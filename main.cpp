        // Qt Database Application

#include <QCoreApplication>
#include <QDir>
#include "database.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString database = "";
    QString dbName = "";
    Database db(database, dbName, nullptr);
    db.selectAll("");


    return a.exec();
}
