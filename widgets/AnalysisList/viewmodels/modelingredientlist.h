#ifndef MODELINGREDIENTLIST_H
#define MODELINGREDIENTLIST_H

#include <QAbstractTableModel>

class ModelIngredientList : public QAbstractTableModel
{
public:
    explicit ModelIngredientList(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QStringList *mData;
};

#endif // MODELINGREDIENTLIST_H
