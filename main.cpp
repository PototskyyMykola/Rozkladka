#include "mainwindow.h"
#include "database.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // connect to DB
    if(!connectDB()){
        //        qDebug() << "- connect to DB...";
        return EXIT_FAILURE;
    }
    if(!checkDB()){
        //            splash->showMessage("Fixing database...", splashAlignment, Qt::black);
        //        qDebug() << "-- fixing database...";
        fixDB();
        //        qDebug() << "-- insert template data...";
        insertExampleDataToDB();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
