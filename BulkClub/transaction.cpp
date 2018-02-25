#include "transaction.h"

Transaction::Transaction() : transactionDate(1970, 1, 1), itemPurchased("", 0.0)
{
    buyersID = 0;
    quantityPurchased = 0;
}

Transaction::Transaction(QDate transDate, Item item, int quantity)
{
    transactionDate = transDate;
    itemPurchased = item;
    quantityPurchased = quantity;
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

int Transaction::GetQuantityPurchased() const
{
    return quantityPurchased;
}
