#include <QSqlQuery>
#include <QDebug>

#include "modelreceipt.h"
#include "../datamodels/receiptrecord.h"

ModelReceipt::ModelReceipt(int analysisId, QObject *parent)
    : QAbstractTableModel{parent}
{
    mData = new QVector<ReceiptRecord>;
    if(analysisId != 0){
        loadFromDB(analysisId);
    }
}

int ModelReceipt::rowCount(const QModelIndex &/*parent*/) const
{
    return mData->count();
}

int ModelReceipt::columnCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

QVariant ModelReceipt::data(const QModelIndex &index, int role) const
{
    QVector<ReceiptRecord>::Iterator i = mData->begin();
    if(role == Qt::DisplayRole){
        int row {index.row()};
        i += row;
        switch (index.column()) {
        case 0:
            return i->getIngredientName(); break;
        case 1:
            return QString().number(i->getIngredientWeight()); break;
        default:
            break;
        }
    }
    return QVariant();
}

QVariant ModelReceipt::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0: return QString(tr("Ingredient name")); break;
        case 1: return QString(tr("Weight")); break;
        default: break;
        }
    }
    return QVariant();
}

void ModelReceipt::loadFromDB(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ingredient, weight FROM receipt WHERE analysisid=:id;");
    query.bindValue(":id", id);
    query.exec();
    while(query.next()){
        ReceiptRecord record;
        record.setIngredientName(query.value(0).toString());
        record.setIngredientWeight(query.value(1).toFloat());
        mData->append(record);
    }
    qDebug() << "query prepared string: " << query.executedQuery();
    qDebug() << "model receipt - loaded record count=" << mData->size();
}
