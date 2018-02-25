#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include "item.h"

class Transaction
{
private:
    QDate   transactionDate;
    int     buyersID;
    Item    itemPurchased;
    int     quantityPurchased;
public:
    Transaction();
    Transaction(QDate transDate, Item item, int quantity);

    QDate GetTransactionDate() const;
    int GetBuyersID() const;
    Item GetItem() const;
    int GetQuantityPurchased() const;
};

#endif // TRANSACTION_H
