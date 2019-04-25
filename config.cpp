#include "config.h"
#include "ui_config.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <iostream>

Config::Config(QWidget *parent) : QWidget(parent), ui(new Ui::ConfigForm)
{
    ui->setupUi(this);

    ui->comboDetectionNotice->setCurrentText(getValue(CORE, DETECTION_NOTICE));
    ui->comboIgnoreClosedLid->setCurrentText(getValue(CORE, IGNORE_CLOSED_LID));
    ui->comboIgnoreSsh->setCurrentText(getValue(CORE, IGNORE_SSH));
    ui->comboNoConfirmation->setCurrentText(getValue(CORE, NO_CONFIRMATION));
    ui->comboSuppressUnknown->setCurrentText(getValue(CORE, SUPPRESS_UNKNOWN));
    ui->comboUseCnn->setCurrentText(getValue(CORE, USE_CNN));

    ui->spinCertainty->setValue(getValue(VIDEO, CERTAINTY).toDouble());
    ui->spinDarkThreshold->setValue(getValue(VIDEO, DARK_THRESHOLD).toInt());
    ui->spinExposure->setValue(getValue(VIDEO, EXPOSURE).toInt());
    ui->comboForceMjpeg->setCurrentText(getValue(VIDEO, FORCE_MJPEG));
    ui->spinFrameHeight->setValue(getValue(VIDEO, FRAME_HEIGHT).toInt());
    ui->spinFrameWidth->setValue(getValue(VIDEO, FRAME_WIDTH).toInt());
    ui->spinMaxHeight->setValue(getValue(VIDEO, MAX_HEIGHT).toInt());
    ui->spinTimeout->setValue(getValue(VIDEO, TIMEOUT).toInt());

    connect(ui->comboDetectionNotice, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboIgnoreClosedLid, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboIgnoreSsh, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboNoConfirmation, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboSuppressUnknown, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->comboUseCnn, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));

    connect(ui->spinCertainty, SIGNAL(valueChanged(double)), this, SLOT(hasChanged()));
    connect(ui->spinDarkThreshold, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinExposure, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->comboForceMjpeg, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
    connect(ui->spinFrameHeight, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinFrameWidth, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinMaxHeight, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
    connect(ui->spinTimeout, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));
}

Config::~Config()
{

}

void Config::save()
{
    setValue(CORE, DETECTION_NOTICE, ui->comboDetectionNotice->currentText());
    setValue(CORE, IGNORE_CLOSED_LID, ui->comboIgnoreClosedLid->currentText());
    setValue(CORE, IGNORE_SSH, ui->comboIgnoreSsh->currentText());
    setValue(CORE, NO_CONFIRMATION, ui->comboNoConfirmation->currentText());
    setValue(CORE, SUPPRESS_UNKNOWN, ui->comboSuppressUnknown->currentText());
    setValue(CORE, USE_CNN, ui->comboUseCnn->currentText());

    setValue(VIDEO, CERTAINTY, QString::number(ui->spinCertainty->value()));
    setValue(VIDEO, DARK_THRESHOLD, QString::number(ui->spinDarkThreshold->value()));
    setValue(VIDEO, EXPOSURE,QString::number(ui->spinExposure->value()));
    setValue(VIDEO, FORCE_MJPEG, ui->comboForceMjpeg->currentText());
    setValue(VIDEO, FRAME_HEIGHT, QString::number(ui->spinFrameHeight->value()));
    setValue(VIDEO, FRAME_WIDTH, QString::number(ui->spinFrameWidth->value()));
    setValue(VIDEO, MAX_HEIGHT, QString::number(ui->spinMaxHeight->value()));
    setValue(VIDEO, TIMEOUT, QString::number(ui->spinTimeout->value()));
}

void Config::hasChanged()
{
    Q_EMIT changed(true);
}

void Config::setValue(QString group, QString name, QString value)
{
    QSettings settings(INI_FILE, QSettings::IniFormat);
    QString together = group + "/" + name;
    settings.setValue(together,value);
}

QString Config::getValue(QString group, QString name)
{
    QSettings settings(INI_FILE, QSettings::IniFormat);
    QString groupWithDelimiter = "/" + group;
    settings.beginGroup(groupWithDelimiter);

    return settings.value(name).toString();
}
