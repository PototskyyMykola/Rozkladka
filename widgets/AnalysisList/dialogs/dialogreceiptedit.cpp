#include <QtWidgets>

#include "dialogreceiptedit.h"
#include "../datamodels/analysis.h"
#include "../viewmodels/modelingredientlist.h"
#include "../viewmodels/modelreceipt.h"

DialogReceiptEdit::DialogReceiptEdit(Analysis *analysis)
{
    currentAnalysis = analysis;
    createModels();
    createUI();
}

void DialogReceiptEdit::createUI()
{
    QHBoxLayout *widgetLayout = new QHBoxLayout;
    setLayout(widgetLayout);

    tvIngredients = new QTableView;
    tvIngredients->setModel(modelIngredientList);

    tvReceipt = new QTableView;
    tvReceipt->setModel(modelReceipt);

    btnAddIngredient = new QPushButton(tr("Add"));
    btnRemoveIngredient = new QPushButton(tr("Remove"));
    btnCalculate = new QPushButton(tr("Calculate"));
    btnCancel = new QPushButton(tr("Cancel"));

    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(btnAddIngredient);
    buttonsLayout->addWidget(btnRemoveIngredient);
    buttonsLayout->addWidget(btnCalculate);
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(btnCancel);

    widgetLayout->addWidget(tvIngredients);
    widgetLayout->addWidget(tvReceipt);
    widgetLayout->addLayout(buttonsLayout);
}

void DialogReceiptEdit::createModels()
{
    modelIngredientList = new ModelIngredientList;
    modelReceipt = new ModelReceipt;
}
