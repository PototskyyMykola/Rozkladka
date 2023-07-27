#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

#include "analysis.h"
#include "receiptrecord.h"

Analysis::Analysis()
{
    clear();
//    receipt = new QVector<ReceiptRecord>;
//    receipt->append(ReceiptRecord("Test", 100));
}

void Analysis::clear()
{
    setID(0);
    setDate(QDate::currentDate());
    setIstance("");
    setDishName("");
    setWeight(0.0);
}

void Analysis::getReceiptFromDB()
{
    qDebug() << "Analysis - clear receipt Vector";
    receipt.clear();
    qDebug() << "Analysis -> getreceiptFromDB";
    QSqlQuery query;
    qDebug() << "modelreceipt prepare query";
    query.prepare("SELECT ingredient, weight FROM receipt WHERE analysisid=:id;");
    query.bindValue(":id", mID);
    query.exec();
    qDebug() << "modelreceipt executed query";
    while(query.next()){
//        ReceiptRecord *record = new ReceiptRecord;
//        record->setIngredientName(query.value(0).toString());
//        record->setIngredientWeight(query.value(1).toFloat());
        QString ingName = query.value(0).toString();
        float ingweight = query.value(1).toFloat();
        qDebug() << "value 1:" << ingName <<
            "value 2:" << QString().number(ingweight);
        qDebug() << "record readed";
        receipt.append(ReceiptRecord(ingName, ingweight));
        qDebug() << "record not appended";
    }
    qDebug() << "receipt loaded it has " << receipt.count() << " records";
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
