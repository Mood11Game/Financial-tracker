#include "dbmanager.h"

DBManager::DBManager(const QString& dataBaseName, const QString& nameUser, const QString& psswd, const QString nameTableUser)
{
    if (!createConnected(dataBaseName, nameUser, psswd))
    {
        qCritical() << "Error open database : " << dataBaseName;
        return;
    }

    if (!createTableUser(nameTableUser))
    {
        qCritical() << "Error create table " << nameTableUser;
        return;
    }

    if(!createTablePoint())
    {
        qCritical() << "Error create table pointTable";
        return;
    }
}

DBManager::~DBManager()
{
    if(db.open())
    {
        db.close();
    }

    qDebug() << "db conect closed";
}

bool DBManager::createTableUser(const QString& nameTable)
{
    QSqlQuery query;

    QString sql =
        "CREATE TABLE IF NOT EXISTS " + nameTable + " ("
        "id SERIAL PRIMARY KEY, "
        "login TEXT UNIQUE NOT NULL, "
        "password_hash TEXT NOT NULL"
        ");";

    bool success = query.exec(sql);

    if (!success)
        qCritical() << "SQL Error:" << query.lastError().text() << "Query:" << sql;

    return success;
}




bool DBManager::createTablePoint()
{
    QSqlQuery query;

    QString sql =
        "CREATE TABLE IF NOT EXISTS pointTable ("
        "id SERIAL PRIMARY KEY, "
        "user_id INTEGER NOT NULL, "
        "amount NUMERIC NOT NULL, "
        "description TEXT, "
        "timestamp TIMESTAMP DEFAULT now(), "
        "balance NUMERIC, "
        "FOREIGN KEY (user_id) REFERENCES user_table(id) ON DELETE CASCADE"
        ");";

    bool success = query.exec(sql);

    if (!success)
        qCritical() << "SQL Error:" << query.lastError().text() << "Query:" << sql;

    return success;
}



bool DBManager::createConnected(const QString& dataBaseName, const QString& nameUser, const QString& psswd)
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName(dataBaseName);
    db.setUserName(nameUser);
    db.setPassword(psswd);

    if(!db.open())
        return false;

    return true;
}
