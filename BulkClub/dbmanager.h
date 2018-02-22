#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include "member.h"
#include "transaction.h"
#include "item.h"

class DBManager
{
private:
    QSqlDatabase bulkdb;
public:
    DBManager(const QString& dbFilename);

    // Login
    bool VerifyLogin(const Credentials& credentials);

    // Members
    bool AddMember(const Member& newMember);
    bool RemoveMember(const Member& member);

    // Transactions
    bool AddTransaction(const Transaction& newTransaction);

    // Inventory
    bool AddItem(const Item& newItem);
    bool RemoveItem(const Item& item);

};

#endif // DBMANAGER_H
