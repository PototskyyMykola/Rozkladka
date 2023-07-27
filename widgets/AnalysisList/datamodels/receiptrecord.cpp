#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>

#include "receiptrecord.h"

ReceiptRecord::ReceiptRecord()
{

}

ReceiptRecord::ReceiptRecord(QString ingredientName, float weight)
{
    setIngredientName(ingredientName);
    setIngredientWeight(weight);
}

QString ReceiptRecord::getIngredientName() const
{
    return ingredientName;
}

void ReceiptRecord::setIngredientName(const QString &newIngredientName)
{
    ingredientName = newIngredientName;
}

float ReceiptRecord::getIngredientWeight() const
{
    return ingredientWeight;
}

void ReceiptRecord::setIngredientWeight(float newIngredientWeight)
{
    ingredientWeight = newIngredientWeight;
}

float ReceiptRecord::getWastes() const
{
    return wastes;
}

float ReceiptRecord::getNetto() const
{
    return netto;
}

float ReceiptRecord::getWater() const
{
    return water;
}

float ReceiptRecord::getProteins() const
{
    return proteins;
}

float ReceiptRecord::getFats() const
{
    return fats;
}

float ReceiptRecord::getCarbons() const
{
    return carbons;
}

void ReceiptRecord::calculate()
{
    getdatafromDB();
    wastes *= ingredientWeight;
    netto = ingredientWeight - wastes;
    water *= ingredientWeight;
    proteins *= ingredientWeight;
    fats *= ingredientWeight;
    carbons *= ingredientWeight;
}

void ReceiptRecord::getdatafromDB()
{
    QSqlQuery query;
    query.prepare("SELECT wastes, water, proteins, fats, carbons FROM ingredient WHERE name=:ingname;");
    query.bindValue(":ingname", ingredientName);
    query.exec();
    while (query.next()) {
        wastes = query.value(0).toFloat();
        water = query.value(1).toFloat();
        proteins = query.value(2).toFloat();
        fats = query.value(3).toFloat();
        carbons = query.value(4).toFloat();
    }
}

QString ReceiptRecord::generateSQLInsert()
{
    QString result;
    result="INSERT INTO receipt (analysisid, ingredient, weight, wastes, netto, water, proteins, fats, carbons) VALUES (" +
             QString().number(analysisId) + ", " +
             ingredientName + ", " +
             QString().number(ingredientWeight) + ", " +
             QString().number(wastes) + ", " +
             QString().number(netto) + ", " +
             QString().number(water) + ", " +
             QString().number(proteins) + ", " +
             QString().number(fats) + ", " +
             QString().number(carbons) + ");";
    return result;
}

//int ReceiptRecord::getId() const
//{
//    return id;
//}

//void ReceiptRecord::setId(int newId)
//{
//    id = newId;
//}

int ReceiptRecord::getAnalysisId() const
{
    return analysisId;
}

void ReceiptRecord::setAnalysisId(int newAnalysisId)
{
    analysisId = newAnalysisId;
}
