/********************************************************************************
** Form generated from reading UI file 'addmemberwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMEMBERWINDOW_H
#define UI_ADDMEMBERWINDOW_H

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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMemberWindow
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QComboBox *mTypes;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QDateEdit *expiration_date;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_mName;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSpinBox *mID;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *addButton;
    QLabel *label_status;
    QSplitter *splitter;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QDialog *AddMemberWindow)
    {
        if (AddMemberWindow->objectName().isEmpty())
            AddMemberWindow->setObjectName(QStringLiteral("AddMemberWindow"));
        AddMemberWindow->resize(416, 150);
        widget = new QWidget(AddMemberWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(11, 80, 271, 43));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        mTypes = new QComboBox(widget);
        mTypes->setObjectName(QStringLiteral("mTypes"));

        verticalLayout_3->addWidget(mTypes);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);

        expiration_date = new QDateEdit(widget);
        expiration_date->setObjectName(QStringLiteral("expiration_date"));

        verticalLayout_4->addWidget(expiration_date);


        horizontalLayout_2->addLayout(verticalLayout_4);

        widget1 = new QWidget(AddMemberWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(10, 20, 135, 41));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEdit_mName = new QLineEdit(widget1);
        lineEdit_mName->setObjectName(QStringLiteral("lineEdit_mName"));
        lineEdit_mName->setReadOnly(false);

        verticalLayout->addWidget(lineEdit_mName);

        widget2 = new QWidget(AddMemberWindow);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(150, 20, 130, 41));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        mID = new QSpinBox(widget2);
        mID->setObjectName(QStringLiteral("mID"));
        mID->setButtonSymbols(QAbstractSpinBox::NoButtons);
        mID->setMinimum(10000);
        mID->setMaximum(99999);

        verticalLayout_2->addWidget(mID);

        widget3 = new QWidget(AddMemberWindow);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(290, 20, 120, 61));
        verticalLayout_5 = new QVBoxLayout(widget3);
        verticalLayout_5->setSpacing(5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(widget3);
        addButton->setObjectName(QStringLiteral("addButton"));

        verticalLayout_5->addWidget(addButton);

        label_status = new QLabel(widget3);
        label_status->setObjectName(QStringLiteral("label_status"));
        label_status->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_status);

        splitter = new QSplitter(AddMemberWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(300, 100, 100, 23));
        splitter->setOrientation(Qt::Horizontal);
        yesButton = new QPushButton(splitter);
        yesButton->setObjectName(QStringLiteral("yesButton"));
        splitter->addWidget(yesButton);
        noButton = new QPushButton(splitter);
        noButton->setObjectName(QStringLiteral("noButton"));
        splitter->addWidget(noButton);

        retranslateUi(AddMemberWindow);

        QMetaObject::connectSlotsByName(AddMemberWindow);
    } // setupUi

    void retranslateUi(QDialog *AddMemberWindow)
    {
        AddMemberWindow->setWindowTitle(QApplication::translate("AddMemberWindow", "Dialog", nullptr));
        label_3->setText(QApplication::translate("AddMemberWindow", "Membership Type", nullptr));
        label_4->setText(QApplication::translate("AddMemberWindow", "Member Expiration Date", nullptr));
        label->setText(QApplication::translate("AddMemberWindow", "Member Name", nullptr));
        label_2->setText(QApplication::translate("AddMemberWindow", "Member ID", nullptr));
        addButton->setText(QApplication::translate("AddMemberWindow", "Add Member", nullptr));
        label_status->setText(QString());
        yesButton->setText(QApplication::translate("AddMemberWindow", "Yes", nullptr));
        noButton->setText(QApplication::translate("AddMemberWindow", "No", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMemberWindow: public Ui_AddMemberWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMEMBERWINDOW_H
