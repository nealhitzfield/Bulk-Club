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
    DBManager();
    ~DBManager();

    QSqlDatabase bulkdb;
public:
    static DBManager& instance();
    DBManager(const DBManager&) = delete;
    void operator=(const DBManager&) = delete;

    // Login
    bool VerifyLogin(const Credentials& credentials, QString& employeeType);

    // Members
    bool AddMember(const Member& newMember);
    bool RemoveMember(const Member& member);
    bool MemberExists(const int memberID);
    Member GetMember(int memberID);
    QList<Member> GetAllMembers();

    // Transactions
    bool AddTransaction(const Transaction& newTransaction);
    bool RemoveTransaction(const Transaction& transaction);
    bool TransactionExists(const Transaction& transaction);
    bool TransactionUpdateInventory(const Transaction newTransaction);
    bool TransactionUpdateMemberTotalSpent(const Transaction newTransaction);
    bool TransactionUpdateMemberRebate(const Transaction newTransaction);
    QList<Transaction> GetAllTransactions();
    double CalcGrossSales();
    double CalcGrossSalesByDate(QDate tDate);
    double CalcGrossSalesByMember(int buyersID);
    double CalcGrossSalesByItem(QString itemName);

    // Inventory
    bool AddItem(const Item& newItem);
    bool RemoveItem(const Item& item);
    bool ItemExists(const Item& item) const;
    Item GetItem(QString itemName);
    double GetItemPrice(QString itemName);
    QList<Item> GetAllItems();
    QStringList GetAllItemNames();

    // Connection Test
    bool isOpen() const;

    // Retrieve boundaries of transaction dates
    bool GetValidDates(QDate& earliestDate, QDate& latestDate);
};

#endif // DBMANAGER_H
