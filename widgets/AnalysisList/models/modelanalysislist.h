#ifndef MODELANALYSISLIST_H
#define MODELANALYSISLIST_H

#include <QAbstractTableModel>

class Analysis;

class ModelAnalysisList : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit ModelAnalysisList(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QVector<Analysis> *mData;
};

#endif // MODELANALYSISLIST_H
