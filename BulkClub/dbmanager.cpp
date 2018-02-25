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
