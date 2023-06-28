#include <QtWidgets>

#include "dialoganalysisedit.h"
#include "../analysis.h"

DialogAnalysisEdit::DialogAnalysisEdit(Analysis *analysis)
{
    currentAnalysis = analysis;
    createUI();
    fillForm();
}

void DialogAnalysisEdit::createUI()
{
    btnOk = new QPushButton(tr("Ok"));
    connect(btnOk, &QPushButton::clicked, this, &DialogAnalysisEdit::onAccepted);

    btnCancel = new QPushButton(tr("Cancel"));
    connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);

    QLabel *lblInstanceName = new QLabel(tr("Instance:"));
    QLabel *lblDishName = new QLabel(tr("Dish name:"));
    QLabel *lblDate = new QLabel(tr("Date:"));
    QLabel *lblWeight = new QLabel(tr("Weight:"));

    leInstanceName = new QLineEdit;
    leDishName = new QLineEdit;
    deDate = new QDateEdit;

    leWeight = new QLineEdit;
    QDoubleValidator *vWeight = new QDoubleValidator(0, 99999, 2);
    leWeight->setValidator(vWeight);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(lblInstanceName, leInstanceName);
    formLayout->addRow(lblDishName, leDishName);
    formLayout->addRow(lblDate, deDate);
    formLayout->addRow(lblWeight, leWeight);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(btnOk);
    buttonsLayout->addWidget(btnCancel);

    QVBoxLayout *widgetLayout = new QVBoxLayout;
    setLayout(widgetLayout);
    widgetLayout->addLayout(formLayout);
    widgetLayout->addLayout(buttonsLayout);

    setWindowTitle(tr("Analysis edit"));

}

void DialogAnalysisEdit::fillForm()
{
    leInstanceName->setText(currentAnalysis->getIstance());
    leDishName->setText(currentAnalysis->getDishName());
    deDate->setDate(currentAnalysis->getDate());
    leWeight->setText(QString().number(currentAnalysis->getWeignt()));
}

void DialogAnalysisEdit::readForm()
{
    currentAnalysis->setIstance(leInstanceName->text());
    currentAnalysis->setDishName(leDishName->text());
    currentAnalysis->setDate(deDate->date());
    currentAnalysis->setWeight(leWeight->text().toFloat());
}

void DialogAnalysisEdit::onAccepted()
{
    readForm();
    emit DialogAnalysisEdit::accept();
}
