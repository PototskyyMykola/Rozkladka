#ifndef DIALOGRECEIPTEDIT_H
#define DIALOGRECEIPTEDIT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QTableView;
class QPushButton;
QT_END_NAMESPACE

class Analysis;

class DialogReceiptEdit : public QDialog
{
public:
    DialogReceiptEdit(Analysis *);
private:
    void createUI();

    QTableView *tvIngredients;
    QTableView *tvReceipt;

    QPushButton *btnAddIngredient;
    QPushButton *btnRemoveIngredient;
    QPushButton *btnCalculate;
    QPushButton *btnCancel;

    Analysis *currentAnalysis;
};

#endif // DIALOGRECEIPTEDIT_H
