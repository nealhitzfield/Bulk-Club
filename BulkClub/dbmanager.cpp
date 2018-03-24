#include "dbmanager.h"
#include <QFile>

DBManager::DBManager()
{
    bulkdb = QSqlDatabase::addDatabase("QSQLITE");
    bulkdb.setDatabaseName("bulkclub.db");

    if(QFile::exists("bulkclub.db"))
    {
        if(!bulkdb.open())
        {
            qDebug() << "Error connecting to database";
        }
        else
        {
            qDebug() << "Connected to database";
        }
    }
    else
    {
        qDebug() << "Database file path does not exist";
    }
}

DBManager::~DBManager()
{
    if(bulkdb.isOpen())
    {
        bulkdb.close();
    }
    qDebug() << "Destroying DBManager";
}

DBManager& DBManager::instance()
{
    static DBManager bulkdbInstance;

    return bulkdbInstance;
}
bool DBManager::AddItem(const Item& newItem)
{
    bool success = false;
    QString itemName;
    double price;

    itemName = newItem.GetItemName();
    price = newItem.GetItemPrice();

    QSqlQuery query;
    query.prepare("INSERT INTO inventory (item_name, price) VALUES (:iName, :iPrice)");
    query.bindValue(":iName", itemName);
    query.bindValue(":iPrice", price);

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "addItem error:"
                 << query.lastError();
    }

    return success;
}
bool DBManager::RemoveItem(const Item& item)
{
    QSqlQuery query;
    bool success;
    QString itemName;

    success = false;
    itemName = item.GetItemName();

    if(ItemExists(item))
    {
        query.prepare("DELETE FROM inventory WHERE item_name = (:name)");
        query.bindValue(":name", itemName);

        if(query.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "RemoveItem error:"
                     << query.lastError();
        }
    }
    return success;
}

bool DBManager::ItemExists(const Item& item) const
{
    bool exists;
    QSqlQuery query;

    query.prepare("SELECT item_name FROM inventory WHERE item_name = :name");
    query.bindValue(":name", item.GetItemName());

    exists = false;
    if(query.exec())
    {
        if(query.next())
        {
            exists = true;
        }
    }

    return exists;
}

bool DBManager::VerifyLogin(const Credentials &credentials, QString& employeeType)
{
    QSqlQuery query;
    bool success;

    success = false;
    query.prepare("SELECT username, password, employee_type FROM credentials WHERE username = :user AND password = :passw");
    query.bindValue(":user", credentials.GetUsername());
    query.bindValue(":passw", credentials.GetPassword());

    if(query.exec())
    {
        if(query.next())
        {
            employeeType = query.value(2).toString();
            success = true;
        }
    }
    else
    {
        qDebug() << "Login Error: " << query.lastError();
    }

    return success;
}
bool DBManager::AddMember(const Member& newMember)
{
    QSqlQuery query;
    bool success;

    success = false;
    query.prepare("INSERT INTO members (name, id, member_type, expiration_date)"
                  " VALUES (:name, :id, :member_type, :expiration_date)");
    query.bindValue(":name", newMember.GetMemberName());
    query.bindValue(":id", newMember.GetID());
    query.bindValue(":member_type", newMember.GetMembershipTypeString());
    query.bindValue(":expiration_date", newMember.GetExpirationDateString());

    if(query.exec())
    {
        success = true;
    }
    else
    {
        qDebug() << "Add Member Error: " << query.lastError();
    }

    return success;
}

bool DBManager::RemoveMember(const Member& member)
{
    bool success;
    QSqlQuery deleteQuery;

    success = false;

    if(MemberExists(member))
    {
        deleteQuery.prepare("DELETE FROM members WHERE name = (:name) AND id = (:id)");
        deleteQuery.bindValue(":name", member.GetMemberName());
        deleteQuery.bindValue(":id", member.GetID());

        if(deleteQuery.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "Remove Member Error: " << deleteQuery.lastError();
        }
    }
    else
    {
        qDebug() << "Member doesn't exist";
    }

    return success;
}

bool DBManager::MemberExists(const Member& member)
{
    bool memberExists;
    QSqlQuery checkQuery;

    memberExists = false;

    checkQuery.prepare("SELECT id FROM members WHERE id = (:id)");
    checkQuery.bindValue(":id", member.GetID());

    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            memberExists = true;
        }
    }

    return memberExists;
}

Member DBManager::GetMember(int memberID)
{
    QSqlQuery query;
    int nameIndex;
    int idIndex;
    int mTypeIndex;
    int expDateIndex;
    int totalSpentIndex;
    int rebateIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double totalSpent;
    double rebate;

    query.prepare("SELECT name, id, member_type, expiration_date, total_spent, rebate FROM members WHERE id = :id");
    query.bindValue(":id", memberID);

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("name");
        idIndex         = query.record().indexOf("id");
        mTypeIndex      = query.record().indexOf("member_type");
        expDateIndex    = query.record().indexOf("expiration_date");
        totalSpentIndex = query.record().indexOf("expiration_date");
        rebateIndex     = query.record().indexOf("rebate");
        if(query.next())
        {
            name    = query.value(nameIndex).toString();
            id      = query.value(idIndex).toInt();
            mType   = query.value(mTypeIndex).toString();
            if(mType == "Regular")
            {
                membershipType = REGULAR;
            }
            else if(mType == "Executive")
            {
                membershipType = EXECUTIVE;
            }
            expDate = query.value(expDateIndex).toString();
            expirationDate = QDate::fromString(expDate, "MM/dd/yyyy");
            totalSpent = query.value(totalSpentIndex).toDouble();
            rebate = query.value(rebateIndex).toDouble();
        }
        else
        {
            qDebug() << "Can't find member";
        }
    }
    else
    {
        qDebug() << "Get Member Error: " << query.lastError();
    }

    return Member(name, id, membershipType, expirationDate, totalSpent, rebate);
}

QList<Member> DBManager::GetAllMembers()
{
    QSqlQuery query;
    QList<Member> memberList;
    int nameIndex;
    int idIndex;
    int mTypeIndex;
    int expDateIndex;
    int totalSpentIndex;
    int rebateIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double totalSpent;
    double rebate;

    query.prepare("SELECT name, id, member_type, expiration_date, total_spent, rebate FROM members");

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("name");
        idIndex         = query.record().indexOf("id");
        mTypeIndex      = query.record().indexOf("member_type");
        expDateIndex    = query.record().indexOf("expiration_date");
        totalSpentIndex = query.record().indexOf("expiration_date");
        rebateIndex     = query.record().indexOf("rebate");
        while(query.next())
        {
            name    = query.value(nameIndex).toString();
            id      = query.value(idIndex).toInt();
            mType   = query.value(mTypeIndex).toString();
            if(mType == "Regular")
            {
                membershipType = REGULAR;
            }
            else if(mType == "Executive")
            {
                membershipType = EXECUTIVE;
            }
            expDate = query.value(expDateIndex).toString();
            expirationDate = QDate::fromString(expDate, "MM/dd/yyyy");
            totalSpent = query.value(totalSpentIndex).toDouble();
            rebate = query.value(rebateIndex).toDouble();

            memberList.append(Member(name, id, membershipType, expirationDate, totalSpent, rebate));
        }
    }
    else
    {
        qDebug() << "Error Getting Members: " << query.lastError();
    }

    return memberList;
}

Item DBManager::GetItem(QString itemName)
{
    QSqlQuery query;
    int nameIndex;
    int priceIndex;
    QString name;
    double price;

    query.prepare("SELECT item_name, price FROM inventory WHERE item_name = :item_name");
    query.bindValue(":item_name", itemName);

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("item_name");
        priceIndex      = query.record().indexOf("price");

        if(query.next())
        {
            name       = query.value(nameIndex).toString();
            price      = query.value(priceIndex).toDouble();
        }
        else
        {
            qDebug() << "Can't find item";
        }
    }
    else
    {
        qDebug() << "Get Item Error: " << query.lastError();
    }

    return Item(name, price);
}

bool DBManager::isOpen() const
{
    return bulkdb.isOpen();
}

QList<Item> DBManager::GetAllItems()
{
    QList<Item> itemList;
    QString name;
    double price;
    int nameIndex;
    int priceIndex;
    QSqlQuery query;

    query.prepare("SELECT item_name, price FROM inventory");

    if(query.exec())
    {
        nameIndex = query.record().indexOf("item_name");
        priceIndex = query.record().indexOf("price");
        while(query.next())
        {
            name = query.value(nameIndex).toString();
            price = query.value(priceIndex).toDouble();

            itemList.append(Item(name, price));
        }
    }
    else
    {
        qDebug() << "Error getting items: " << query.lastError();
    }

    return itemList;
}

bool DBManager::AddTransaction(const Transaction& newTransaction)
{
    QSqlQuery query;
    bool success;

    query.prepare("INSERT INTO transactions (transaction_date, id, item_name, price, quantity) \
                  VALUES (:transaction_date, :id, :item_name, :price, :quantity)");
    query.bindValue(":transaction_date", newTransaction.GetTransactionDate());
    query.bindValue(":id", newTransaction.GetBuyersID());
    query.bindValue(":item_name", newTransaction.GetItemName());
    query.bindValue(":price", newTransaction.GetTransactionPrice());
    query.bindValue(":quantity", newTransaction.GetQuantityPurchased());

    if(query.exec())
    {
        success = true;
        TransactionUpdateInventory(newTransaction);   // If transaction was successful, update the inventory details.
    }
    else
    {
       qDebug() << "Failed to add transaction" << query.lastError();
    }
    return success;
}

bool DBManager::TransactionUpdateInventory(const Transaction newTransaction)
{
    QSqlQuery query;
    bool success;
    if(ItemExists(newTransaction.GetItem()))  // If the item exists, update it.
    {
        query.prepare("UPDATE inventory SET quantity_sold = quantity_sold + :transactionQuantity WHERE item_name = :item_name");
        query.bindValue(":transactionQuantity", newTransaction.GetQuantityPurchased());
        query.bindValue(":item_name", newTransaction.GetItemName());
        if(query.exec())
        {
            success = true;
            qDebug() << "Updated quantity sold.";
        }
        else
        {
            qDebug() << "Updating item in inventory failed." << query.lastError();
        }
     }
    else  // If the item doesn't exist, return.
    {
        qDebug() << "Item did not exist";
        success = false;
    }
    return success;
}

bool DBManager::RemoveTransaction(const Transaction& transaction)
{
    bool success;
    QSqlQuery deleteQuery;

    success = false;

    if(TransactionExists(transaction))
    {
        deleteQuery.prepare("DELETE FROM transactions WHERE id = :id AND item_name = :item_name)");
        deleteQuery.bindValue(":id", transaction.GetBuyersID());
        deleteQuery.bindValue(":item_name", transaction.GetItemName());

        success = deleteQuery.exec();

        if(!success)
        {
            qDebug() << "Remove Transaction Error: " << deleteQuery.lastError();
        }
    }
    else
    {
        qDebug() << "Transaction doesn't exist";
    }

    return success;
}

bool DBManager::TransactionExists(const Transaction& trans)
{
    bool transactionExists;
    QSqlQuery checkQuery;

    transactionExists = false;

    checkQuery.prepare("SELECT id, item_name, price, quantity FROM transactions "
                       "WHERE id = :id AND item_name = :item_name AND price = :price AND quantity = :quantity");
    checkQuery.bindValue(":id", trans.GetBuyersID());
    checkQuery.bindValue(":item_name", trans.GetItemName());
    checkQuery.bindValue(":price", trans.GetTransactionPrice());
    checkQuery.bindValue(":quantity", trans.GetQuantityPurchased());

    if(checkQuery.exec())
    {
        if(checkQuery.next())
        {
            transactionExists = true;
        }
    }

    return transactionExists;
}

QList<Transaction> DBManager::GetAllTransactions()
{
    QSqlQuery query;
    QList<Transaction> transactionList;
    int dateIndex;
    int idIndex;
    int itemNameIndex;
    int priceIndex;
    int qtyIndex;
    QDate transDate;
    int id;
    QString itemName;
    double itemPrice;
    int qty;
    double transTotal;

    query.prepare("SELECT transaction_date, id, item_name, price, quantity FROM transactions");

    if(query.exec())
    {
        dateIndex       = query.record().indexOf("transaction_date");
        idIndex         = query.record().indexOf("id");
        itemNameIndex   = query.record().indexOf("item_name");
        priceIndex      = query.record().indexOf("price");
        qtyIndex        = query.record().indexOf("quantity");

        while(query.next())
        {
            transDate   = QDate::fromString(query.value(dateIndex).toString(), "MM/dd/yyyy");
            id          = query.value(idIndex).toInt();
            itemName    = query.value(itemNameIndex).toString();
            itemPrice   = query.value(priceIndex).toDouble();
            qty         = query.value(qtyIndex).toInt();
            transTotal  = qty * itemPrice;

            transactionList.append(Transaction(transDate, id, Item(itemName, itemPrice), qty, transTotal));
        }
    }
    else
    {
        qDebug() << "Error Getting Transactions: " << query.lastError();
    }

    return transactionList;
}

double DBManager::CalcGrossSales()
{
    QSqlQuery query;
    double grossSales;

    query.prepare("SELECT Sum(total) FROM transactions");
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

double DBManager::CalcGrossSalesByDate(QDate tDate)
{
    QSqlQuery query;
    double grossSales;

    query.prepare("SELECT Sum(total) FROM transactions WHERE transaction_date = :date");
    query.bindValue(":date", tDate.toString("MM/dd/yyyy"));
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

double DBManager::CalcGrossSalesByMember(int buyersID)
{
    QSqlQuery query;
    double grossSales;

    query.prepare("SELECT Sum(total) FROM transactions WHERE id = :id");
    query.bindValue(":id", buyersID);
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

double DBManager::CalcGrossSalesByItem(QString itemName)
{
    QSqlQuery query;
    double grossSales;

    query.prepare("SELECT Sum(total) FROM transactions WHERE item_name = :iName COLLATE NOCASE");
    query.bindValue(":iName", itemName);
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

bool DBManager::GetValidDates(QDate &earliestDate, QDate &latestDate)
{
    bool success;
    QSqlQuery query;
    int transIndex;
    QDate tempDate;

    query.prepare("SELECT transaction_date FROM transactions");

    if(query.exec())
    {
        transIndex = query.record().indexOf("transaction_date");
        if(query.next())
        {
            success = true;
            earliestDate = QDate::fromString(query.value(transIndex).toString(), "MM/dd/yyyy");
            latestDate = QDate::fromString(query.value(transIndex).toString(), "MM/dd/yyyy");
            while(query.next())
            {
                tempDate = QDate::fromString(query.value(transIndex).toString(), "MM/dd/yyyy");
                if(tempDate < earliestDate)
                {
                    earliestDate = tempDate;
                }
                else if(tempDate > latestDate)
                {
                    latestDate = tempDate;
                }
            }

        }
        else
        {
            success = false;
        }
    }
    else
    {
        success = false;
    }

    return success;
}
