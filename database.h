#ifndef DATABASE_H
#define DATABASE_H

#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

struct DBConstructor{
    QString tableName;
    QString tableSQLString;
};

//DBConstructor dbstruct[3];
//dbstruct[0].tableName = "analysis";


static bool connectDB()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/chiteki/Work/Database/Analysis.sqlite");
    db.setUserName("User");
    db.setPassword("1234");
    if(!db.open()){
        QMessageBox::critical(nullptr, QObject::tr("Cannot open database"),
                              QObject::tr("Unable to establish database connection \n"
                                          "This progran need SQLite support."), QMessageBox::Cancel);
        return false;
    }
    return true;
}

bool checkDB()
{
    QStringList dbTableNames;
    dbTableNames << "analysis" << "receipt" << "ingredient";
    dbTableNames.sort();
    int dbTableCount = dbTableNames.count();
    int dbTablesEnable = 0;

    QSqlQuery query;
    // table 'sqlite_master' contains all database information about tables
    // check tables by their names
    query.exec("SELECT name FROM sqlite_master WHERE type='table' ORDER BY name");

    while(query.next()){
        if(dbTableNames.contains(query.value(0).toString())){
            ++dbTablesEnable;
        }
    }
    if(dbTablesEnable == dbTableCount)
        return true;

    // check structure of tables
    return false;
}

void fixDB(){
//    "... fixing DB ...";
    QSqlQuery query;

//    "... droping used tables ...";
    query.exec("DROP TABLE analysis");
    query.exec("DROP TABLE receipt");
    query.exec("DROP TABLE ingredient");

//    "... creating tables ...";
    query.exec("CREATE TABLE analysis("
               "id int,"
               "instance varchar(255),"
               "dishname varchar(255),"
               "date date,"
               "weight float);");

    query.exec("CREATE TABLE receipt("
//               "id int,"
               "analysisid int,"
               "ingredient varchar(255),"
               "weight float,"
               "wastes float,"
               "netto float,"
               "water float,"
               "proteins float,"
               "fats float,"
               "carbons float);");

    query.exec("CREATE TABLE ingredient("
               "id int,"
//               "category int,"
               "name varchar(255),"
               "waist float,"
               "proteins float,"
               "fats float,"
               "carbons float,"
               "energy float);");
//    "... DB recreated ...";
}

void insertExampleDataToDB(){
    QSqlQuery query;
    QStringList analysisExampleData;
    analysisExampleData << "INSERT INTO analysis (id, instance, dishname, date, weight) VALUES (1, 'Табір ЗШ №1 м.Червоноград', 'обід', '2014-06-14', 235);";
    analysisExampleData << "INSERT INTO analysis (id, instance, dishname, date, weight) VALUES (2, 'ДДЗ No 5 м.Соснівка', 'голубці з курячим м`ясом', '2014-06-23', 160);";
    analysisExampleData << "INSERT INTO analysis (id, instance, dishname, date, weight) VALUES (3, 'Савчинська ЗШ', 'ІІ страва', '2014-04-04', 100);";
    analysisExampleData << "INSERT INTO analysis (id, instance, dishname, date, weight) VALUES (4, 'ЗШ с.Муроване', 'обід - макарони, курка, ікра', '2014-04-14', 210);";
    analysisExampleData << "INSERT INTO analysis (id, instance, dishname, date, weight) VALUES (5, 'Опільський НВК', 'перша страва', '2014-04-04', 250);";

//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (1, 1, 'Крупа пшенична Артек', 58);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (2, 1, 'Сіль', 3.75);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (3, 1, 'Курка бройлер 1 кат.', 83);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (4, 1, 'Морква', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (5, 1, 'Цибуля ріпчата', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (6, 1, 'Олія соняшникова', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (7, 1, 'Томатна паста', 2.8);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (8, 1, 'Мука пшенична в.с.', 2);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (9, 1, 'Сіль', 2);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (10, 1, 'Масло Селянське', 5.25);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (11, 1, 'Огірки грунтові', 35);";

//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (12, 2, 'Капуста білокачанна', 150);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (13, 2, 'Курка бройлер 1 кат.', 80);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (14, 2, 'Крупа рисова', 15);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (15, 2, 'Томатна паста', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (16, 2, 'Цибуля ріпчата', 10);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (17, 2, 'Морква', 20);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (18, 2, 'Масло Селянське', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (19, 2, 'Сметана 20%', 10);";

//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (20, 3, 'Мука пшенична 1с.', 13);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (21, 3, 'Цукор', 1);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (22, 3, 'Яйце куряче', 3.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (23, 3, 'Олія соняшникова', 3);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (24, 3, 'Сир нежирний', 9.1);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (25, 3, 'Повидло яблучне', 1);";

//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (26, 4, 'Масло Селянське', 3.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (27, 4, 'Макарон в.с.', 35);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (28, 4, 'Сіль', 1.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (29, 4, 'Курка бройлер 1 кат.', 75);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (30, 4, 'Олія соняшникова', 2);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (31, 4, 'Сметана 20%', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (32, 4, 'Мука пшенична в.с.', 4);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (33, 4, 'Сіль', 1);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (34, 4, 'Масло Селянське', 1.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (35, 4, 'Олія соняшникова', 6);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (36, 4, 'Цукор', 0.8);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (37, 4, 'Цибуля ріпчата', 8);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (38, 4, 'Буряк', 60);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (39, 4, 'Сіль', 0.8);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (40, 4, 'Лимон', 0.01);";

//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (41, 5, 'Масло Селянське', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (42, 5, 'Сметана 20%', 5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (43, 5, 'Горошок консервований', 11.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (44, 5, 'Картопля (01.03-31.06)', 67);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (45, 5, 'Цибуля ріпчата', 12);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (46, 5, 'Морква', 12.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (47, 5, 'Сіль', 1.5);";
//    analysisExampleData << "INSERT INTO receipt (id, analysisid, ingredient, weight) VALUES (48, 5, 'Капуста білокачанна', 25);";


    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (1, 'Буряк', 20, 1.5, 0.1, 9.1, 42);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (2, 'Горошок консервований', 0, 3.1, 0.2, 6.5, 40);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (3, 'Капуста білокачанна', 20, 1.8, 0.1, 4.7, 27);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (4, 'Картопля (01.03-31.06)', 40, 2, 0.4, 16.3, 80);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (5, 'Крупа пшенична Артек', 1, 11, 1.2, 68.3, 335);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (6, 'Крупа рисова', 1, 7, 1, 71.4, 330);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (7, 'Курка бройлер 1 кат.', 52, 19.7, 11.2, 0.5, 183);";
    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons, energy) VALUES (8, 'Лимон', 40, 0.9, 0.1, 3, 33);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (9, 'Макарон в.с.', 0, 10.4, 1.1, 69.7);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (10, 'Масло Селянське', 0, 0.8, 72.2, 1.3);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (11, 'Морква', 20, 1.8, 0.1, 7.2);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (12, 'Мука пшенична 1с.', 0, 10.6, 1.3, 67.6);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (13, 'Мука пшенична в.с.', 0, 10.3, 1.1, 68.9);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (14, 'Огірки грунтові', 7, 0.8, 0.1, 2.6);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (15, 'Олія соняшникова', 0, 0, 99.9, 0);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (16, 'Повидло яблучне', 0, 0.4, 0, 65.3);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (17, 'Сир нежирний', 0, 18, 0.6, 1.8);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (18, 'Сіль', 0, 0, 0, 0);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (19, 'Сметана 20%', 0, 2.8, 20, 3.2);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (20, 'Томатна паста', 0, 4.8, 0, 19);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (21, 'Цибуля ріпчата', 16, 1.4, 0, 9.1);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (22, 'Цукор', 0, 0, 0, 99.8);";
//    analysisExampleData << "INSERT INTO ingredient (id, name, waist, proteins, fats, carbons) VALUES (23, 'Яйце куряче', 13, 12.7, 11.5, 0.7);";

    QStringList::const_iterator i;
    for(i=analysisExampleData.constBegin(); i!=analysisExampleData.constEnd(); ++i){
        query.exec(*i);
    }

}

#endif // DATABASE_H
