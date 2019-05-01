#include "config.h"
#include "ui_config.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QFileDialog>
#include <QDebug>
#include <KAuth>

Config::Config(QWidget *parent) : QWidget(parent), ui(new Ui::ConfigForm)
{
    ui->setupUi(this);
    config = KSharedConfig::openConfig(INI_FILE);

    coreGroup = KConfigGroup(config, CORE);
    videoGroup = KConfigGroup(config, VIDEO);
    debugGroup = KConfigGroup(config, DEBUG);

    connect(ui->comboDetectionNotice, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboIgnoreClosedLid, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboIgnoreSsh, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboNoConfirmation, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboSuppressUnknown, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboUseCnn, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));

    connect(ui->spinCertainty, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(ui->spinDarkThreshold, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
     connect(ui->comboDeviceFormat, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->buttonDevicePath, SIGNAL(clicked()), this, SLOT(chooseButtonClicked()));
    connect(ui->spinExposure, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->comboForceMjpeg, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->spinFrameHeight, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinFrameWidth, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinMaxHeight, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
     connect(ui->comboRecordingPlugin, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->spinTimeout, SIGNAL(valueChanged(int)), this, SLOT(save()));

     connect(ui->comboEndReport, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
}

Config::~Config()
{

}

void Config::load()
{

    ui->comboDetectionNotice->setCurrentText(coreGroup.readEntry(DETECTION_NOTICE, QString()));
    ui->comboIgnoreClosedLid->setCurrentText(coreGroup.readEntry(IGNORE_CLOSED_LID, QString()));
    ui->comboIgnoreSsh->setCurrentText(coreGroup.readEntry(IGNORE_SSH, QString()));
    ui->comboNoConfirmation->setCurrentText(coreGroup.readEntry(NO_CONFIRMATION, QString()));
    ui->comboSuppressUnknown->setCurrentText(coreGroup.readEntry(SUPPRESS_UNKNOWN, QString()));
    ui->comboUseCnn->setCurrentText(coreGroup.readEntry(USE_CNN, QString()));

    ui->spinCertainty->setValue(videoGroup.readEntry(CERTAINTY, double()));
    ui->spinDarkThreshold->setValue(videoGroup.readEntry(DARK_THRESHOLD, int()));
    mDeviceUrl =  videoGroup.readEntry(DEVICE_PATH, QString());
    ui->comboDeviceFormat->setCurrentText(videoGroup.readEntry(DEVICE_FORMAT, QString()));
    ui->spinExposure->setValue(videoGroup.readEntry(EXPOSURE, int()));
    ui->comboForceMjpeg->setCurrentText(videoGroup.readEntry(FORCE_MJPEG, QString()));
    ui->spinFrameHeight->setValue(videoGroup.readEntry(FRAME_HEIGHT, int()));
    ui->spinFrameWidth->setValue(videoGroup.readEntry(FRAME_WIDTH, int()));
    ui->spinMaxHeight->setValue(videoGroup.readEntry(MAX_HEIGHT, int()));
    ui->comboRecordingPlugin->setCurrentText(videoGroup.readEntry(RECORDING_PLUGIN, QString()));
    ui->spinTimeout->setValue(videoGroup.readEntry(TIMEOUT, int()));

    ui->comboEndReport->setCurrentText(debugGroup.readEntry(END_REPORT, QString()));
}

void Config::chooseButtonClicked()
{
    QFileDialog dialog;
        dialog.selectFile(videoGroup.readEntry(DEVICE_PATH, QString()));
        dialog.setFileMode(QFileDialog::AnyFile);
        if(dialog.exec()) {
            QStringList selected = dialog.selectedFiles();

            QString firstSelected = dialog.selectedFiles().at(0);

            if(firstSelected != mDeviceUrl)
            {
                mDeviceUrl = dialog.selectedFiles().at(0);
                hasChanged();
            }

        }
}

void Config::save()
{

    if(config->isConfigWritable(true)){
        coreGroup.writeEntry(DETECTION_NOTICE,ui->comboDetectionNotice->currentText());
        coreGroup.writeEntry(IGNORE_CLOSED_LID, ui->comboIgnoreClosedLid->currentText());
        coreGroup.writeEntry(IGNORE_SSH, ui->comboIgnoreSsh->currentText());
        coreGroup.writeEntry(NO_CONFIRMATION, ui->comboNoConfirmation->currentText());
        coreGroup.writeEntry(SUPPRESS_UNKNOWN, ui->comboSuppressUnknown->currentText());
        coreGroup.writeEntry(USE_CNN, ui->comboUseCnn->currentText());

        videoGroup.writeEntry(CERTAINTY, QString::number(ui->spinCertainty->value()));
        videoGroup.writeEntry(DARK_THRESHOLD, QString::number(ui->spinDarkThreshold->value()));
        videoGroup.writeEntry(DEVICE_FORMAT, ui->comboDeviceFormat->currentText());
        videoGroup.writeEntry(DEVICE_PATH, mDeviceUrl);
        videoGroup.writeEntry(EXPOSURE,QString::number(ui->spinExposure->value()));
        videoGroup.writeEntry(FORCE_MJPEG, ui->comboForceMjpeg->currentText());
        videoGroup.writeEntry(FRAME_HEIGHT, QString::number(ui->spinFrameHeight->value()));
        videoGroup.writeEntry(FRAME_WIDTH, QString::number(ui->spinFrameWidth->value()));
        videoGroup.writeEntry(MAX_HEIGHT, QString::number(ui->spinMaxHeight->value()));
        videoGroup.writeEntry(RECORDING_PLUGIN, ui->comboRecordingPlugin->currentText());
        videoGroup.writeEntry(TIMEOUT, QString::number(ui->spinTimeout->value()));

        debugGroup.writeEntry(END_REPORT, ui->comboEndReport->currentText());

        config->sync();
    }

}

void Config::hasChanged()
{
    Q_EMIT changed(true);
}

