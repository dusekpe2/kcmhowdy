/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *Model;
    QWidget *Add;
    QTextEdit *textEdit;
    QPushButton *addButton;
    QWidget *Config;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(782, 459);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Model = new QWidget();
        Model->setObjectName(QStringLiteral("Model"));
        tabWidget->addTab(Model, QString());
        Add = new QWidget();
        Add->setObjectName(QStringLiteral("Add"));
        textEdit = new QTextEdit(Add);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 10, 341, 21));
        addButton = new QPushButton(Add);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(30, 50, 95, 23));
        tabWidget->addTab(Add, QString());
        Config = new QWidget();
        Config->setObjectName(QStringLiteral("Config"));
        tabWidget->addTab(Config, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Model), QApplication::translate("Widget", "Model", nullptr));
        addButton->setText(QApplication::translate("Widget", "add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Add), QApplication::translate("Widget", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Config), QApplication::translate("Widget", "Config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
