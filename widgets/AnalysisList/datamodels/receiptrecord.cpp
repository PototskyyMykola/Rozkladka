#include "receiptrecord.h"

ReceiptRecord::ReceiptRecord()
{

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
