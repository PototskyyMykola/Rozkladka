#ifndef MODELRECEIPT_H
#define MODELRECEIPT_H

#include <QAbstractTableModel>

class ReceiptRecord;

class ModelReceipt : public QAbstractTableModel
{
public:
    explicit ModelReceipt(QObject *parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QVector<ReceiptRecord> *mData;
};

#endif // MODELRECEIPT_H
