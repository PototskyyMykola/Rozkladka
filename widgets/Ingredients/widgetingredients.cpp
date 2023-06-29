#include <QtWidgets>
#include <QSqlQuery>
#include <QSqlError>

#include "widgetingredients.h"
#include "dialogs/dialogingredientedit.h"
#include "viewmodels/modeltableingredient.h"
#include "datamodels/ingredient.h"

WidgetIngredients::WidgetIngredients(QWidget *parent)
    : QWidget{parent}
{
    maxID = 0;
    mData = new QVector<Ingredient>;

    createModel();
    loadFromDB();
    createUI();

    currentIngredient = new Ingredient;
}

void WidgetIngredients::createUI()
{
    QHBoxLayout *widgetLayout = new QHBoxLayout;
    setLayout(widgetLayout);

    tv = new QTableView;
    tv->setModel(modelTableIngredient);
    tv->setSelectionBehavior(QAbstractItemView::SelectRows);  // set selection to row
    tv->setSelectionMode(QAbstractItemView::SingleSelection); // set selection to only 1 row
    tv->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    tv->selectRow(0);
    widgetLayout->addWidget(tv);

    btnIngredientNew = new QPushButton(tr("New Ingredient"));
    connect(btnIngredientNew, &QPushButton::clicked, this, &WidgetIngredients::slotAddIngredient);

    btnIngredientEdit = new QPushButton(tr("Edit Ingredient"));
    connect(btnIngredientEdit, &QPushButton::clicked, this, &WidgetIngredients::slotEditIngredient);

    btnIngredientRemove = new QPushButton(tr("Remove Ingredient"));
    connect(btnIngredientRemove, &QPushButton::clicked, this, &WidgetIngredients::slotRemoveIngredient);

    QVBoxLayout *buttonsLayout = new QVBoxLayout;
    buttonsLayout->addWidget(btnIngredientNew);
    buttonsLayout->addWidget(btnIngredientEdit);
    buttonsLayout->addWidget(btnIngredientRemove);
    buttonsLayout->addStretch();

    widgetLayout->addLayout(buttonsLayout);
    setGeometry(QRect(100, 100, 940, 480));
}

void WidgetIngredients::createModel()
{
    modelTableIngredient = new ModelTableIngredient(this, mData);
}

void WidgetIngredients::loadFromDB()
{
    // fill data from DB
    QSqlQuery query;
    query.prepare("SELECT * FROM ingredient");
    query.exec();
    while(query.next()){
        Ingredient ingredient;

        int id = query.value(0).toInt();
        if(id > maxID) maxID = id;

        ingredient.setID(id);
        ingredient.setName(query.value(1).toString());
        ingredient.setWaist(query.value(2).toFloat());
        ingredient.setProteins(query.value(3).toFloat());
        ingredient.setFats(query.value(4).toFloat());
        ingredient.setCarbons(query.value(5).toFloat());
        ingredient.setEnergy(query.value(6).toFloat());
        mData->append(ingredient);
    }

    //    qDebug() << maxID;
}

void WidgetIngredients::addIngredient()
{
    QSqlQuery query;
    query.prepare("INSERT INTO ingredient ( id,  name,  waist,  proteins,  fats,  carbons,  energy)"
                  " VALUES (:id, :name, :waist, :proteins, :fats, :carbons, :energy);");
    query.bindValue(":id", currentIngredient->getID());
    query.bindValue(":name", currentIngredient->getName());
    query.bindValue(":waist", currentIngredient->getWaist());
    query.bindValue(":proteins", currentIngredient->getProteins());
    query.bindValue(":fats", currentIngredient->getFats());
    query.bindValue(":carbons", currentIngredient->getCarbons());
    query.bindValue(":energy", currentIngredient->getEnergy());
    query.exec();
//    qDebug() << "query result when adding ing: " << query.lastError();

    Ingredient *ingredient = new Ingredient;
    ingredient->setID(currentIngredient->getID());
    ingredient->setName(currentIngredient->getName());
    ingredient->setWaist(currentIngredient->getWaist());
    ingredient->setProteins(currentIngredient->getProteins());
    ingredient->setFats(currentIngredient->getFats());
    ingredient->setCarbons(currentIngredient->getCarbons());
    ingredient->setEnergy(currentIngredient->getEnergy());

    currentIngredient->clear();

    mData->append(*ingredient);
    delete modelTableIngredient;
    createModel();
    tv->setModel(modelTableIngredient);
}

void WidgetIngredients::updateIngredient()
{
    QSqlQuery query;
    query.prepare("UPDATE ingredient "
                  "SET name = :name, waist = :waist, proteins = :proteins, fats = :fats, carbons = :carbons, energy = :energy "
                  "WHERE id = :id");
    query.bindValue(":id", currentIngredient->getID());
    query.bindValue(":name", currentIngredient->getName());
    query.bindValue(":waist", currentIngredient->getWaist());
    query.bindValue(":proteins", currentIngredient->getProteins());
    query.bindValue(":fats", currentIngredient->getFats());
    query.bindValue(":carbons", currentIngredient->getCarbons());
    query.bindValue(":energy", currentIngredient->getEnergy());
//    qDebug() << query.lastQuery();
    query.exec();
//    qDebug() << "query result when updating ing: " << query.lastError();

    mData->clear(); // clear current data model
    loadFromDB();   // load updated from DB
    createModel();  // recreate model
    tv->setModel(modelTableIngredient);  // reconect model to TableView
}

void WidgetIngredients::removeIngredient(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ingredient WHERE id=:id");
    query.bindValue(":id", id);
    query.exec();
//    qDebug() << "query result when removing ing: " << query.lastError();

    mData->clear(); // clear current data model
    loadFromDB();   // load updated from DB
    createModel();  // recreate model
    tv->setModel(modelTableIngredient);  // reconect model to TableView
}

Ingredient *WidgetIngredients::getSelectedItem()
{
    // get selected item
    // return mData element
    const QModelIndex index = tv->selectionModel()->currentIndex();
    int selectedRow = index.row();

    QVector<Ingredient>::Iterator i = mData->begin();
    i += selectedRow;

    return i;
}

void WidgetIngredients::slotAddIngredient()
{
    currentIngredient->clear();
    currentIngredient->setID(++maxID);

    DialogIngredientEdit dialogNew(currentIngredient);
    if(dialogNew.exec()){
        addIngredient();
    }
}

void WidgetIngredients::slotEditIngredient()
{
    currentIngredient = getSelectedItem();
    DialogIngredientEdit dialogEdit(currentIngredient);
    if(dialogEdit.exec()){
        updateIngredient();
    };
}

void WidgetIngredients::slotRemoveIngredient()
{
    currentIngredient = getSelectedItem();
    removeIngredient(currentIngredient->getID());
}
