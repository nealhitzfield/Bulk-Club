#include "item.h"

Item::Item(QString iName, double iPrice)
{
    itemName = iName;
    itemPrice =iPrice;
}

QString Item::GetItemName() const
{
    return itemName;
}
double Item::GetItemPrice() const
{
    return itemPrice;
}
