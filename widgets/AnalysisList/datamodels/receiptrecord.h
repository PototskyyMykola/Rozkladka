#ifndef RECEIPT_H
#define RECEIPT_H

#include <QString>

class ReceiptRecord
{
public:
    ReceiptRecord();
    ReceiptRecord(QString, float);
    QString getIngredientName() const;
    void setIngredientName(const QString &newIngredientName);

    float getIngredientWeight() const;
    void setIngredientWeight(float newIngredientWeight);

    float getWastes() const;
    float getNetto() const;
    float getWater() const;
    float getProteins() const;
    float getFats() const;
    float getCarbons() const;

private:
    QString ingredientName;
    float   ingredientWeight;

    float wastes;
    float netto;
    float water;
    float proteins;
    float fats;
    float carbons;
};

#endif // RECEIPT_H
