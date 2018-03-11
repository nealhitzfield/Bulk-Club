#include "transaction.h"

Transaction::Transaction() : transactionDate(1970, 1, 1), itemPurchased("", 0.0)
{
    buyersID = 0;
    quantityPurchased = 0;
    transactionPrice = 0.0;
}

Transaction::Transaction(QDate transDate, int bID, Item item, int quantity, double transPrice)
{
    transactionDate = transDate;
    buyersID = bID;
    itemPurchased = item;
    quantityPurchased = quantity;
    transactionPrice = transPrice;
}

QDate Transaction::GetTransactionDate() const
{
    return transactionDate;
}

int Transaction::GetBuyersID() const
{
    return buyersID;
}

Item Transaction::GetItem() const
{
    return itemPurchased;
}

QString Transaction::GetItemName() const
{
    return itemPurchased.GetItemName();
}

int Transaction::GetQuantityPurchased() const
{
    return quantityPurchased;
}

double Transaction::GetTransactionPrice() const
{
    return transactionPrice;
}
