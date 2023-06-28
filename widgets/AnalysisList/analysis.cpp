#include "analysis.h"

Analysis::Analysis()
{
    clear();
}

void Analysis::clear()
{
    setID(0);
    setDate(QDate::currentDate());
    setIstance("");
    setDishName("");
    setWeight(0.0);
}

void Analysis::setDate(QString date)
{
    // dd-mm-yyyy
    //needed test for cheking input data
    QStringList slDate = date.split(QLatin1Char('-'));
    int d = slDate[0].toInt();
    int m = slDate[1].toInt();
    int y = slDate[2].toInt();
    mDate = QDate(y, m, d);
}

void Analysis::setDate(const QDate date)
{
    mDate = date;
}
