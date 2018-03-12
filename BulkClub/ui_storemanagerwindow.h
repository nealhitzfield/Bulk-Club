/********************************************************************************
** Form generated from reading UI file 'storemanagerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREMANAGERWINDOW_H
#define UI_STOREMANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreManagerWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *SMTabs;
    QWidget *daily;
    QTableView *dailyView;
    QDateEdit *dateEdit;
    QWidget *member;
    QWidget *item;

    void setupUi(QDialog *StoreManagerWindow)
    {
        if (StoreManagerWindow->objectName().isEmpty())
            StoreManagerWindow->setObjectName(QStringLiteral("StoreManagerWindow"));
        StoreManagerWindow->resize(411, 300);
        horizontalLayout = new QHBoxLayout(StoreManagerWindow);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SMTabs = new QTabWidget(StoreManagerWindow);
        SMTabs->setObjectName(QStringLiteral("SMTabs"));
        daily = new QWidget();
        daily->setObjectName(QStringLiteral("daily"));
        dailyView = new QTableView(daily);
        dailyView->setObjectName(QStringLiteral("dailyView"));
        dailyView->setGeometry(QRect(10, 10, 256, 192));
        dateEdit = new QDateEdit(daily);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(270, 10, 110, 22));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2018, 2, 18), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2018, 2, 12), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);
        SMTabs->addTab(daily, QString());
        member = new QWidget();
        member->setObjectName(QStringLiteral("member"));
        SMTabs->addTab(member, QString());
        item = new QWidget();
        item->setObjectName(QStringLiteral("item"));
        SMTabs->addTab(item, QString());

        horizontalLayout->addWidget(SMTabs);


        retranslateUi(StoreManagerWindow);

        SMTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StoreManagerWindow);
    } // setupUi

    void retranslateUi(QDialog *StoreManagerWindow)
    {
        StoreManagerWindow->setWindowTitle(QApplication::translate("StoreManagerWindow", "Dialog", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(daily), QApplication::translate("StoreManagerWindow", "Sales by day", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(member), QApplication::translate("StoreManagerWindow", "Sales by member", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(item), QApplication::translate("StoreManagerWindow", "Sales by item", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreManagerWindow: public Ui_StoreManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREMANAGERWINDOW_H
