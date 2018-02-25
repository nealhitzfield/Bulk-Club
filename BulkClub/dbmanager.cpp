#include "dbmanager.h"

DBManager::DBManager()
{
    bulkdb = QSqlDatabase::database();
}
DBManager::DBManager(const QString& dbFilename)
{
    bulkdb = QSqlDatabase::addDatabase("QSQLITE");
    bulkdb.setDatabaseName(dbFilename);

    if(!bulkdb.open())
    {
        qDebug() << "Can't connect to database";
    }
    else
    {
        qDebug() << "Connected to database";
    }
}

<<<<<<< HEAD
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
            bool success = false;
            QString itemName = item.GetItemName();

        if(ItemExists(item))
            {
            query.prepare("DELETE FROM inventory WHERE item_name = (:name)");
            query.bindValue(":name", itemName);

            success = query.exec();

            if(!success)
            {
                qDebug() << "RemoveItem error:"
                         << query.lastError();
            }

        }

            return success;
    }

    bool DBManager::ItemExists(const Item& item) const
    {
        bool exists = false;
        QSqlQuery query;
        QString itemName = item.GetItemName();
        query.prepare("SELECT FROM inventory WHERE item_name = (:name)");
        query.bindValue(":name", itemName);

        if(query.exec())
        {
            if(query.next())
            {
                exists = true;
            }
        }

        return exists;
    }
=======
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

    query.prepare("INSERT INTO members (name, id, member_type, expiration_date)"
                  " VALUES (:name, :id, :member_type, :expiration_date)");
    query.bindValue(":name", newMember.GetMemberName());
    query.bindValue(":id", newMember.GetID());
    query.bindValue(":member_type", newMember.GetMembershipTypeString());
    query.bindValue(":expiration_date", newMember.GetExpirationDateString());

    success = query.exec();

    if(!success)
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

        success = deleteQuery.exec();

        if(!success)
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
>>>>>>> 43f24e40a20e2f08b95cb34e5f32d573491b9ff6
