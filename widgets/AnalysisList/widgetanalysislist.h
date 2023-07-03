#ifndef WIDGETANALYSISLIST_H
#define WIDGETANALYSISLIST_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTableView;
class QPushButton;
class QAbstractTableModel;
class QDialog;
QT_END_NAMESPACE

class Analysis;

class WidgetAnalysisList : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetAnalysisList(QWidget *parent = nullptr);
    void analysisNew();
    void analysisEdit();
    void analysisRemove();
    void analysisView();
    void analysisPrint();

private:
    void createUI();
    void createModel();
    void loadFromDB();
    Analysis *getSelectedAnalysis();

    Analysis *currentAnalysis;

    QTableView *tv;
    QAbstractTableModel *modelTableAnalysis;

    QPushButton *btnAnalysisNew;
    QPushButton *btnAnalysisEdit;
    QPushButton *btnAnalysisRemove;
    QPushButton *btnAnalysisView;
    QPushButton *btnAnalysisPrint;

    QDialog *dialogEdit;
    QDialog *dialogPrint;
    QDialog *receiptEdit;

    int maxId;
    QVector<Analysis> *mData;

private slots:
    void slotAanalysisNew();
    void slotAnalysisEdit();
    void slotAnalysisRemove();
    void slotAnalysisView();
    void slotAnalysisPrint();
signals:

};

#endif // WIDGETANALYSISLIST_H
