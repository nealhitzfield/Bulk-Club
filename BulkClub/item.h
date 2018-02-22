#ifndef ITEM_H
#define ITEM_H


class Item
{
private:
    QString itemName;
    double  itemPrice;
public:
    Item();
    Item(string name, double price);

    string GetItemName() const;
    double GetItemPrice() const;
};

#endif // ITEM_H
