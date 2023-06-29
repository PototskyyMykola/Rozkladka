#include "modelingredientlist.h"

ModelIngredientList::ModelIngredientList(QObject *parent)
    : QAbstractTableModel{parent}
{
    mData = new QStringList;
}

int ModelIngredientList::rowCount(const QModelIndex &/*parent*/) const
{
    return mData->size();
}

int ModelIngredientList::columnCount(const QModelIndex &/*parent*/) const
{
    return 1;
}

QVariant ModelIngredientList::data(const QModelIndex &index, int role) const
{
    QStringList::iterator iterator = mData->begin();
    iterator += index.row();
    if(role == Qt::DisplayRole){
        return iterator->toLower();
    }
    return QVariant();
}

QVariant ModelIngredientList::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        switch (section) {
        case 0: return QString(tr("Ingredient name")); break;
        default: break;
        }
    }
    return QVariant();

}
