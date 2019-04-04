/********************************************************************************
** Form generated from reading UI file 'module.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULE_H
#define UI_MODULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_module
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *module)
    {
        if (module->objectName().isEmpty())
            module->setObjectName(QStringLiteral("module"));
        module->resize(400, 300);
        pushButton = new QPushButton(module);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 80, 80, 23));
        pushButton_2 = new QPushButton(module);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 120, 80, 23));
        pushButton_3 = new QPushButton(module);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 160, 80, 23));
        pushButton_4 = new QPushButton(module);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 200, 80, 23));

        retranslateUi(module);

        QMetaObject::connectSlotsByName(module);
    } // setupUi

    void retranslateUi(QWidget *module)
    {
        module->setWindowTitle(QApplication::translate("module", "Form", nullptr));
        pushButton->setText(QApplication::translate("module", "PushButton", nullptr));
        pushButton_2->setText(QApplication::translate("module", "PushButton", nullptr));
        pushButton_3->setText(QApplication::translate("module", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("module", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class module: public Ui_module {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_H
