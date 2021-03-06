/** @file loginwindow.h
*	@brief Displays a window which prompts the user to enter a username and password.
*/

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "dbmanager.h"
#include "credentials.h"

namespace Ui {
class LoginWindow;
}

/**
* @brief Receives input for user login.
*/
class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
