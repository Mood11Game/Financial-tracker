#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

class DBManager
{
public:
    DBManager(const QString& dataBaseName, const QString& nameUser, const QString& psswd, const QString nameTableUser);
    ~DBManager();


private:
    bool createConnected(const QString& dataBaseName, const QString& nameUser, const QString& psswd);

    bool createTableUser(const QString& nameTable);
    bool createTablePoint();

    QSqlDatabase db;

};



#endif // DBMANAGER_H
