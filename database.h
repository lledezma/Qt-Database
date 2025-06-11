#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

class Database: public QObject
{
    Q_OBJECT
public:
    explicit Database(QString database, QString dbName, QObject *parent = nullptr);
    ~Database();
    void selectAll(QString table);

private:
    QSqlDatabase db;
    QSqlRecord row;

};

#endif // DATABASE_H



