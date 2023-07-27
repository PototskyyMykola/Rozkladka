#ifndef MODELRECEIPT_H
#define MODELRECEIPT_H

#include <QAbstractTableModel>

class ReceiptRecord;
class Analysis;

class ModelReceipt : public QAbstractTableModel
{
public:
    explicit ModelReceipt(QVector<ReceiptRecord> *data, QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void addIngredient(QString ingredName);
private:
    QVector<ReceiptRecord> *mData;
//    void loadFromDB(int id);
};

#endif // MODELRECEIPT_H
