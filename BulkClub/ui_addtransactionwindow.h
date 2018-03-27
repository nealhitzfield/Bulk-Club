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

QT_BEGIN_NAMESPACE

class Ui_AddTransactionWindow
{
public:
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
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
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_item_price;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *qty_purchased;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_subtotal;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_tax;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLabel *label_trans_total;

    void setupUi(QDialog *AddTransactionWindow)
    {
        if (AddTransactionWindow->objectName().isEmpty())
            AddTransactionWindow->setObjectName(QStringLiteral("AddTransactionWindow"));
        AddTransactionWindow->resize(296, 304);
        horizontalLayout_5 = new QHBoxLayout(AddTransactionWindow);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dateLabel = new QLabel(AddTransactionWindow);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));

        gridLayout->addWidget(dateLabel, 0, 0, 1, 1);

        purchaseDate = new QDateEdit(AddTransactionWindow);
        purchaseDate->setObjectName(QStringLiteral("purchaseDate"));
        purchaseDate->setButtonSymbols(QAbstractSpinBox::NoButtons);

        gridLayout->addWidget(purchaseDate, 0, 1, 1, 2);

        itemLabel = new QLabel(AddTransactionWindow);
        itemLabel->setObjectName(QStringLiteral("itemLabel"));

        gridLayout->addWidget(itemLabel, 1, 0, 1, 1);

        comboBox = new QComboBox(AddTransactionWindow);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 2);

        quantityLabel = new QLabel(AddTransactionWindow);
        quantityLabel->setObjectName(QStringLiteral("quantityLabel"));

        gridLayout->addWidget(quantityLabel, 2, 0, 1, 1);

        purchaseQuantity = new QSpinBox(AddTransactionWindow);
        purchaseQuantity->setObjectName(QStringLiteral("purchaseQuantity"));
        purchaseQuantity->setButtonSymbols(QAbstractSpinBox::NoButtons);
        purchaseQuantity->setMaximum(9999);

        gridLayout->addWidget(purchaseQuantity, 2, 1, 1, 1);

        purchaseAddButton = new QPushButton(AddTransactionWindow);
        purchaseAddButton->setObjectName(QStringLiteral("purchaseAddButton"));

        gridLayout->addWidget(purchaseAddButton, 3, 0, 1, 2);

        purchaseCancelButton = new QPushButton(AddTransactionWindow);
        purchaseCancelButton->setObjectName(QStringLiteral("purchaseCancelButton"));

        gridLayout->addWidget(purchaseCancelButton, 3, 2, 1, 1);

        label_status = new QLabel(AddTransactionWindow);
        label_status->setObjectName(QStringLiteral("label_status"));

        gridLayout->addWidget(label_status, 4, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(AddTransactionWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_item_price = new QLabel(AddTransactionWindow);
        label_item_price->setObjectName(QStringLiteral("label_item_price"));

        verticalLayout->addWidget(label_item_price);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(AddTransactionWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        qty_purchased = new QLabel(AddTransactionWindow);
        qty_purchased->setObjectName(QStringLiteral("qty_purchased"));

        verticalLayout_3->addWidget(qty_purchased);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(AddTransactionWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(91, 0));

        horizontalLayout_2->addWidget(label_3);

        label_subtotal = new QLabel(AddTransactionWindow);
        label_subtotal->setObjectName(QStringLiteral("label_subtotal"));

        horizontalLayout_2->addWidget(label_subtotal);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(AddTransactionWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(91, 0));

        horizontalLayout_3->addWidget(label_4);

        label_tax = new QLabel(AddTransactionWindow);
        label_tax->setObjectName(QStringLiteral("label_tax"));

        horizontalLayout_3->addWidget(label_tax);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(AddTransactionWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(91, 0));

        horizontalLayout_4->addWidget(label_5);

        label_trans_total = new QLabel(AddTransactionWindow);
        label_trans_total->setObjectName(QStringLiteral("label_trans_total"));

        horizontalLayout_4->addWidget(label_trans_total);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_5);


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
        label_2->setText(QApplication::translate("AddTransactionWindow", "Qty", nullptr));
        qty_purchased->setText(QString());
        label_3->setText(QApplication::translate("AddTransactionWindow", "Subtotal", nullptr));
        label_subtotal->setText(QString());
        label_4->setText(QApplication::translate("AddTransactionWindow", "Tax", nullptr));
        label_tax->setText(QString());
        label_5->setText(QApplication::translate("AddTransactionWindow", "Transaction Total", nullptr));
        label_trans_total->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddTransactionWindow: public Ui_AddTransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONWINDOW_H
