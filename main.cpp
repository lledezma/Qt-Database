        // Qt Database Application

#include <QCoreApplication>
#include <QDir>
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString database = "";
    QString dbName = "";
    QString table = "";
    Database db(database, dbName, table, nullptr);

    db.selectAll("");


    return a.exec();
}
