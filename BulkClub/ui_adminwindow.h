/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *MembersTab;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QTableView *membersTable;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *addMemberButton;
    QPushButton *removeMemberButton;
    QWidget *InventoryTab;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QTableView *itemsTable;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addItemButton;
    QPushButton *removeItemButton;
    QWidget *UpgDowngTab;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QTableView *UpgradeTable;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QTableView *DowngradeTable;

    void setupUi(QDialog *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(654, 518);
        verticalLayout_3 = new QVBoxLayout(AdminWindow);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabWidget = new QTabWidget(AdminWindow);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        MembersTab = new QWidget();
        MembersTab->setObjectName(QStringLiteral("MembersTab"));
        horizontalLayout_3 = new QHBoxLayout(MembersTab);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        membersTable = new QTableView(MembersTab);
        membersTable->setObjectName(QStringLiteral("membersTable"));

        verticalLayout->addWidget(membersTable);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        addMemberButton = new QPushButton(MembersTab);
        addMemberButton->setObjectName(QStringLiteral("addMemberButton"));

        horizontalLayout_2->addWidget(addMemberButton);

        removeMemberButton = new QPushButton(MembersTab);
        removeMemberButton->setObjectName(QStringLiteral("removeMemberButton"));

        horizontalLayout_2->addWidget(removeMemberButton);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        tabWidget->addTab(MembersTab, QString());
        InventoryTab = new QWidget();
        InventoryTab->setObjectName(QStringLiteral("InventoryTab"));
        horizontalLayout_5 = new QHBoxLayout(InventoryTab);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        itemsTable = new QTableView(InventoryTab);
        itemsTable->setObjectName(QStringLiteral("itemsTable"));
        itemsTable->setSelectionMode(QAbstractItemView::MultiSelection);
        itemsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_2->addWidget(itemsTable);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        addItemButton = new QPushButton(InventoryTab);
        addItemButton->setObjectName(QStringLiteral("addItemButton"));

        horizontalLayout_4->addWidget(addItemButton);

        removeItemButton = new QPushButton(InventoryTab);
        removeItemButton->setObjectName(QStringLiteral("removeItemButton"));

        horizontalLayout_4->addWidget(removeItemButton);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        tabWidget->addTab(InventoryTab, QString());
        UpgDowngTab = new QWidget();
        UpgDowngTab->setObjectName(QStringLiteral("UpgDowngTab"));
        horizontalLayout = new QHBoxLayout(UpgDowngTab);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label = new QLabel(UpgDowngTab);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout_5->addWidget(label);

        UpgradeTable = new QTableView(UpgDowngTab);
        UpgradeTable->setObjectName(QStringLiteral("UpgradeTable"));

        verticalLayout_5->addWidget(UpgradeTable);


        verticalLayout_6->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_2 = new QLabel(UpgDowngTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout_4->addWidget(label_2);

        DowngradeTable = new QTableView(UpgDowngTab);
        DowngradeTable->setObjectName(QStringLiteral("DowngradeTable"));

        verticalLayout_4->addWidget(DowngradeTable);


        verticalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout->addLayout(verticalLayout_6);

        tabWidget->addTab(UpgDowngTab, QString());

        verticalLayout_3->addWidget(tabWidget);


        retranslateUi(AdminWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QDialog *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "Admin Window", nullptr));
        addMemberButton->setText(QApplication::translate("AdminWindow", "Add Member", nullptr));
        removeMemberButton->setText(QApplication::translate("AdminWindow", "Remove Member", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(MembersTab), QApplication::translate("AdminWindow", "Members", nullptr));
        tabWidget->setTabToolTip(tabWidget->indexOf(MembersTab), QApplication::translate("AdminWindow", "Member Management", nullptr));
        addItemButton->setText(QApplication::translate("AdminWindow", "Add Item", nullptr));
        removeItemButton->setText(QApplication::translate("AdminWindow", "Remove Item", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(InventoryTab), QApplication::translate("AdminWindow", "Inventory", nullptr));
        tabWidget->setTabToolTip(tabWidget->indexOf(InventoryTab), QApplication::translate("AdminWindow", "Inventory Management", nullptr));
        label->setText(QApplication::translate("AdminWindow", "Suggested Membership Upgrades", nullptr));
        label_2->setText(QApplication::translate("AdminWindow", "Suggested Membership Downgrades", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(UpgDowngTab), QApplication::translate("AdminWindow", "Upgrade/Downgrade", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
