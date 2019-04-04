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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_module
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *clearButton;
    QPushButton *configButton;
    QPushButton *disableButton;
    QPushButton *enableButton;

    void setupUi(QWidget *module)
    {
        if (module->objectName().isEmpty())
            module->setObjectName(QStringLiteral("module"));
        module->resize(436, 315);
        verticalLayoutWidget = new QWidget(module);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 428, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        configButton = new QPushButton(verticalLayoutWidget);
        configButton->setObjectName(QStringLiteral("configButton"));

        horizontalLayout->addWidget(configButton);

        disableButton = new QPushButton(verticalLayoutWidget);
        disableButton->setObjectName(QStringLiteral("disableButton"));

        horizontalLayout->addWidget(disableButton);

        enableButton = new QPushButton(verticalLayoutWidget);
        enableButton->setObjectName(QStringLiteral("enableButton"));

        horizontalLayout->addWidget(enableButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(module);

        QMetaObject::connectSlotsByName(module);
    } // setupUi

    void retranslateUi(QWidget *module)
    {
        module->setWindowTitle(QApplication::translate("module", "Form", nullptr));
        addButton->setText(QApplication::translate("module", "add", nullptr));
        clearButton->setText(QApplication::translate("module", "clear", nullptr));
        configButton->setText(QApplication::translate("module", "config", nullptr));
        disableButton->setText(QApplication::translate("module", "disable", nullptr));
        enableButton->setText(QApplication::translate("module", "enable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class module: public Ui_module {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULE_H
