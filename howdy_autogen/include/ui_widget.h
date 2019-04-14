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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *Model;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *enableButton;
    QPushButton *clearButton;
    QPushButton *disableButton;
    QWidget *Add;
    QTextEdit *textEdit;
    QPushButton *addButton;
    QWidget *Config;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelDetectionNotice;
    QComboBox *comboDetectionNotice;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelNoConfirmation;
    QComboBox *comboNoConfirmation;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelSuppressUnknown;
    QComboBox *comboSuppressUnknown;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelIgnoreSsh;
    QComboBox *comboIgnoreSsh;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelIgnoreClosedLid;
    QComboBox *comboIgnoreClosedLid;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelUseCnn;
    QComboBox *comboUseCnn;
    QPushButton *buttonSave;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(584, 346);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 521, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        Model = new QWidget();
        Model->setObjectName(QStringLiteral("Model"));
        verticalLayoutWidget_3 = new QWidget(Model);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(-10, 0, 511, 231));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget_3);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_3->addWidget(tableView);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        enableButton = new QPushButton(verticalLayoutWidget_3);
        enableButton->setObjectName(QStringLiteral("enableButton"));

        horizontalLayout_8->addWidget(enableButton);

        clearButton = new QPushButton(verticalLayoutWidget_3);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout_8->addWidget(clearButton);

        disableButton = new QPushButton(verticalLayoutWidget_3);
        disableButton->setObjectName(QStringLiteral("disableButton"));

        horizontalLayout_8->addWidget(disableButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

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
        verticalLayoutWidget_2 = new QWidget(Config);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(20, 10, 451, 231));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelDetectionNotice = new QLabel(verticalLayoutWidget_2);
        labelDetectionNotice->setObjectName(QStringLiteral("labelDetectionNotice"));

        horizontalLayout_2->addWidget(labelDetectionNotice);

        comboDetectionNotice = new QComboBox(verticalLayoutWidget_2);
        comboDetectionNotice->addItem(QString());
        comboDetectionNotice->addItem(QString());
        comboDetectionNotice->setObjectName(QStringLiteral("comboDetectionNotice"));

        horizontalLayout_2->addWidget(comboDetectionNotice);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelNoConfirmation = new QLabel(verticalLayoutWidget_2);
        labelNoConfirmation->setObjectName(QStringLiteral("labelNoConfirmation"));

        horizontalLayout_3->addWidget(labelNoConfirmation);

        comboNoConfirmation = new QComboBox(verticalLayoutWidget_2);
        comboNoConfirmation->addItem(QString());
        comboNoConfirmation->addItem(QString());
        comboNoConfirmation->setObjectName(QStringLiteral("comboNoConfirmation"));

        horizontalLayout_3->addWidget(comboNoConfirmation);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelSuppressUnknown = new QLabel(verticalLayoutWidget_2);
        labelSuppressUnknown->setObjectName(QStringLiteral("labelSuppressUnknown"));

        horizontalLayout_4->addWidget(labelSuppressUnknown);

        comboSuppressUnknown = new QComboBox(verticalLayoutWidget_2);
        comboSuppressUnknown->addItem(QString());
        comboSuppressUnknown->addItem(QString());
        comboSuppressUnknown->setObjectName(QStringLiteral("comboSuppressUnknown"));

        horizontalLayout_4->addWidget(comboSuppressUnknown);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelIgnoreSsh = new QLabel(verticalLayoutWidget_2);
        labelIgnoreSsh->setObjectName(QStringLiteral("labelIgnoreSsh"));

        horizontalLayout_5->addWidget(labelIgnoreSsh);

        comboIgnoreSsh = new QComboBox(verticalLayoutWidget_2);
        comboIgnoreSsh->addItem(QString());
        comboIgnoreSsh->addItem(QString());
        comboIgnoreSsh->setObjectName(QStringLiteral("comboIgnoreSsh"));

        horizontalLayout_5->addWidget(comboIgnoreSsh);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelIgnoreClosedLid = new QLabel(verticalLayoutWidget_2);
        labelIgnoreClosedLid->setObjectName(QStringLiteral("labelIgnoreClosedLid"));

        horizontalLayout_6->addWidget(labelIgnoreClosedLid);

        comboIgnoreClosedLid = new QComboBox(verticalLayoutWidget_2);
        comboIgnoreClosedLid->addItem(QString());
        comboIgnoreClosedLid->addItem(QString());
        comboIgnoreClosedLid->setObjectName(QStringLiteral("comboIgnoreClosedLid"));

        horizontalLayout_6->addWidget(comboIgnoreClosedLid);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelUseCnn = new QLabel(verticalLayoutWidget_2);
        labelUseCnn->setObjectName(QStringLiteral("labelUseCnn"));

        horizontalLayout_7->addWidget(labelUseCnn);

        comboUseCnn = new QComboBox(verticalLayoutWidget_2);
        comboUseCnn->addItem(QString());
        comboUseCnn->addItem(QString());
        comboUseCnn->setObjectName(QStringLiteral("comboUseCnn"));

        horizontalLayout_7->addWidget(comboUseCnn);


        verticalLayout_2->addLayout(horizontalLayout_7);

        tabWidget->addTab(Config, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout->addLayout(horizontalLayout);

        buttonSave = new QPushButton(Widget);
        buttonSave->setObjectName(QStringLiteral("buttonSave"));
        buttonSave->setGeometry(QRect(420, 290, 80, 23));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Form", nullptr));
        enableButton->setText(QApplication::translate("Widget", "enable", nullptr));
        clearButton->setText(QApplication::translate("Widget", "clear", nullptr));
        disableButton->setText(QApplication::translate("Widget", "disable", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Model), QApplication::translate("Widget", "Model", nullptr));
        addButton->setText(QApplication::translate("Widget", "add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Add), QApplication::translate("Widget", "Add", nullptr));
        labelDetectionNotice->setText(QApplication::translate("Widget", "Detection notice", nullptr));
        comboDetectionNotice->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboDetectionNotice->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        labelNoConfirmation->setText(QApplication::translate("Widget", "No confirmation", nullptr));
        comboNoConfirmation->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboNoConfirmation->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        labelSuppressUnknown->setText(QApplication::translate("Widget", "Suppress unknown", nullptr));
        comboSuppressUnknown->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboSuppressUnknown->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        labelIgnoreSsh->setText(QApplication::translate("Widget", "Ignore ssh", nullptr));
        comboIgnoreSsh->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboIgnoreSsh->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        labelIgnoreClosedLid->setText(QApplication::translate("Widget", "Ignore closed lid", nullptr));
        comboIgnoreClosedLid->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboIgnoreClosedLid->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        labelUseCnn->setText(QApplication::translate("Widget", "Use cnn", nullptr));
        comboUseCnn->setItemText(0, QApplication::translate("Widget", "true", nullptr));
        comboUseCnn->setItemText(1, QApplication::translate("Widget", "false", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(Config), QApplication::translate("Widget", "Config", nullptr));
        buttonSave->setText(QApplication::translate("Widget", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
