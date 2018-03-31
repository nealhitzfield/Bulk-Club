#include "dbmanager.h"

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

bool DBManager::IsDatabasePopulated()
{
    QSqlQuery flagQuery;
    bool databasePopulated;

    flagQuery.prepare("SELECT database_populated FROM populated_flag");
    if(flagQuery.exec())
        if(flagQuery.next())
            databasePopulated = flagQuery.value(0).toBool();

    return databasePopulated;
}

bool DBManager::SetPopulatedFlag()
{
    QSqlQuery flag;
    bool success;

    flag.prepare("UPDATE populated_flag SET database_populated = 1");

    if(flag.exec())
        success = true;
    else
        success = false;

    return success;
}
bool DBManager::PopulateMembers()
{
    bool success;
    ifstream fin;
    string mTypeStr;
    MemberType mType;
    string expDate;
    string mName;
    int id;

    fin.open(MEMBER_FILE.c_str());
    success = true;

    while(!fin.eof())
    {
        getline(fin, mName);
        fin >> id;
        fin.ignore(1000, '\n');
        getline(fin, mTypeStr);
        if(mTypeStr == "Regular")
            mType = REGULAR;
        else
            mType = EXECUTIVE;
        getline(fin, expDate);

        qDebug() << QString::fromStdString(mTypeStr);
        qDebug() << QString::fromStdString(expDate);
        qDebug() << QString::fromStdString(mName);
        qDebug() << id;

        if(!AddMember(Member(QString::fromStdString(mName), id, mType,
                            QDate::fromString(QString::fromStdString(expDate), "MM/dd/yyyy"))))
        {
            success = false;
        }
    }
    fin.close();

    return success;
}

bool DBManager::PopulateTransactions()
{
    bool success;
    ifstream fin;
    string transDate;
    int buyersID;
    string itemName;
    double itemPrice;
    int qty;
    double subtotal;
    double total;

    for(int fileCount = 0; fileCount < TOTAL_TRANS_FILES; fileCount++)
    {
        fin.open(TRANS_FILES[fileCount].c_str());
        while(!fin.eof())
        {
            getline(fin, transDate);
            fin >> buyersID;
            fin.ignore(1000, '\n');
            getline(fin, itemName);
            fin >> itemPrice;
            fin.ignore(1000, '\t');
            fin >> qty;
            fin.ignore(1000, '\n');

            qDebug() << QString::fromStdString(transDate);
            qDebug() << buyersID;
            qDebug() << QString::fromStdString(itemName);
            qDebug() << itemPrice;
            qDebug() << qty;

            subtotal = itemPrice * qty;
            total = subtotal + subtotal * TAX_RATE;

            if(!ItemExists(Item(QString::fromStdString(itemName), itemPrice)))
            {
                    if(!AddItem(Item(QString::fromStdString(itemName), itemPrice)))
                        qDebug() << "Error adding item";
            }
            if(!AddTransaction(Transaction(QDate::fromString(QString::fromStdString(transDate), "MM/dd/yyyy"),
                                       buyersID, Item(QString::fromStdString(itemName), itemPrice), qty,
                                       subtotal, total)))
            {
                success = false;
            }
        }
        fin.close();
    }

    return success;
}
bool DBManager::AddItem(const Item& newItem)
{
    bool success;
    QString itemName;
    double price;

    success = false;
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

    if(MemberExists(member.GetID()))
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

bool DBManager::MemberExists(const int memberID)
{
    bool memberExists;
    QSqlQuery checkQuery;

    memberExists = false;

    checkQuery.prepare("SELECT id FROM members WHERE id = (:id)");
    checkQuery.bindValue(":id", memberID);

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
    int rebateIndex;
    int totalSpentIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double rebate;
    double totalSpent;

    query.prepare("SELECT name, id, member_type, expiration_date, rebate, total_spent FROM members WHERE id = :id");
    query.bindValue(":id", memberID);

    if(query.exec())
    {
        nameIndex           = query.record().indexOf("name");
        idIndex             = query.record().indexOf("id");
        mTypeIndex          = query.record().indexOf("member_type");
        expDateIndex        = query.record().indexOf("expiration_date");
        rebateIndex         = query.record().indexOf("rebate");
        totalSpentIndex     = query.record().indexOf("total_spent");
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
            rebate = query.value(rebateIndex).toDouble();
            totalSpent = query.value(totalSpentIndex).toDouble();
        }
        else
        {
            qDebug() << "Can't find member";
            name = "";
            id = 0;
            membershipType = REGULAR;
            expirationDate = QDate(2000, 1, 1);
            rebate = 0;
            totalSpent = 0;
        }
    }
    else
    {
        qDebug() << "Get Member Error: " << query.lastError();
        name = "";
        id = 0;
        membershipType = REGULAR;
        expirationDate = QDate(2000, 1, 1);
        rebate = 0;
        totalSpent = 0;
    }

    return Member(name, id, membershipType, expirationDate, rebate, totalSpent);
}

QList<Member> DBManager::GetAllMembers()
{
    QSqlQuery query;
    QList<Member> memberList;
    int nameIndex;
    int idIndex;
    int mTypeIndex;
    int expDateIndex;
    int rebateIndex;
    int totalSpentIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double rebate;
    double totalSpent;

    query.prepare("SELECT name, id, member_type, expiration_date, rebate, total_spent FROM members");

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("name");
        idIndex         = query.record().indexOf("id");
        mTypeIndex      = query.record().indexOf("member_type");
        expDateIndex    = query.record().indexOf("expiration_date");
        rebateIndex     = query.record().indexOf("rebate");
        totalSpentIndex = query.record().indexOf("total_spent");

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
            rebate = query.value(rebateIndex).toDouble();
            totalSpent = query.value(totalSpentIndex).toDouble();

            memberList.append(Member(name, id, membershipType, expirationDate, rebate, totalSpent));
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

double DBManager::GetItemPrice(QString itemName)
{
    QSqlQuery query;
    int priceIndex;
    double itemPrice;

    query.prepare("SELECT price FROM inventory WHERE item_name = :itemName");
    query.bindValue(":itemName", itemName);

    if(query.exec())
    {
        priceIndex = query.record().indexOf("price");
        if(query.next())
        {
            itemPrice = query.value(priceIndex).toDouble();
        }
        else
        {
            itemPrice = 0.0;
        }
    }
    return itemPrice;
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

QStringList DBManager::GetAllItemNames()
{
    QSqlQuery query;
    int nameIndex;
    QString name;
    QStringList itemNames;

    query.prepare("SELECT item_name FROM inventory");
    if(query.exec())
    {
        nameIndex = query.record().indexOf("item_name");
        while(query.next())
        {
            name = query.value(nameIndex).toString();
            itemNames.append(name);
        }
    }
    else
    {
        qDebug() << "Error getting items: " << query.lastError();
    }
    return itemNames;
}
bool DBManager::AddTransaction(const Transaction& newTransaction)
{
    QSqlQuery query;
    bool success;


    query.prepare("INSERT INTO transactions (transaction_date, id, item_name, item_price, quantity, subtotal, total) "
                  "VALUES (:transaction_date, :id, :item_name, :item_price, :quantity, :subtotal, :total)");
    query.bindValue(":transaction_date", newTransaction.GetTransactionDate().toString("MM/dd/yyyy"));
    query.bindValue(":id", newTransaction.GetBuyersID());
    query.bindValue(":item_name", newTransaction.GetItemName());
    query.bindValue(":item_price", newTransaction.GetItem().GetItemPrice());
    query.bindValue(":quantity", newTransaction.GetQuantityPurchased());
    query.bindValue(":subtotal", newTransaction.GetTransactionSubTotal());
    query.bindValue(":total", newTransaction.GetTransactionTotal());

    if(query.exec())
    {
        success = true;
        TransactionUpdateInventory(newTransaction);   // If transaction was successful, update the inventory details.
        TransactionUpdateMemberTotalSpent(newTransaction); // If transaction was successful, update member's total spent
        if(GetMember(newTransaction.GetBuyersID()).isExecutive())
        {
            TransactionUpdateMemberRebate(newTransaction);
        }
    }
    else
    {
       qDebug() << "Failed to add transaction" << query.lastError();
       success = false;
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
            success = false;
        }
     }
    else  // If the item doesn't exist
    {
        qDebug() << "Item did not exist";
        success = false;
    }
    return success;
}

bool DBManager::TransactionUpdateMemberTotalSpent(const Transaction newTransaction)
{
    QSqlQuery query;
    bool success;
    if(MemberExists(newTransaction.GetBuyersID()))  // If the member exists, update it.
    {
        query.prepare("UPDATE members SET total_spent = total_spent + :transactionTotal WHERE id = :buyersID");
        query.bindValue(":transactionTotal", newTransaction.GetTransactionTotal());
        query.bindValue(":buyersID", newTransaction.GetBuyersID());
        if(query.exec())
        {
            success = true;
            qDebug() << "Updated total spent";
        }
        else
        {
            qDebug() << "Updating member's total spent failed: " << query.lastError();
            success = false;
        }
     }
    else  // If the member doesn't exist
    {
        qDebug() << "Member does not exist";
        success = false;
    }
    return success;
}

bool DBManager::TransactionUpdateMemberRebate(const Transaction newTransaction)
{
    QSqlQuery query;
    bool success;
    if(MemberExists(newTransaction.GetBuyersID()))  // If the member exists, update it.
    {
        query.prepare("UPDATE members SET rebate = rebate + :rebateAmt WHERE id = :buyersID");
        query.bindValue(":rebateAmt", newTransaction.GetTransactionSubTotal() * REBATE_RATE);
        query.bindValue(":buyersID", newTransaction.GetBuyersID());
        if(query.exec())
        {
            success = true;
            qDebug() << "Updated rebate";
        }
        else
        {
            qDebug() << "Updating member's rebate failed: " << query.lastError();
            success = false;
        }
     }
    else  // If the member doesn't exist
    {
        qDebug() << "Member does not exist";
        success = false;
    }
    return success;
}

bool DBManager::TransactionExists(const Transaction& trans)
{
    bool transactionExists;
    QSqlQuery checkQuery;

    transactionExists = false;

    checkQuery.prepare("SELECT id, item_name, quantity FROM transactions "
                       "WHERE id = :id AND item_name = :item_name AND quantity = :quantity");
    checkQuery.bindValue(":id", trans.GetBuyersID());
    checkQuery.bindValue(":item_name", trans.GetItemName());
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
    int itemPriceIndex;
    int qtyIndex;
    int subTotIndex;
    int totIndex;
    QDate transDate;
    int id;
    QString itemName;
    double itemPrice;
    int qty;
    double transSubtotal;
    double transTotal;

    query.prepare("SELECT transaction_date, id, item_name, item_price, quantity, subtotal, total FROM transactions");

    if(query.exec())
    {
        dateIndex       = query.record().indexOf("transaction_date");
        idIndex         = query.record().indexOf("id");
        itemNameIndex   = query.record().indexOf("item_name");
        itemPriceIndex  = query.record().indexOf("item_price");
        qtyIndex        = query.record().indexOf("quantity");
        subTotIndex     = query.record().indexOf("subtotal");
        totIndex        = query.record().indexOf("total");

        while(query.next())
        {
            transDate   = QDate::fromString(query.value(dateIndex).toString(), "MM/dd/yyyy");
            id          = query.value(idIndex).toInt();
            itemName    = query.value(itemNameIndex).toString();
            itemPrice   = query.value(itemPriceIndex).toDouble();
            qty         = query.value(qtyIndex).toInt();
            transSubtotal = query.value(subTotIndex).toDouble();
            transTotal  = query.value(totIndex).toDouble();

            transactionList.append(Transaction(transDate, id, Item(itemName, itemPrice), qty, transSubtotal, transTotal));
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

    query.prepare("SELECT Sum(subtotal) FROM transactions");
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

    query.prepare("SELECT Sum(subtotal) FROM transactions WHERE transaction_date = :date");
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

    query.prepare("SELECT Sum(subtotal) FROM transactions WHERE id = :id");
    query.bindValue(":id", buyersID);
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

double DBManager::CalcGrossSalesByMember(QString bName)
{
    QSqlQuery queryMember;
    QSqlQuery queryTrans;
    double grossSales;
    int id;

    queryMember.prepare("SELECT id FROM members WHERE name = :name COLLATE NOCASE");
    queryMember.bindValue(":name", bName);

    grossSales = 0;

    if(queryMember.exec())
        if(queryMember.next())
        {
            id = queryMember.value(0).toInt();

            queryTrans.prepare("SELECT Sum(subtotal) FROM transactions WHERE id = :id");
            queryTrans.bindValue(":id", id);

            if(queryTrans.exec())
                if(queryTrans.next())
                    grossSales = queryTrans.value(0).toDouble();
        }

    return grossSales;
}

double DBManager::CalcGrossSalesByMember(MemberType mType)
{
    QSqlQuery query;
    double grossSales;
    int id;

    query.prepare("SELECT subtotal, id FROM transactions");

    grossSales = 0;
    if(query.exec())
        while(query.next())
        {
            id = query.value(1).toInt();
            if(GetMember(id).isExecutive())
            {
                if(mType == EXECUTIVE)
                    grossSales += query.value(0).toDouble();
            }
            else
            {
                if(mType == REGULAR)
                    grossSales += query.value(0).toDouble();
            }
        }

    return grossSales;
}

double DBManager::CalcGrossSalesByItem(QString itemName)
{
    QSqlQuery query;
    double grossSales;

    query.prepare("SELECT Sum(subtotal) FROM transactions WHERE item_name = :iName COLLATE NOCASE");
    query.bindValue(":iName", itemName);
    grossSales = 0;

    if(query.exec())
        if(query.next())
            grossSales = query.value(0).toDouble();

    return grossSales;
}

int DBManager::GetTotalShoppers(MemberType mType)
{
    QSqlQuery query;
    int totalShoppers;
    int id;
    QString mTypeString;

    query.prepare("SELECT id FROM transactions");
    totalShoppers = 0;
    if(mType == REGULAR)
        mTypeString = "Regular";
    else
        mTypeString = "Executive";

    totalShoppers = 0;
    if(query.exec())
        while(query.next())
        {
            id = query.value(0).toInt();
            if(GetMember(id).GetMembershipTypeString() == mTypeString)
                totalShoppers++;
        }

    return totalShoppers;
}

int DBManager::GetTotalShoppersByDate(QDate fDate, MemberType mType)
{
    QSqlQuery query;
    int totalShoppers;
    int id;
    QString mTypeString;

    query.prepare("SELECT id FROM transactions WHERE transaction_date = :tDate");
    query.bindValue(":tDate", fDate.toString("MM/dd/yyyy"));

    totalShoppers = 0;
    if(mType == REGULAR)
        mTypeString = "Regular";
    else
        mTypeString = "Executive";

    if(query.exec())
        while(query.next())
        {
            id = query.value(0).toInt();
            if(GetMember(id).GetMembershipTypeString() == mTypeString)
                totalShoppers++;
        }

    return totalShoppers;
}

int DBManager::GetTotalShoppersByItem(QString itemName, MemberType mType)
{
    QSqlQuery query;
    int totalShoppers;
    int id;
    QString mTypeString;

    query.prepare("SELECT id FROM transactions WHERE item_name = :iName COLLATE NOCASE");
    query.bindValue(":iName", itemName);

    totalShoppers = 0;
    if(mType == REGULAR)
        mTypeString = "Regular";
    else
        mTypeString = "Executive";

    if(query.exec())
        while(query.next())
        {
            id = query.value(0).toInt();
            if(GetMember(id).GetMembershipTypeString() == mTypeString)
                totalShoppers++;
        }

    return totalShoppers;
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

QList<Member> DBManager::GetUpgrades()
{
    QSqlQuery query;
    QList<Member> memberList;
    int nameIndex;
    int idIndex;
    int mTypeIndex;
    int expDateIndex;
    int rebateIndex;
    int totalSpentIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double rebate;
    double totalSpent;

    query.prepare("SELECT name, id, member_type, expiration_date, rebate, total_spent FROM members");

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("name");
        idIndex         = query.record().indexOf("id");
        mTypeIndex      = query.record().indexOf("member_type");
        expDateIndex    = query.record().indexOf("expiration_date");
        rebateIndex     = query.record().indexOf("rebate");
        totalSpentIndex = query.record().indexOf("total_spent");

        while(query.next())
        {
            mType   = query.value(mTypeIndex).toString();
            if(mType == "Regular")
            {
                totalSpent = query.value(totalSpentIndex).toDouble();
                if(totalSpent/(1 + TAX_RATE) >= 120)
                {
                name    = query.value(nameIndex).toString();
                id      = query.value(idIndex).toInt();
                membershipType = REGULAR;
                expDate = query.value(expDateIndex).toString();
                expirationDate = QDate::fromString(expDate, "MM/dd/yyyy");
                rebate = query.value(rebateIndex).toDouble();
                memberList.append(Member(name, id, membershipType, expirationDate, rebate, totalSpent));
                }
            }
        }
    }
    else
    {
        qDebug() << "Error Getting Upgrades: " << query.lastError();
    }

    return memberList;
}

QList<Member> DBManager::GetDowngrades()
{
    QSqlQuery query;
    QList<Member> memberList;
    int nameIndex;
    int idIndex;
    int mTypeIndex;
    int expDateIndex;
    int rebateIndex;
    int totalSpentIndex;
    QString name;
    int id;
    QString mType;
    MemberType membershipType;
    QString expDate;
    QDate expirationDate;
    double rebate;
    double totalSpent;

    query.prepare("SELECT name, id, member_type, expiration_date, rebate, total_spent FROM members");

    if(query.exec())
    {
        nameIndex       = query.record().indexOf("name");
        idIndex         = query.record().indexOf("id");
        mTypeIndex      = query.record().indexOf("member_type");
        expDateIndex    = query.record().indexOf("expiration_date");
        rebateIndex     = query.record().indexOf("rebate");
        totalSpentIndex = query.record().indexOf("total_spent");

        while(query.next())
        {
            mType   = query.value(mTypeIndex).toString();
            if(mType == "Executive")
            {
                rebate = query.value(rebateIndex).toDouble();
                if(rebate < 120)
                {
                name    = query.value(nameIndex).toString();
                id      = query.value(idIndex).toInt();
                membershipType = REGULAR;
                totalSpent = query.value(totalSpentIndex).toDouble();
                expDate = query.value(expDateIndex).toString();
                expirationDate = QDate::fromString(expDate, "MM/dd/yyyy");
                memberList.append(Member(name, id, membershipType, expirationDate, rebate, totalSpent));
                }
            }
        }
    }
    else
    {
        qDebug() << "Error Getting Dowmgrades: " << query.lastError();
    }

    return memberList;
}
