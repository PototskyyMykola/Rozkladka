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
    void analysisPrint();

private:
    void createUI();
    void createModel();

    Analysis *currentAnalysis;

    QTableView *tv;
    QAbstractTableModel *modelTableAnalysis;

    QPushButton *btnAnalysisNew;
    QPushButton *btnAnalysisEdit;
    QPushButton *btnAnalysisRemove;
    QPushButton *btnAnalysisPrint;

    QDialog *dialogEdit;
    QDialog *dialogPrint;
    QDialog *receiptEdit;

    int maxId;

private slots:
    void slotNewAanalysis();
signals:

};

#endif // WIDGETANALYSISLIST_H
