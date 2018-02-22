#include "dbmanager.h"

DBManager::DBManager()
{
    bulkdb = QSqlDatabase::addDatabase("SQSLITE");
    bulkdb.setDatabaseName("bulkclub.db");

    if(!bulkdb.open())
    {
        qDebug() << "Can't connect to database";
    }
    else
    {
        qDebug() << "Connected to database";
    }
}
