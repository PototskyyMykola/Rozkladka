#include <QtWidgets>

#include "dialogingredientedit.h"
#include "../datamodels/ingredient.h"

DialogIngredientEdit::DialogIngredientEdit(Ingredient * ingredient)
{
    currentIngredient = ingredient;
    createUI();
    fillUI();
}

void DialogIngredientEdit::createUI()
{
    QVBoxLayout *widgetLayout = new QVBoxLayout;
    setLayout(widgetLayout);

    QFormLayout *formLayout = new QFormLayout;
    widgetLayout->addLayout(formLayout);

    QHBoxLayout *buttonsLayout = new QHBoxLayout;
    widgetLayout->addLayout(buttonsLayout);

    leName = new QLineEdit;
    leWaist = new QLineEdit;
    leProteins = new QLineEdit;
    leFats = new QLineEdit;
    leCarbons = new QLineEdit;
    leEnergy = new QLineEdit;

    QLabel *lblName = new QLabel(tr("Ingredient Name:"));
    QLabel *lblWaist = new QLabel(tr("Waist:"));
    QLabel *lblProteins = new QLabel(tr("Proteins:"));
    QLabel *lblFats = new QLabel(tr("Fats:"));
    QLabel *lblCarbons = new QLabel(tr("Carbons"));
    QLabel *lblEnergy = new QLabel(tr("Energy"));

    formLayout->addRow(lblName, leName);
    formLayout->addRow(lblWaist, leWaist);
    formLayout->addRow(lblProteins, leProteins);
    formLayout->addRow(lblFats, leFats);
    formLayout->addRow(lblCarbons, leCarbons);
    formLayout->addRow(lblEnergy, leEnergy);

    btnOk = new QPushButton(tr("Ok"));
    connect(btnOk, &QPushButton::clicked, this, &DialogIngredientEdit::onAccept);

    btnCancel = new QPushButton(tr("Cancel"));
    connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);

    buttonsLayout->addWidget(btnOk);
    buttonsLayout->addWidget(btnCancel);

    setWindowTitle(tr("Editing Ingredient"));
}

void DialogIngredientEdit::fillUI()
{
    leName->setText(currentIngredient->getName());
    leWaist->setText(QString().number(currentIngredient->getWaist()));
    leProteins->setText(QString().number(currentIngredient->getProteins()));
    leFats->setText(QString().number(currentIngredient->getFats()));
    leCarbons->setText(QString().number(currentIngredient->getCarbons()));
    leEnergy->setText(QString().number(currentIngredient->getEnergy()));
}

void DialogIngredientEdit::onAccept()
{
    currentIngredient->setName(leName->text());
    currentIngredient->setWaist(leWaist->text().toFloat());
    currentIngredient->setProteins(leProteins->text().toFloat());
    currentIngredient->setFats(leFats->text().toFloat());
    currentIngredient->setCarbons(leCarbons->text().toFloat());
    currentIngredient->setEnergy(leEnergy->text().toFloat());
    emit DialogIngredientEdit::accept();
}
