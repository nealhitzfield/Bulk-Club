/********************************************************************************
** Form generated from reading UI file 'smwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMWINDOW_H
#define UI_SMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SMWindow
{
public:

    void setupUi(QDialog *SMWindow)
    {
        if (SMWindow->objectName().isEmpty())
            SMWindow->setObjectName(QStringLiteral("SMWindow"));
        SMWindow->resize(400, 300);

        retranslateUi(SMWindow);

        QMetaObject::connectSlotsByName(SMWindow);
    } // setupUi

    void retranslateUi(QDialog *SMWindow)
    {
        SMWindow->setWindowTitle(QApplication::translate("SMWindow", "Store Manager Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SMWindow: public Ui_SMWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMWINDOW_H
