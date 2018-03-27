#include "transaction.h"

Transaction::Transaction() : transactionDate(1970, 1, 1), itemPurchased("", 0.0)
{
    buyersID = 0;
    quantityPurchased = 0;
    transactionSubtotal = 0.0;
    transactionTotal = 0.0;
}

Transaction::Transaction(QDate transDate, int bID, Item item, int quantity, double transSub, double transTotal)
{
    transactionDate = transDate;
    buyersID = bID;
    itemPurchased = item;
    quantityPurchased = quantity;
    transactionSubtotal = transSub;
    transactionTotal = transTotal;
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

double Transaction::GetTransactionSubTotal() const
{
    return transactionSubtotal;
}

double Transaction::GetTransactionTotal() const
{
    return transactionTotal;
}
