#ifndef DIALOGANALYSISEDIT_H
#define DIALOGANALYSISEDIT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLineEdit;
class QDateEdit;
QT_END_NAMESPACE

class Analysis;

class DialogAnalysisEdit : public QDialog
{
    Q_OBJECT
public:
    DialogAnalysisEdit(Analysis*);
private:
    void createUI();
    void fillForm();
    void readForm();

    Analysis *currentAnalysis;

    QPushButton *btnOk;
    QPushButton *btnCancel;

    QLineEdit *leInstanceName;
    QLineEdit *leDishName;
    QDateEdit *deDate;
    QLineEdit *leWeight;

private slots:
    void onAccepted();
};

#endif // DIALOGANALYSISEDIT_H
