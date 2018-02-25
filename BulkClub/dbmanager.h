#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include "credentials.h"
#include "member.h"
#include "transaction.h"
#include "item.h"

class DBManager
{
private:
    QSqlDatabase bulkdb;
public:
    DBManager();
<<<<<<< HEAD
=======
    DBManager(const QString& dbFilename);
>>>>>>> 43f24e40a20e2f08b95cb34e5f32d573491b9ff6

    // Login
    bool VerifyLogin(const Credentials& credentials, QString& employeeType);

    // Members
    bool AddMember(const Member& newMember);
    bool RemoveMember(const Member& member);
    bool MemberExists(const Member& member);
    Member GetMember(int memberID);
    QList<Member> GetAllMembers();


    // Transactions
    bool AddTransaction(const Transaction& newTransaction);

    // Inventory
    bool AddItem(const Item& newItem);
    bool RemoveItem(const Item& item);
<<<<<<< HEAD
    bool ItemExists(const Item& item) const;
=======
    QList<Item> GetAllItems();
>>>>>>> 43f24e40a20e2f08b95cb34e5f32d573491b9ff6

    // Connection Test
    bool isOpen() const;
};

#endif // DBMANAGER_H
