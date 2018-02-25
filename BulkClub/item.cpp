#include "item.h"

Item::Item(QString iName, double iPrice)
{
<<<<<<< HEAD
    itemName = iName;
    itemPrice =iPrice;
=======
    itemName = "";
    itemPrice = 0;
}

Item::Item(QString name, double price)
{
    itemName = name;
    itemPrice = price;
>>>>>>> 43f24e40a20e2f08b95cb34e5f32d573491b9ff6
}

QString Item::GetItemName() const
{
    return itemName;
}
<<<<<<< HEAD
=======

>>>>>>> 43f24e40a20e2f08b95cb34e5f32d573491b9ff6
double Item::GetItemPrice() const
{
    return itemPrice;
}
