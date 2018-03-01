/********************************************************************************
** Form generated from reading UI file 'additemwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITEMWINDOW_H
#define UI_ADDITEMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_additemwindow
{
public:
    QPushButton *addButton;
    QLabel *outputLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *itemName;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *itemPrice;

    void setupUi(QDialog *additemwindow)
    {
        if (additemwindow->objectName().isEmpty())
            additemwindow->setObjectName(QStringLiteral("additemwindow"));
        additemwindow->resize(400, 300);
        addButton = new QPushButton(additemwindow);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(100, 60, 101, 31));
        outputLabel = new QLabel(additemwindow);
        outputLabel->setObjectName(QStringLiteral("outputLabel"));
        outputLabel->setGeometry(QRect(110, 100, 81, 21));
        widget = new QWidget(additemwindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 131, 41));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        itemName = new QLineEdit(widget);
        itemName->setObjectName(QStringLiteral("itemName"));

        verticalLayout->addWidget(itemName);

        widget1 = new QWidget(additemwindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(180, 10, 70, 40));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        itemPrice = new QDoubleSpinBox(widget1);
        itemPrice->setObjectName(QStringLiteral("itemPrice"));
        itemPrice->setButtonSymbols(QAbstractSpinBox::NoButtons);
        itemPrice->setMaximum(9999);

        verticalLayout_2->addWidget(itemPrice);


        retranslateUi(additemwindow);

        QMetaObject::connectSlotsByName(additemwindow);
    } // setupUi

    void retranslateUi(QDialog *additemwindow)
    {
        additemwindow->setWindowTitle(QApplication::translate("additemwindow", "Dialog", nullptr));
        addButton->setText(QApplication::translate("additemwindow", "Add Item", nullptr));
        outputLabel->setText(QString());
        label->setText(QApplication::translate("additemwindow", "Item Name", nullptr));
        label_2->setText(QApplication::translate("additemwindow", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class additemwindow: public Ui_additemwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITEMWINDOW_H
