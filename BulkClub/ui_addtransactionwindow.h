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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionWindow
{
public:
    QWidget *widget;
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

    void setupUi(QDialog *AddTransactionWindow)
    {
        if (AddTransactionWindow->objectName().isEmpty())
            AddTransactionWindow->setObjectName(QStringLiteral("AddTransactionWindow"));
        AddTransactionWindow->resize(400, 300);
        widget = new QWidget(AddTransactionWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(56, 61, 180, 122));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
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
    } // retranslateUi

};

namespace Ui {
    class AddTransactionWindow: public Ui_AddTransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONWINDOW_H
