#include "item.h"

Item::Item(QString name, double price)
{
    itemName = name;
    itemPrice = price;
}

QString Item::GetItemName() const
{
    return itemName;
}

double Item::GetItemPrice() const
{
    return itemPrice;
}
