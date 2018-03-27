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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreManagerWindow
{
public:
    QHBoxLayout *horizontalLayout_7;
    QTabWidget *SMTabs;
    QWidget *daily;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_4;
    QTableView *dailyView;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_3;
    QLabel *subtotal;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLabel *tax;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLabel *total;
    QPushButton *resetButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit;
    QLabel *label_status;
    QPushButton *dateFilterButton;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_item;
    QLabel *label;
    QPushButton *itemFilterButton;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *memberID;
    QLabel *label_2;
    QPushButton *memberFilterButton;
    QWidget *member;
    QWidget *item;

    void setupUi(QDialog *StoreManagerWindow)
    {
        if (StoreManagerWindow->objectName().isEmpty())
            StoreManagerWindow->setObjectName(QStringLiteral("StoreManagerWindow"));
        StoreManagerWindow->resize(523, 414);
        horizontalLayout_7 = new QHBoxLayout(StoreManagerWindow);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        SMTabs = new QTabWidget(StoreManagerWindow);
        SMTabs->setObjectName(QStringLiteral("SMTabs"));
        daily = new QWidget();
        daily->setObjectName(QStringLiteral("daily"));
        horizontalLayout_11 = new QHBoxLayout(daily);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        dailyView = new QTableView(daily);
        dailyView->setObjectName(QStringLiteral("dailyView"));
        dailyView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout_4->addWidget(dailyView);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_3 = new QLabel(daily);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_9->addWidget(label_3);

        subtotal = new QLabel(daily);
        subtotal->setObjectName(QStringLiteral("subtotal"));
        subtotal->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(subtotal);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(daily);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        tax = new QLabel(daily);
        tax->setObjectName(QStringLiteral("tax"));
        tax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(tax);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(daily);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        total = new QLabel(daily);
        total->setObjectName(QStringLiteral("total"));
        total->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(total);


        verticalLayout_2->addLayout(horizontalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_2);

        resetButton = new QPushButton(daily);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setMinimumSize(QSize(110, 23));
        resetButton->setMaximumSize(QSize(110, 23));

        horizontalLayout_10->addWidget(resetButton);


        verticalLayout_3->addLayout(horizontalLayout_10);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dateEdit = new QDateEdit(daily);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMaximumSize(QSize(102, 20));
        dateEdit->setMaximumDateTime(QDateTime(QDate(2019, 2, 18), QTime(23, 59, 59)));
        dateEdit->setMinimumDateTime(QDateTime(QDate(2017, 2, 12), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        label_status = new QLabel(daily);
        label_status->setObjectName(QStringLiteral("label_status"));

        horizontalLayout->addWidget(label_status);


        horizontalLayout_2->addLayout(horizontalLayout);

        dateFilterButton = new QPushButton(daily);
        dateFilterButton->setObjectName(QStringLiteral("dateFilterButton"));
        dateFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_2->addWidget(dateFilterButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_item = new QLineEdit(daily);
        lineEdit_item->setObjectName(QStringLiteral("lineEdit_item"));
        lineEdit_item->setMaximumSize(QSize(146, 16777215));

        horizontalLayout_3->addWidget(lineEdit_item);

        label = new QLabel(daily);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        itemFilterButton = new QPushButton(daily);
        itemFilterButton->setObjectName(QStringLiteral("itemFilterButton"));
        itemFilterButton->setMinimumSize(QSize(110, 0));
        itemFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_4->addWidget(itemFilterButton);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        memberID = new QSpinBox(daily);
        memberID->setObjectName(QStringLiteral("memberID"));
        memberID->setMinimumSize(QSize(70, 20));
        memberID->setMaximumSize(QSize(70, 20));
        memberID->setButtonSymbols(QAbstractSpinBox::NoButtons);
        memberID->setMinimum(10000);
        memberID->setMaximum(99999);

        horizontalLayout_5->addWidget(memberID);

        label_2 = new QLabel(daily);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        memberFilterButton = new QPushButton(daily);
        memberFilterButton->setObjectName(QStringLiteral("memberFilterButton"));
        memberFilterButton->setMinimumSize(QSize(110, 0));
        memberFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_5->addWidget(memberFilterButton);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(verticalLayout);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_11->addLayout(verticalLayout_4);

        SMTabs->addTab(daily, QString());
        member = new QWidget();
        member->setObjectName(QStringLiteral("member"));
        SMTabs->addTab(member, QString());
        item = new QWidget();
        item->setObjectName(QStringLiteral("item"));
        SMTabs->addTab(item, QString());

        horizontalLayout_7->addWidget(SMTabs);


        retranslateUi(StoreManagerWindow);

        SMTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StoreManagerWindow);
    } // setupUi

    void retranslateUi(QDialog *StoreManagerWindow)
    {
        StoreManagerWindow->setWindowTitle(QApplication::translate("StoreManagerWindow", "Dialog", nullptr));
        label_3->setText(QApplication::translate("StoreManagerWindow", "Sub Total", nullptr));
        subtotal->setText(QApplication::translate("StoreManagerWindow", "[+]Total", nullptr));
        label_4->setText(QApplication::translate("StoreManagerWindow", "Tax", nullptr));
        tax->setText(QApplication::translate("StoreManagerWindow", "[+]Total", nullptr));
        label_5->setText(QApplication::translate("StoreManagerWindow", "Total", nullptr));
        total->setText(QApplication::translate("StoreManagerWindow", "[+]Total", nullptr));
        resetButton->setText(QApplication::translate("StoreManagerWindow", "Reset Filter", nullptr));
        label_status->setText(QApplication::translate("StoreManagerWindow", "[+]Status", nullptr));
        dateFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label->setText(QApplication::translate("StoreManagerWindow", "Enter Item Name", nullptr));
        itemFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label_2->setText(QApplication::translate("StoreManagerWindow", "Enter Member ID", nullptr));
        memberFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(daily), QApplication::translate("StoreManagerWindow", "Sales", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(member), QApplication::translate("StoreManagerWindow", "Rebates", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(item), QApplication::translate("StoreManagerWindow", "Item Popularity", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreManagerWindow: public Ui_StoreManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREMANAGERWINDOW_H
