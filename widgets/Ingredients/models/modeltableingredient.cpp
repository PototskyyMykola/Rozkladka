#include "modeltableingredient.h"
#include "../ingredient.h"

ModelTableIngredient::ModelTableIngredient(QObject *parent)
    : QAbstractTableModel{parent}
{
//    mData = new QVector<Ingredient>;
}

ModelTableIngredient::ModelTableIngredient(QObject *parent, QVector<Ingredient> *data)
    :QAbstractTableModel{parent}
{
    setModelData(data);
}

int ModelTableIngredient::rowCount(const QModelIndex &/*parent*/) const
{
    return mData->count();
}

int ModelTableIngredient::columnCount(const QModelIndex &/*parent*/) const
{
    return 6;
}

QVariant ModelTableIngredient::data(const QModelIndex &index, int role) const
{
    QVector<Ingredient>::Iterator i = mData->begin();
    if(role == Qt::DisplayRole){
        QString answer = "";
        i += index.row();
        int col = index.column();
        switch (col){
        case 0: answer = i->getName(); break;
        case 1: answer = QString().number(i->getWaist()); break;
        case 2: answer = QString().number(i->getProteins()); break;
        case 3: answer = QString().number(i->getFats()); break;
        case 4: answer = QString().number(i->getCarbons()); break;
        case 5: answer = QString().number(i->getEnergy()); break;

        default:  break;
        }
        return answer;
    }
    return QVariant();
}

QVariant ModelTableIngredient::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0: return QString(tr("Name")); break;
        case 1: return QString(tr("Waist")); break;
        case 2: return QString(tr("Proteins")); break;
        case 3: return QString(tr("Fats")); break;
        case 4: return QString(tr("Carbons")); break;
        case 5: return QString(tr("Energy")); break;

        default: break;
        }
    }
    return QVariant();
}

bool ModelTableIngredient::insertRows(int /*row*/, int /*count*/, const QModelIndex &/*parent*/)
{
    beginResetModel();
    endResetModel();
    return true;
}

//void ModelTableIngredient::refreshModelData()
//{
//    beginResetModel();
//    endResetModel();
//}

