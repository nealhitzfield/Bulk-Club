/** @file additemwindow.h
*	@brief Displays a window which lets the user add an item and its price to the inventory.
*/

#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QDialog>
#include <QDebug>
#include "dbmanager.h"

namespace Ui {
class additemwindow;
}

/**
* @brief Receives input for adding new items.
*/
class additemwindow : public QDialog
{
    Q_OBJECT

public:
    explicit additemwindow(QWidget *parent = 0);
    ~additemwindow();

private slots:
    void on_addButton_clicked();

signals:
    void itemAdded();
private:
    Ui::additemwindow *ui;
};

#endif // ADDITEMWINDOW_H
