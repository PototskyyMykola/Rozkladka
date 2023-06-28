#ifndef MODELTABLEINGREDIENT_H
#define MODELTABLEINGREDIENT_H

#include <QAbstractTableModel>

class Ingredient;

class ModelTableIngredient : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelTableIngredient(QObject *parent = nullptr);
    ModelTableIngredient(QObject *parent, QVector<Ingredient>*);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

//    void refreshModelData();
    void setModelData(QVector<Ingredient> *data){mData = data;}
private:
    QVector<Ingredient> *mData;

    // QAbstractItemModel interface
public:
    bool insertRows(int row, int count, const QModelIndex &parent) override;
};

#endif // MODELTABLEINGREDIENT_H
