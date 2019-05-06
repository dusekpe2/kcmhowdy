/********************************************************************************
** Form generated from reading UI file 'modelwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELWIDGET_H
#define UI_MODELWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *clearButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *spaceClearAllow;
    QSpacerItem *spacerViewWidget;
    QCheckBox *checkAllow;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ModelWidget)
    {
        if (ModelWidget->objectName().isEmpty())
            ModelWidget->setObjectName(QStringLiteral("ModelWidget"));
        ModelWidget->resize(622, 337);
        gridLayout = new QGridLayout(ModelWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        clearButton = new QPushButton(ModelWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        gridLayout->addWidget(clearButton, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        spaceClearAllow = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spaceClearAllow, 2, 1, 1, 1);

        spacerViewWidget = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerViewWidget, 0, 3, 1, 1);

        checkAllow = new QCheckBox(ModelWidget);
        checkAllow->setObjectName(QStringLiteral("checkAllow"));

        gridLayout->addWidget(checkAllow, 2, 2, 1, 1);

        tableWidget = new QTableWidget(ModelWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 3);


        retranslateUi(ModelWidget);

        QMetaObject::connectSlotsByName(ModelWidget);
    } // setupUi

    void retranslateUi(QWidget *ModelWidget)
    {
        ModelWidget->setWindowTitle(QApplication::translate("ModelWidget", "Form", nullptr));
        clearButton->setText(QApplication::translate("ModelWidget", "Clear all", nullptr));
        checkAllow->setText(QApplication::translate("ModelWidget", "Allow howdy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelWidget: public Ui_ModelWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELWIDGET_H
