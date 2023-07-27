#include <QtWidgets>

#include "dialogreceiptedit.h"
#include "../datamodels/analysis.h"
#include "../viewmodels/modelingredientlist.h"
#include "../viewmodels/modelreceipt.h"

DialogReceiptEdit::DialogReceiptEdit(Analysis *analysis)
{
    qDebug() << "Dialog ReceiptEdit - constructor";
    currentAnalysis = analysis;
    qDebug() << "Dialog ReceiptEdit - constructor - analysis defined";
    createModels();
    qDebug() << "Dialog ReceiptEdit - constructor - models created";
    createUI();
    qDebug() << "Dialog ReceiptEdit - constructor - UI created";
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
    connect(btnAddIngredient, &QPushButton::clicked, this, &DialogReceiptEdit::btnAddIngredientClicked);

    btnRemoveIngredient = new QPushButton(tr("Remove"));
    connect(btnRemoveIngredient, &QPushButton::clicked, this, &DialogReceiptEdit::btnRemoveIngredientClicked);

    btnCalculate = new QPushButton(tr("Calculate"));
    connect(btnCalculate, &QPushButton::clicked, this, &DialogReceiptEdit::btnCalculateClicked);

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
    qDebug() << "Dialog ReceiptEdit - created ingredient list model";
    modelReceipt = new ModelReceipt(currentAnalysis->getReceipt());
    qDebug() << "Dialog ReceiptEdit - created receipt model with ID=" << currentAnalysis->getID();
}

void DialogReceiptEdit::btnAddIngredientClicked()
{
    // get ingredient name from tvIngredients and add it to receipt model
    modelReceipt->addIngredient(tvIngredients->currentIndex().data().toString());

}

void DialogReceiptEdit::btnRemoveIngredientClicked()
{
    // remve selected record in receipt model
}

void DialogReceiptEdit::btnCalculateClicked()
{
    // calculate dependent rows in receipt model

}
