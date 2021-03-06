/** @file transaction.h
*	@brief Contains data in regard to transactions within the databse.
*/

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QDate>
#include "item.h"

const double TAX_RATE = 0.0775;

/**
* @brief Contains property values of a transaction from the database.
*/
class Transaction
{
private:
    QDate   transactionDate;
    int     buyersID;
    Item    itemPurchased;
    int     quantityPurchased;
    double  transactionSubtotal;
    double  transactionTotal;
public:
    Transaction();
    Transaction(QDate, int, Item, int, double, double);
    QDate GetTransactionDate() const;
    int GetBuyersID() const;
    Item GetItem() const;
    QString GetItemName() const;
    int GetQuantityPurchased() const;
    double GetTransactionSubTotal() const;
    double GetTransactionTotal() const;
};

#endif // TRANSACTION_H
