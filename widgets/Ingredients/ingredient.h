#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <QString>

class Ingredient
{
public:
    Ingredient();

    void clear();
    // setters
    void setID(int i)         {mId = i;}
    void setName(QString s)   {mName = s;}
    void setWaist(float f)    {mWaist = f;}
    void setProteins(float f) {mProteins = f;}
    void setFats(float f)     {mFats = f;}
    void setCarbons(float f)  {mCarbons = f;}
    void setEnergy(float f)   {mEnergy = f;}
    // getters
    int     getID()      {return mId;}
    QString getName()    {return mName;}
    float   getWaist()   {return mWaist;}
    float   getProteins(){return mProteins;}
    float   getFats()    {return mFats;}
    float   getCarbons() {return mCarbons;}
    float   getEnergy()  {return mEnergy;}
    //    float get(){return m;}
private:
    int mId;
    QString mName;
    float mWaist;
    float mProteins;
    float mFats;
    float mCarbons;
    float mEnergy;
};

#endif // INGREDIENT_H
