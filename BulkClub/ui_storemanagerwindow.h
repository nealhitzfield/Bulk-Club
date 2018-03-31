/********************************************************************************
** Form generated from reading UI file 'storemanagerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREMANAGERWINDOW_H
#define UI_STOREMANAGERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_11;
    QTabWidget *SMTabs;
    QWidget *daily;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_5;
    QTableView *dailyView;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
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
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QLabel *label_ex_shoppers;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_7;
    QLabel *label_reg_shoppers;
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
    QPushButton *memberIDFilterButton;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit_memberName;
    QLabel *label_8;
    QPushButton *memberNameFilterButton;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *memberTypeComboBox;
    QLabel *label_9;
    QPushButton *memberTypeFilterButton;
    QWidget *member;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_11;
    QPushButton *ResetExpirationFilterButton;
    QTableView *ExpTable;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *monthComboBox;
    QLabel *label_10;
    QPushButton *getMemberExpirationButton;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_12;
    QTableView *rebateTable;

    void setupUi(QDialog *StoreManagerWindow)
    {
        if (StoreManagerWindow->objectName().isEmpty())
            StoreManagerWindow->setObjectName(QStringLiteral("StoreManagerWindow"));
        StoreManagerWindow->resize(563, 478);
        horizontalLayout_15 = new QHBoxLayout(StoreManagerWindow);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));

        horizontalLayout_15->addLayout(horizontalLayout_11);

        SMTabs = new QTabWidget(StoreManagerWindow);
        SMTabs->setObjectName(QStringLiteral("SMTabs"));
        daily = new QWidget();
        daily->setObjectName(QStringLiteral("daily"));
        horizontalLayout_16 = new QHBoxLayout(daily);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        dailyView = new QTableView(daily);
        dailyView->setObjectName(QStringLiteral("dailyView"));
        dailyView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout_5->addWidget(dailyView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
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


        horizontalLayout_12->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(daily);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(101, 0));

        horizontalLayout_7->addWidget(label_6);

        label_ex_shoppers = new QLabel(daily);
        label_ex_shoppers->setObjectName(QStringLiteral("label_ex_shoppers"));

        horizontalLayout_7->addWidget(label_ex_shoppers);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_7 = new QLabel(daily);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(101, 0));

        horizontalLayout_10->addWidget(label_7);

        label_reg_shoppers = new QLabel(daily);
        label_reg_shoppers->setObjectName(QStringLiteral("label_reg_shoppers"));

        horizontalLayout_10->addWidget(label_reg_shoppers);


        verticalLayout_3->addLayout(horizontalLayout_10);

        resetButton = new QPushButton(daily);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setMinimumSize(QSize(110, 23));
        resetButton->setMaximumSize(QSize(110, 23));

        verticalLayout_3->addWidget(resetButton);


        horizontalLayout_12->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_12);

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
        label_status->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

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
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

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
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_2);

        memberIDFilterButton = new QPushButton(daily);
        memberIDFilterButton->setObjectName(QStringLiteral("memberIDFilterButton"));
        memberIDFilterButton->setMinimumSize(QSize(110, 0));
        memberIDFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_5->addWidget(memberIDFilterButton);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        lineEdit_memberName = new QLineEdit(daily);
        lineEdit_memberName->setObjectName(QStringLiteral("lineEdit_memberName"));
        lineEdit_memberName->setMaximumSize(QSize(146, 16777215));

        horizontalLayout_13->addWidget(lineEdit_memberName);

        label_8 = new QLabel(daily);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(label_8);

        memberNameFilterButton = new QPushButton(daily);
        memberNameFilterButton->setObjectName(QStringLiteral("memberNameFilterButton"));
        memberNameFilterButton->setMinimumSize(QSize(110, 0));
        memberNameFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_13->addWidget(memberNameFilterButton);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        memberTypeComboBox = new QComboBox(daily);
        memberTypeComboBox->setObjectName(QStringLiteral("memberTypeComboBox"));
        memberTypeComboBox->setMaximumSize(QSize(111, 16777215));

        horizontalLayout_14->addWidget(memberTypeComboBox);

        label_9 = new QLabel(daily);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_14->addWidget(label_9);

        memberTypeFilterButton = new QPushButton(daily);
        memberTypeFilterButton->setObjectName(QStringLiteral("memberTypeFilterButton"));
        memberTypeFilterButton->setMinimumSize(QSize(110, 0));
        memberTypeFilterButton->setMaximumSize(QSize(110, 16777215));

        horizontalLayout_14->addWidget(memberTypeFilterButton);


        verticalLayout->addLayout(horizontalLayout_14);


        verticalLayout_4->addLayout(verticalLayout);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_16->addLayout(verticalLayout_5);

        SMTabs->addTab(daily, QString());
        member = new QWidget();
        member->setObjectName(QStringLiteral("member"));
        horizontalLayout_19 = new QHBoxLayout(member);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_11 = new QLabel(member);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_18->addWidget(label_11);

        ResetExpirationFilterButton = new QPushButton(member);
        ResetExpirationFilterButton->setObjectName(QStringLiteral("ResetExpirationFilterButton"));

        horizontalLayout_18->addWidget(ResetExpirationFilterButton);


        verticalLayout_6->addLayout(horizontalLayout_18);

        ExpTable = new QTableView(member);
        ExpTable->setObjectName(QStringLiteral("ExpTable"));

        verticalLayout_6->addWidget(ExpTable);


        verticalLayout_8->addLayout(verticalLayout_6);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        monthComboBox = new QComboBox(member);
        monthComboBox->setObjectName(QStringLiteral("monthComboBox"));
        monthComboBox->setMaximumSize(QSize(91, 16777215));

        horizontalLayout_17->addWidget(monthComboBox);

        label_10 = new QLabel(member);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(131, 0));

        horizontalLayout_17->addWidget(label_10);

        getMemberExpirationButton = new QPushButton(member);
        getMemberExpirationButton->setObjectName(QStringLiteral("getMemberExpirationButton"));

        horizontalLayout_17->addWidget(getMemberExpirationButton);


        verticalLayout_8->addLayout(horizontalLayout_17);


        verticalLayout_9->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_12 = new QLabel(member);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_7->addWidget(label_12);

        rebateTable = new QTableView(member);
        rebateTable->setObjectName(QStringLiteral("rebateTable"));

        verticalLayout_7->addWidget(rebateTable);


        verticalLayout_9->addLayout(verticalLayout_7);


        horizontalLayout_19->addLayout(verticalLayout_9);

        SMTabs->addTab(member, QString());

        horizontalLayout_15->addWidget(SMTabs);


        retranslateUi(StoreManagerWindow);

        SMTabs->setCurrentIndex(1);


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
        label_6->setText(QApplication::translate("StoreManagerWindow", "Executive Shoppers", nullptr));
        label_ex_shoppers->setText(QApplication::translate("StoreManagerWindow", "[+]Total", nullptr));
        label_7->setText(QApplication::translate("StoreManagerWindow", "Regular Shoppers", nullptr));
        label_reg_shoppers->setText(QApplication::translate("StoreManagerWindow", "[+]Total", nullptr));
        resetButton->setText(QApplication::translate("StoreManagerWindow", "Reset Filter", nullptr));
        label_status->setText(QApplication::translate("StoreManagerWindow", "Enter Transaction Date", nullptr));
        dateFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label->setText(QApplication::translate("StoreManagerWindow", "Enter Item Name", nullptr));
        itemFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label_2->setText(QApplication::translate("StoreManagerWindow", "Enter Member ID", nullptr));
        memberIDFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label_8->setText(QApplication::translate("StoreManagerWindow", "Enter Member Name", nullptr));
        memberNameFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        label_9->setText(QApplication::translate("StoreManagerWindow", "Membership Type", nullptr));
        memberTypeFilterButton->setText(QApplication::translate("StoreManagerWindow", "Get Transactions", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(daily), QApplication::translate("StoreManagerWindow", "Sales", nullptr));
        label_11->setText(QApplication::translate("StoreManagerWindow", "Membership Expirations", nullptr));
        ResetExpirationFilterButton->setText(QApplication::translate("StoreManagerWindow", "Reset Filter", nullptr));
        label_10->setText(QApplication::translate("StoreManagerWindow", "Enter Expiration Month", nullptr));
        getMemberExpirationButton->setText(QApplication::translate("StoreManagerWindow", "Get Members", nullptr));
        label_12->setText(QApplication::translate("StoreManagerWindow", "Member Rebates", nullptr));
        SMTabs->setTabText(SMTabs->indexOf(member), QApplication::translate("StoreManagerWindow", "Membership Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StoreManagerWindow: public Ui_StoreManagerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREMANAGERWINDOW_H
