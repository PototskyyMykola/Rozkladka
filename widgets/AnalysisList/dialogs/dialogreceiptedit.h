#ifndef DIALOGRECEIPTEDIT_H
#define DIALOGRECEIPTEDIT_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QTableView;
class QPushButton;
class QAbstractTableModel;
QT_END_NAMESPACE

class Analysis;
class ModelIngredientList;
class ModelReceipt;

class DialogReceiptEdit : public QDialog
{
public:
    DialogReceiptEdit(Analysis *);
private:
    void createUI();
    void createModels();

    QTableView *tvIngredients;
    QTableView *tvReceipt;

    QPushButton *btnAddIngredient;
    QPushButton *btnRemoveIngredient;
    QPushButton *btnCalculate;
    QPushButton *btnCancel;

    Analysis *currentAnalysis;

    QAbstractTableModel *modelIngredientList;
    ModelReceipt *modelReceipt;
private slots:
    void onAccepted();
    void btnAddIngredientClicked();
    void btnRemoveIngredientClicked();
    void btnCalculateClicked();
};

#endif // DIALOGRECEIPTEDIT_H
