/********************************************************************************
** Form generated from reading UI file 'addtransactionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANSACTIONWINDOW_H
#define UI_ADDTRANSACTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *dateLabel;
    QDateEdit *purchaseDate;
    QLabel *itemLabel;
    QComboBox *comboBox;
    QLabel *quantityLabel;
    QSpinBox *purchaseQuantity;
    QPushButton *purchaseAddButton;
    QPushButton *purchaseCancelButton;
    QLabel *label_status;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_item_price;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLabel *label_trans_total;

    void setupUi(QDialog *AddTransactionWindow)
    {
        if (AddTransactionWindow->objectName().isEmpty())
            AddTransactionWindow->setObjectName(QStringLiteral("AddTransactionWindow"));
        AddTransactionWindow->resize(296, 304);
        widget = new QWidget(AddTransactionWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(57, 62, 182, 166));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateLabel = new QLabel(widget);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        gridLayout->addWidget(dateLabel, 0, 0, 1, 1);

        purchaseDate = new QDateEdit(widget);
        purchaseDate->setObjectName(QStringLiteral("purchaseDate"));
        purchaseDate->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(purchaseDate, 0, 1, 1, 2);

        itemLabel = new QLabel(widget);
        itemLabel->setObjectName(QStringLiteral("itemLabel"));

        gridLayout->addWidget(itemLabel, 1, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 2);

        quantityLabel = new QLabel(widget);
        quantityLabel->setObjectName(QStringLiteral("quantityLabel"));

        gridLayout->addWidget(quantityLabel, 2, 0, 1, 1);

        purchaseQuantity = new QSpinBox(widget);
        purchaseQuantity->setObjectName(QStringLiteral("purchaseQuantity"));
        purchaseQuantity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        purchaseQuantity->setMaximum(9999);

        gridLayout->addWidget(purchaseQuantity, 2, 1, 1, 1);

        purchaseAddButton = new QPushButton(widget);
        purchaseAddButton->setObjectName(QStringLiteral("purchaseAddButton"));

        gridLayout->addWidget(purchaseAddButton, 3, 0, 1, 2);

        purchaseCancelButton = new QPushButton(widget);
        purchaseCancelButton->setObjectName(QStringLiteral("purchaseCancelButton"));

        gridLayout->addWidget(purchaseCancelButton, 3, 2, 1, 1);

        label_status = new QLabel(widget);
        label_status->setObjectName(QStringLiteral("label_status"));

        gridLayout->addWidget(label_status, 4, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_item_price = new QLabel(widget);
        label_item_price->setObjectName(QStringLiteral("label_item_price"));

        verticalLayout->addWidget(label_item_price);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(91, 0));

        verticalLayout_2->addWidget(label_3);

        label_trans_total = new QLabel(widget);
        label_trans_total->setObjectName(QStringLiteral("label_trans_total"));

        verticalLayout_2->addWidget(label_trans_total);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(AddTransactionWindow);

        QMetaObject::connectSlotsByName(AddTransactionWindow);
    } // setupUi

    void retranslateUi(QDialog *AddTransactionWindow)
    {
        AddTransactionWindow->setWindowTitle(QApplication::translate("AddTransactionWindow", "Add Transaction ", nullptr));
        dateLabel->setText(QApplication::translate("AddTransactionWindow", "Date:", nullptr));
        itemLabel->setText(QApplication::translate("AddTransactionWindow", "Item", nullptr));
        quantityLabel->setText(QApplication::translate("AddTransactionWindow", "Quantity", nullptr));
        purchaseAddButton->setText(QApplication::translate("AddTransactionWindow", "Add Purchase", nullptr));
        purchaseCancelButton->setText(QApplication::translate("AddTransactionWindow", "Cancel", nullptr));
        label_status->setText(QString());
        label->setText(QApplication::translate("AddTransactionWindow", "Item Price", nullptr));
        label_item_price->setText(QString());
        label_3->setText(QApplication::translate("AddTransactionWindow", "Transaction Total", nullptr));
        label_trans_total->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddTransactionWindow: public Ui_AddTransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONWINDOW_H
