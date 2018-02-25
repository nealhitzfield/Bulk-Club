/********************************************************************************
** Form generated from reading UI file 'addtransactionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANSACTIONWINDOW_H
#define UI_ADDTRANSACTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDateEdit *dateEdit;

    void setupUi(QDialog *AddTransactionWindow)
    {
        if (AddTransactionWindow->objectName().isEmpty())
            AddTransactionWindow->setObjectName(QStringLiteral("AddTransactionWindow"));
        AddTransactionWindow->resize(400, 300);
        widget = new QWidget(AddTransactionWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 30, 100, 50));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        verticalLayout->addWidget(dateEdit);


        retranslateUi(AddTransactionWindow);

        QMetaObject::connectSlotsByName(AddTransactionWindow);
    } // setupUi

    void retranslateUi(QDialog *AddTransactionWindow)
    {
        AddTransactionWindow->setWindowTitle(QApplication::translate("AddTransactionWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("AddTransactionWindow", "Transaction Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTransactionWindow: public Ui_AddTransactionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTRANSACTIONWINDOW_H
