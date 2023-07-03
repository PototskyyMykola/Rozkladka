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
    tvIngredients->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

    tvReceipt = new QTableView;
    tvReceipt->setModel(modelReceipt);
    tvReceipt->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

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
    qDebug() << "created ingredient list model";
    modelReceipt = new ModelReceipt(currentAnalysis->getID());
    qDebug() << "created receipt model with ID=" << currentAnalysis->getID();
}
