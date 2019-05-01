/********************************************************************************
** Form generated from reading UI file 'model.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODEL_H
#define UI_MODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Model
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *spaceClearAllow;
    QSpacerItem *spacerViewWidget;
    QPushButton *clearButton;
    QTableView *tableView;
    QCheckBox *checkAllow;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Model)
    {
        if (Model->objectName().isEmpty())
            Model->setObjectName(QStringLiteral("Model"));
        Model->resize(636, 336);
        gridLayout = new QGridLayout(Model);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spaceClearAllow = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spaceClearAllow, 2, 1, 1, 1);

        spacerViewWidget = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerViewWidget, 0, 3, 1, 1);

        clearButton = new QPushButton(Model);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 2, 0, 1, 1);

        tableView = new QTableView(Model);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setIconSize(QSize(0, 0));
        tableView->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setProperty("showSortIndicator", QVariant(false));

        gridLayout->addWidget(tableView, 0, 0, 1, 3);

        checkAllow = new QCheckBox(Model);
        checkAllow->setObjectName(QStringLiteral("checkAllow"));

        gridLayout->addWidget(checkAllow, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);


        retranslateUi(Model);

        QMetaObject::connectSlotsByName(Model);
    } // setupUi

    void retranslateUi(QWidget *Model)
    {
        Model->setWindowTitle(QApplication::translate("Model", "Form", nullptr));
        clearButton->setText(QApplication::translate("Model", "Clear all", nullptr));
        checkAllow->setText(QApplication::translate("Model", "Allow howdy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Model: public Ui_Model {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODEL_H
