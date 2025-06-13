#include "database.h"


Database::Database(QString database, QString dbName, QString table, QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase(database);
    db.setDatabaseName(dbName);

    // Open the database
    if (!db.open()) {
        qDebug() << "Error: Failed to connect to database.";
        return;
    } else {
        qDebug() << "Database connection successful!";
    }
}

Database::~Database()
{
    qInfo() << "Closing database...";
    db.close();
}

void Database::selectAll(QString table)
{
    QString cmd = "SELECT * FROM " + table;
    QSqlQuery query(cmd);
    bool ok = query.exec();

    if(!ok){
        qDebug() << "Query " + query.executedQuery() + "not executed";
        return;
    }

    while(query.next())
    {
        row = query.record();
        for(int i = 0; i < row.count(); i++){
            qInfo() << row.value(i).toString();
        }
        qInfo() << "\n\n";
    }

}

