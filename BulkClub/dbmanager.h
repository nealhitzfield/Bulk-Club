/** @file dbmanager.h
*	@brief Handles information sent to and read from the bulkclub database file.
*/

#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QList>
#include <QFile>
#include <QString>
#include <fstream>
#include <string>
#include "credentials.h"
#include "member.h"
#include "transaction.h"
#include "item.h"

using namespace std;

const int TOTAL_TRANS_FILES = 7;
const string TRANS_FILES[] = {"data/day1.txt", "data/day2.txt", "data/day3.txt", "data/day4.txt", "data/day5.txt", "data/day6.txt", "data/day7.txt"};
const string MEMBER_FILE = "data/warehouse-shoppers.txt";

/**
* @brief Manages data stored within the bulkclub database file.
*/
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

    // Populate database from file
    bool IsDatabasePopulated();
    bool SetPopulatedFlag();
    bool PopulateMembers();
    bool PopulateTransactions();

    // Members
    bool AddMember(const Member& newMember);
    bool RemoveMember(const Member& member);
    bool MemberExists(const int memberID);
    Member GetMember(int memberID);
    QList<Member> GetAllMembers();
    QList<Member> GetUpgrades();
    QList<Member> GetDowngrades();
    QList<Member> GetExpirations(int month);
    QList<Member> GetRebates();

    // Transactions
    bool AddTransaction(const Transaction& newTransaction);
    bool TransactionExists(const Transaction& transaction);
    bool TransactionUpdateInventory(const Transaction newTransaction);
    bool TransactionUpdateMemberTotalSpent(const Transaction newTransaction);
    bool TransactionUpdateMemberRebate(const Transaction newTransaction);
    QList<Transaction> GetAllTransactions();
    double CalcGrossSales();
    double CalcGrossSalesByDate(QDate tDate);
    double CalcGrossSalesByMember(int buyersID);
    double CalcGrossSalesByMember(QString bName);
    double CalcGrossSalesByMember(MemberType mType);
    double CalcGrossSalesByItem(QString itemName);
    int GetTotalShoppers(MemberType mType);
    int GetTotalShoppersByDate(QDate, MemberType mType);
    int GetTotalShoppersByItem(QString itemName, MemberType mType);

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
