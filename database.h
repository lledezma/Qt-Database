#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class Database: public QObject
{
    Q_OBJECT

    public:
        explicit Database(QString database, QString dbName, QString table, QObject *parent = nullptr);
        ~Database();
        void selectAll();
        void dropRecord(QString column, QString value);
        void addRecord(QStringList values);

    private:
        QSqlDatabase db;
        QSqlRecord row;
        QString table;
};

#endif // DATABASE_H



