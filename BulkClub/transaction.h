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
    double  transactionPrice;

public:
    Transaction();
    Transaction(QDate, int, Item, int, double);
    QDate GetTransactionDate() const;
    int GetBuyersID() const;
    Item GetItem() const;
    QString GetItemName() const;
    int GetQuantityPurchased() const;
    double GetTransactionPrice() const;
};

#endif // TRANSACTION_H
