/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigForm
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaGroups;
    QGridLayout *gridLayout_2;
    QGridLayout *gridGroups;
    QGroupBox *debugGroup;
    QGridLayout *gridLayout_6;
    QLabel *labelEndReport;
    QComboBox *comboEndReport;
    QGroupBox *coreGroup;
    QGridLayout *gridLayout_4;
    QLabel *labelDetectionNotice;
    QComboBox *comboDetectionNotice;
    QLabel *labelIgnoreClosedLid;
    QComboBox *comboIgnoreClosedLid;
    QLabel *labelIgnoreSsh;
    QComboBox *comboIgnoreSsh;
    QLabel *labelNoConfirmation;
    QComboBox *comboNoConfirmation;
    QLabel *labelSuppressUknown;
    QComboBox *comboSuppressUnknown;
    QLabel *labelUseCnn;
    QComboBox *comboUseCnn;
    QGroupBox *videoGroup;
    QGridLayout *gridLayout_5;
    QLabel *labelFrameHeight;
    QLabel *labelCertainty;
    QSpinBox *spinDarkThreshold;
    QLabel *labelTimeout;
    QLabel *labelDarkThreshold;
    QComboBox *comboForceMjpeg;
    QLabel *labelExposure;
    QSpinBox *spinFrameWidth;
    QSpinBox *spinMaxHeight;
    QLabel *labelRecordingPlugin;
    QComboBox *comboRecordingPlugin;
    QLabel *labelDevicePath;
    QLabel *labelMaxHeight;
    QComboBox *comboDeviceFormat;
    QSpinBox *spinTimeout;
    QLabel *labelDeviceFormat;
    QSpinBox *spinExposure;
    QLabel *labelFrameWidth;
    QLabel *labelForceMjpeg;
    QSpinBox *spinFrameHeight;
    QDoubleSpinBox *spinCertainty;
    QPushButton *buttonDevicePath;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ConfigForm)
    {
        if (ConfigForm->objectName().isEmpty())
            ConfigForm->setObjectName(QStringLiteral("ConfigForm"));
        ConfigForm->resize(812, 854);
        gridLayout = new QGridLayout(ConfigForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(ConfigForm);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaGroups = new QWidget();
        scrollAreaGroups->setObjectName(QStringLiteral("scrollAreaGroups"));
        scrollAreaGroups->setGeometry(QRect(0, 0, 392, 834));
        gridLayout_2 = new QGridLayout(scrollAreaGroups);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridGroups = new QGridLayout();
        gridGroups->setObjectName(QStringLiteral("gridGroups"));
        gridGroups->setContentsMargins(-1, -1, 10, -1);
        debugGroup = new QGroupBox(scrollAreaGroups);
        debugGroup->setObjectName(QStringLiteral("debugGroup"));
        debugGroup->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(debugGroup);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        labelEndReport = new QLabel(debugGroup);
        labelEndReport->setObjectName(QStringLiteral("labelEndReport"));

        gridLayout_6->addWidget(labelEndReport, 0, 0, 1, 1);

        comboEndReport = new QComboBox(debugGroup);
        comboEndReport->addItem(QString());
        comboEndReport->addItem(QString());
        comboEndReport->setObjectName(QStringLiteral("comboEndReport"));

        gridLayout_6->addWidget(comboEndReport, 0, 1, 1, 1);


        gridGroups->addWidget(debugGroup, 2, 1, 1, 1);

        coreGroup = new QGroupBox(scrollAreaGroups);
        coreGroup->setObjectName(QStringLiteral("coreGroup"));
        coreGroup->setAlignment(Qt::AlignCenter);
        coreGroup->setFlat(false);
        coreGroup->setCheckable(false);
        gridLayout_4 = new QGridLayout(coreGroup);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        labelDetectionNotice = new QLabel(coreGroup);
        labelDetectionNotice->setObjectName(QStringLiteral("labelDetectionNotice"));

        gridLayout_4->addWidget(labelDetectionNotice, 0, 0, 1, 1);

        comboDetectionNotice = new QComboBox(coreGroup);
        comboDetectionNotice->addItem(QString());
        comboDetectionNotice->addItem(QString());
        comboDetectionNotice->setObjectName(QStringLiteral("comboDetectionNotice"));

        gridLayout_4->addWidget(comboDetectionNotice, 0, 1, 1, 1);

        labelIgnoreClosedLid = new QLabel(coreGroup);
        labelIgnoreClosedLid->setObjectName(QStringLiteral("labelIgnoreClosedLid"));

        gridLayout_4->addWidget(labelIgnoreClosedLid, 1, 0, 1, 1);

        comboIgnoreClosedLid = new QComboBox(coreGroup);
        comboIgnoreClosedLid->addItem(QString());
        comboIgnoreClosedLid->addItem(QString());
        comboIgnoreClosedLid->setObjectName(QStringLiteral("comboIgnoreClosedLid"));

        gridLayout_4->addWidget(comboIgnoreClosedLid, 1, 1, 1, 1);

        labelIgnoreSsh = new QLabel(coreGroup);
        labelIgnoreSsh->setObjectName(QStringLiteral("labelIgnoreSsh"));

        gridLayout_4->addWidget(labelIgnoreSsh, 2, 0, 1, 1);

        comboIgnoreSsh = new QComboBox(coreGroup);
        comboIgnoreSsh->addItem(QString());
        comboIgnoreSsh->addItem(QString());
        comboIgnoreSsh->setObjectName(QStringLiteral("comboIgnoreSsh"));

        gridLayout_4->addWidget(comboIgnoreSsh, 2, 1, 1, 1);

        labelNoConfirmation = new QLabel(coreGroup);
        labelNoConfirmation->setObjectName(QStringLiteral("labelNoConfirmation"));

        gridLayout_4->addWidget(labelNoConfirmation, 3, 0, 1, 1);

        comboNoConfirmation = new QComboBox(coreGroup);
        comboNoConfirmation->addItem(QString());
        comboNoConfirmation->addItem(QString());
        comboNoConfirmation->setObjectName(QStringLiteral("comboNoConfirmation"));

        gridLayout_4->addWidget(comboNoConfirmation, 3, 1, 1, 1);

        labelSuppressUknown = new QLabel(coreGroup);
        labelSuppressUknown->setObjectName(QStringLiteral("labelSuppressUknown"));

        gridLayout_4->addWidget(labelSuppressUknown, 4, 0, 1, 1);

        comboSuppressUnknown = new QComboBox(coreGroup);
        comboSuppressUnknown->addItem(QString());
        comboSuppressUnknown->addItem(QString());
        comboSuppressUnknown->setObjectName(QStringLiteral("comboSuppressUnknown"));

        gridLayout_4->addWidget(comboSuppressUnknown, 4, 1, 1, 1);

        labelUseCnn = new QLabel(coreGroup);
        labelUseCnn->setObjectName(QStringLiteral("labelUseCnn"));

        gridLayout_4->addWidget(labelUseCnn, 5, 0, 1, 1);

        comboUseCnn = new QComboBox(coreGroup);
        comboUseCnn->addItem(QString());
        comboUseCnn->addItem(QString());
        comboUseCnn->setObjectName(QStringLiteral("comboUseCnn"));

        gridLayout_4->addWidget(comboUseCnn, 5, 1, 1, 1);


        gridGroups->addWidget(coreGroup, 0, 1, 1, 1);

        videoGroup = new QGroupBox(scrollAreaGroups);
        videoGroup->setObjectName(QStringLiteral("videoGroup"));
        videoGroup->setAlignment(Qt::AlignCenter);
        gridLayout_5 = new QGridLayout(videoGroup);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        labelFrameHeight = new QLabel(videoGroup);
        labelFrameHeight->setObjectName(QStringLiteral("labelFrameHeight"));

        gridLayout_5->addWidget(labelFrameHeight, 6, 0, 1, 1);

        labelCertainty = new QLabel(videoGroup);
        labelCertainty->setObjectName(QStringLiteral("labelCertainty"));

        gridLayout_5->addWidget(labelCertainty, 0, 0, 1, 1);

        spinDarkThreshold = new QSpinBox(videoGroup);
        spinDarkThreshold->setObjectName(QStringLiteral("spinDarkThreshold"));

        gridLayout_5->addWidget(spinDarkThreshold, 1, 1, 1, 1);

        labelTimeout = new QLabel(videoGroup);
        labelTimeout->setObjectName(QStringLiteral("labelTimeout"));

        gridLayout_5->addWidget(labelTimeout, 10, 0, 1, 1);

        labelDarkThreshold = new QLabel(videoGroup);
        labelDarkThreshold->setObjectName(QStringLiteral("labelDarkThreshold"));

        gridLayout_5->addWidget(labelDarkThreshold, 1, 0, 1, 1);

        comboForceMjpeg = new QComboBox(videoGroup);
        comboForceMjpeg->addItem(QString());
        comboForceMjpeg->addItem(QString());
        comboForceMjpeg->setObjectName(QStringLiteral("comboForceMjpeg"));

        gridLayout_5->addWidget(comboForceMjpeg, 5, 1, 1, 1);

        labelExposure = new QLabel(videoGroup);
        labelExposure->setObjectName(QStringLiteral("labelExposure"));

        gridLayout_5->addWidget(labelExposure, 4, 0, 1, 1);

        spinFrameWidth = new QSpinBox(videoGroup);
        spinFrameWidth->setObjectName(QStringLiteral("spinFrameWidth"));
        spinFrameWidth->setMinimum(-1);

        gridLayout_5->addWidget(spinFrameWidth, 7, 1, 1, 1);

        spinMaxHeight = new QSpinBox(videoGroup);
        spinMaxHeight->setObjectName(QStringLiteral("spinMaxHeight"));
        spinMaxHeight->setMaximum(1000);

        gridLayout_5->addWidget(spinMaxHeight, 8, 1, 1, 1);

        labelRecordingPlugin = new QLabel(videoGroup);
        labelRecordingPlugin->setObjectName(QStringLiteral("labelRecordingPlugin"));

        gridLayout_5->addWidget(labelRecordingPlugin, 9, 0, 1, 1);

        comboRecordingPlugin = new QComboBox(videoGroup);
        comboRecordingPlugin->addItem(QString());
        comboRecordingPlugin->addItem(QString());
        comboRecordingPlugin->addItem(QString());
        comboRecordingPlugin->setObjectName(QStringLiteral("comboRecordingPlugin"));

        gridLayout_5->addWidget(comboRecordingPlugin, 9, 1, 1, 1);

        labelDevicePath = new QLabel(videoGroup);
        labelDevicePath->setObjectName(QStringLiteral("labelDevicePath"));

        gridLayout_5->addWidget(labelDevicePath, 3, 0, 1, 1);

        labelMaxHeight = new QLabel(videoGroup);
        labelMaxHeight->setObjectName(QStringLiteral("labelMaxHeight"));

        gridLayout_5->addWidget(labelMaxHeight, 8, 0, 1, 1);

        comboDeviceFormat = new QComboBox(videoGroup);
        comboDeviceFormat->addItem(QString());
        comboDeviceFormat->addItem(QString());
        comboDeviceFormat->setObjectName(QStringLiteral("comboDeviceFormat"));

        gridLayout_5->addWidget(comboDeviceFormat, 2, 1, 1, 1);

        spinTimeout = new QSpinBox(videoGroup);
        spinTimeout->setObjectName(QStringLiteral("spinTimeout"));

        gridLayout_5->addWidget(spinTimeout, 10, 1, 1, 1);

        labelDeviceFormat = new QLabel(videoGroup);
        labelDeviceFormat->setObjectName(QStringLiteral("labelDeviceFormat"));

        gridLayout_5->addWidget(labelDeviceFormat, 2, 0, 1, 1);

        spinExposure = new QSpinBox(videoGroup);
        spinExposure->setObjectName(QStringLiteral("spinExposure"));
        spinExposure->setMinimum(-1);

        gridLayout_5->addWidget(spinExposure, 4, 1, 1, 1);

        labelFrameWidth = new QLabel(videoGroup);
        labelFrameWidth->setObjectName(QStringLiteral("labelFrameWidth"));

        gridLayout_5->addWidget(labelFrameWidth, 7, 0, 1, 1);

        labelForceMjpeg = new QLabel(videoGroup);
        labelForceMjpeg->setObjectName(QStringLiteral("labelForceMjpeg"));

        gridLayout_5->addWidget(labelForceMjpeg, 5, 0, 1, 1);

        spinFrameHeight = new QSpinBox(videoGroup);
        spinFrameHeight->setObjectName(QStringLiteral("spinFrameHeight"));
        spinFrameHeight->setMinimum(-1);

        gridLayout_5->addWidget(spinFrameHeight, 6, 1, 1, 1);

        spinCertainty = new QDoubleSpinBox(videoGroup);
        spinCertainty->setObjectName(QStringLiteral("spinCertainty"));
        spinCertainty->setMinimum(1);
        spinCertainty->setMaximum(10);

        gridLayout_5->addWidget(spinCertainty, 0, 1, 1, 1);

        buttonDevicePath = new QPushButton(videoGroup);
        buttonDevicePath->setObjectName(QStringLiteral("buttonDevicePath"));

        gridLayout_5->addWidget(buttonDevicePath, 3, 1, 1, 1);


        gridGroups->addWidget(videoGroup, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridGroups, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaGroups);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);


        retranslateUi(ConfigForm);

        QMetaObject::connectSlotsByName(ConfigForm);
    } // setupUi

    void retranslateUi(QWidget *ConfigForm)
    {
        ConfigForm->setWindowTitle(QApplication::translate("ConfigForm", "Form", nullptr));
        debugGroup->setTitle(QApplication::translate("ConfigForm", "Debug", nullptr));
        labelEndReport->setText(QApplication::translate("ConfigForm", "End report", nullptr));
        comboEndReport->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboEndReport->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        coreGroup->setTitle(QApplication::translate("ConfigForm", "Core", nullptr));
        labelDetectionNotice->setText(QApplication::translate("ConfigForm", "Detection notice", nullptr));
        comboDetectionNotice->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboDetectionNotice->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelIgnoreClosedLid->setText(QApplication::translate("ConfigForm", "Ignore closed lid", nullptr));
        comboIgnoreClosedLid->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboIgnoreClosedLid->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelIgnoreSsh->setText(QApplication::translate("ConfigForm", "Ignore ssh", nullptr));
        comboIgnoreSsh->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboIgnoreSsh->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelNoConfirmation->setText(QApplication::translate("ConfigForm", "No confirmation", nullptr));
        comboNoConfirmation->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboNoConfirmation->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelSuppressUknown->setText(QApplication::translate("ConfigForm", "Suppress unknown", nullptr));
        comboSuppressUnknown->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboSuppressUnknown->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelUseCnn->setText(QApplication::translate("ConfigForm", "Use cnn", nullptr));
        comboUseCnn->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboUseCnn->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        videoGroup->setTitle(QApplication::translate("ConfigForm", "Video", nullptr));
        labelFrameHeight->setText(QApplication::translate("ConfigForm", "Frame height", nullptr));
        labelCertainty->setText(QApplication::translate("ConfigForm", "Certainty", nullptr));
        labelTimeout->setText(QApplication::translate("ConfigForm", "Timeout", nullptr));
        labelDarkThreshold->setText(QApplication::translate("ConfigForm", "Dark threshold", nullptr));
        comboForceMjpeg->setItemText(0, QApplication::translate("ConfigForm", "true", nullptr));
        comboForceMjpeg->setItemText(1, QApplication::translate("ConfigForm", "false", nullptr));

        labelExposure->setText(QApplication::translate("ConfigForm", "Exposure", nullptr));
        labelRecordingPlugin->setText(QApplication::translate("ConfigForm", "Recording plugin", nullptr));
        comboRecordingPlugin->setItemText(0, QApplication::translate("ConfigForm", "opencv", nullptr));
        comboRecordingPlugin->setItemText(1, QApplication::translate("ConfigForm", "ffmpeg", nullptr));
        comboRecordingPlugin->setItemText(2, QApplication::translate("ConfigForm", "pyv4l2", nullptr));

        labelDevicePath->setText(QApplication::translate("ConfigForm", "Device path", nullptr));
        labelMaxHeight->setText(QApplication::translate("ConfigForm", "Max height", nullptr));
        comboDeviceFormat->setItemText(0, QApplication::translate("ConfigForm", "v4l2", nullptr));
        comboDeviceFormat->setItemText(1, QApplication::translate("ConfigForm", "vfwcap", nullptr));

        labelDeviceFormat->setText(QApplication::translate("ConfigForm", "Device format", nullptr));
        labelFrameWidth->setText(QApplication::translate("ConfigForm", "Frame width", nullptr));
        labelForceMjpeg->setText(QApplication::translate("ConfigForm", "Force mjpeg", nullptr));
        buttonDevicePath->setText(QApplication::translate("ConfigForm", "Choose path", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigForm: public Ui_ConfigForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
