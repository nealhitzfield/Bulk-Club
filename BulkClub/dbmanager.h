#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include <QObject>
#include "credentials.h"
#include "member.h"
#include "transaction.h"
#include "item.h"

class DBManager : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase bulkdb;
public:
    DBManager();

    DBManager(const QString& dbFilename);

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
    bool RemoveTransaction(const Transaction& transaction);
    bool TransactionExists(const Transaction& transaction);
    bool TransactionUpdateInventory(const Transaction newTransaction);
    QList<Transaction> GetAllTransactions();

    // Inventory
    bool AddItem(const Item& newItem);
    bool RemoveItem(const Item& item);
    bool ItemExists(const Item& item) const;
    Item GetItem(QString itemName);
    QList<Item> GetAllItems();

    // Connection Test
    bool isOpen() const;

    // Retrieve boundaries of transaction dates
    bool GetValidDates(QDate& earliestDate, QDate& latestDate);
};

#endif // DBMANAGER_H
