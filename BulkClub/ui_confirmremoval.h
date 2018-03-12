/********************************************************************************
** Form generated from reading UI file 'confirmremoval.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfirmRemoval
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *ConfirmRemoval)
    {
        if (ConfirmRemoval->objectName().isEmpty())
            ConfirmRemoval->setObjectName(QStringLiteral("ConfirmRemoval"));
        ConfirmRemoval->resize(626, 196);
        horizontalLayout_2 = new QHBoxLayout(ConfirmRemoval);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ConfirmRemoval);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableView = new QTableView(ConfirmRemoval);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        confirmButton = new QPushButton(ConfirmRemoval);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));
        confirmButton->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(ConfirmRemoval);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMaximumSize(QSize(72, 16777215));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(ConfirmRemoval);

        QMetaObject::connectSlotsByName(ConfirmRemoval);
    } // setupUi

    void retranslateUi(QDialog *ConfirmRemoval)
    {
        ConfirmRemoval->setWindowTitle(QApplication::translate("ConfirmRemoval", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("ConfirmRemoval", "Are you sure you want to remove the following?", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("ConfirmRemoval", "Confirm", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("ConfirmRemoval", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfirmRemoval: public Ui_ConfirmRemoval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMREMOVAL_H
