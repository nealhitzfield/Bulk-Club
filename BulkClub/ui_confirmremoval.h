/********************************************************************************
** Form generated from reading UI file 'confirmremoval.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMREMOVAL_H
#define UI_CONFIRMREMOVAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_ConfirmRemoval
{
public:
    QTableView *tableView;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
    QLabel *label;

    void setupUi(QDialog *ConfirmRemoval)
    {
        if (ConfirmRemoval->objectName().isEmpty())
            ConfirmRemoval->setObjectName(QStringLiteral("ConfirmRemoval"));
        ConfirmRemoval->resize(400, 196);
        tableView = new QTableView(ConfirmRemoval);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 40, 380, 91));
        confirmButton = new QPushButton(ConfirmRemoval);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setGeometry(QRect(70, 140, 72, 23));
        cancelButton = new QPushButton(ConfirmRemoval);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(260, 140, 72, 23));
        label = new QLabel(ConfirmRemoval);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 9, 380, 31));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(ConfirmRemoval);

        QMetaObject::connectSlotsByName(ConfirmRemoval);
    } // setupUi

    void retranslateUi(QDialog *ConfirmRemoval)
    {
        ConfirmRemoval->setWindowTitle(QApplication::translate("ConfirmRemoval", "Dialog", nullptr));
        confirmButton->setText(QApplication::translate("ConfirmRemoval", "Confirm", nullptr));
        cancelButton->setText(QApplication::translate("ConfirmRemoval", "Cancel", nullptr));
        label->setText(QApplication::translate("ConfirmRemoval", "Are you sure you want to remove the following?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmRemoval: public Ui_ConfirmRemoval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMREMOVAL_H
