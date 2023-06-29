#include "modelanalysislist.h"
#include "../datamodels/analysis.h"

ModelAnalysisList::ModelAnalysisList(QObject *parent)
    : QAbstractTableModel{parent}
{
    mData = new QVector<Analysis>;
}

int ModelAnalysisList::rowCount(const QModelIndex &/*parent*/) const
{
    return mData->count();
}

int ModelAnalysisList::columnCount(const QModelIndex &/*parent*/) const
{
    return 4;
}

QVariant ModelAnalysisList::data(const QModelIndex &index, int role) const
{
    QVector<Analysis>::Iterator i = mData->begin();
    if(role == Qt::DisplayRole){
        QString answer = "";
        i += index.row();
        int col = index.column();
        switch (col){
        case 0: answer = i->getIstance(); break;
        case 1: answer = i->getDishName(); break;
        case 2: answer = i->getDate().toString(); break;
        case 3: answer = QString().number(i->getWeignt()); break;
        default:  break;
        }
        return answer;
    }
    return QVariant();
}

QVariant ModelAnalysisList::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0: return QString(tr("Instance")); break;
        case 1: return QString(tr("Dish name")); break;
        case 2: return QString(tr("Date")); break;
        case 3: return QString(tr("Weight")); break;
        default: break;
        }
    }
    return QVariant();
}
