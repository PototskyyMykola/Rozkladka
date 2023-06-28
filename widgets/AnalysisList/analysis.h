#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <QDate>

class Analysis
{
public:
    Analysis();

    void clear();

    void setID(int id)              {mID = id;}
    void setIstance(QString inst)   {mInstance = inst;}
    void setDishName(QString dish)  {mDishName = dish;}
    void setDate(const QString date);
    void setDate(const QDate);
    void setWeight(float weight)    {mWeight = weight;}

    int getID()             const {return mID;}
    QString getIstance()    const {return mInstance;}
    QString getDishName()   const {return mDishName;}
    QDate getDate()         const {return mDate;}
    float getWeignt()       const {return mWeight;}

private:
    int     mID;
    QString mInstance;
    QString mDishName;
    QDate   mDate;
    float   mWeight;
    // add "Netto", "Proteins", "Fats" and others
};
#endif // ANALYSIS_H
