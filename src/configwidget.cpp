#include "configwidget.h"
#include "ui_configwidget.h"
#include <QMessageBox>
#include <iostream>
#include <QFileDialog>

#include <KAuth>
#include <QStringLiteral>

/**
 * Constructor. 
 * Sets UI.
 * Connects all signals from elements in UI for konfiguration file to slot hasChanged.
 **/
ConfigWidget::ConfigWidget(const KSharedConfigPtr &config, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConfigWidget),
    mConfig(config)
{
    ui->setupUi(this);

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
    connect(ui->spinTimeout, SIGNAL(valueChanged(int)), this, SLOT(hasChanged()));

     connect(ui->comboEndReport, SIGNAL(currentTextChanged(QString)), this, SLOT(hasChanged()));
}

/**
 * Destructor 
 * Deletes UI
 * 
 **/
ConfigWidget::~ConfigWidget()
{
    delete ui;
}

/**
 * This function is started when Widgets needs to load.
 * Function loads data from konfiguration file and save it to UI elements.
 * 
 **/
void ConfigWidget::load()
{
    mConfig->reparseConfiguration();

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

    changed(false);
}

/**
 * This function handling choose button for selecting path to camera
 * Shows dialog with files, where user can choose a file with camera.
 **/
void ConfigWidget::chooseButtonClicked()
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

/**
 * This function saves values from UI elements to configuration file.
 * It calls HowdyAuthHelper, which needs admin privileges to run.
 * It also shows MessageBox with error if something went wrong or with success.
 **/
void ConfigWidget::save()
{

    QVariantMap args;

    args[CORE+"/"+DETECTION_NOTICE] = ui->comboDetectionNotice->currentText();
    args[CORE+"/"+IGNORE_CLOSED_LID] = ui->comboIgnoreClosedLid->currentText();
    args[CORE+"/"+IGNORE_SSH] = ui->comboIgnoreSsh->currentText();
    args[CORE+"/"+NO_CONFIRMATION] = ui->comboNoConfirmation->currentText();
    args[CORE+"/"+SUPPRESS_UNKNOWN] = ui->comboSuppressUnknown->currentText();
    args[CORE+"/"+USE_CNN] = ui->comboUseCnn->currentText();

    args[VIDEO+"/"+CERTAINTY] =  QString::number(ui->spinCertainty->value());
    args[VIDEO+"/"+DARK_THRESHOLD] = QString::number(ui->spinDarkThreshold->value());
    args[VIDEO+"/"+DEVICE_FORMAT] = ui->comboDeviceFormat->currentText();
    args[VIDEO+"/"+DEVICE_PATH] = mDeviceUrl;
    args[VIDEO+"/"+EXPOSURE] = QString::number(ui->spinExposure->value());
    args[VIDEO+"/"+FORCE_MJPEG] = ui->comboForceMjpeg->currentText();
    args[VIDEO+"/"+FRAME_HEIGHT] = QString::number(ui->spinFrameHeight->value());
    args[VIDEO+"/"+FRAME_WIDTH] = QString::number(ui->spinFrameWidth->value());
    args[VIDEO+"/"+MAX_HEIGHT] = QString::number(ui->spinMaxHeight->value());
    args[VIDEO+"/"+RECORDING_PLUGIN] = ui->comboRecordingPlugin->currentText();
    args[VIDEO+"/"+TIMEOUT] = QString::number(ui->spinTimeout->value());

    args[DEBUG+"/"+END_REPORT] = ui->comboEndReport->currentText();

    args[QStringLiteral("conf")] = mConfig->name();

    KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.save"));
    saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    saveAction.setArguments(args);

    auto job = saveAction.execute();

    job->exec();

    QMessageBox messageBox;

    if (job->error()){
        messageBox.critical(nullptr, "Error", "Save failed");
    } else {
        messageBox.information(nullptr, "Success", "File saved");
    }
    messageBox.setFixedSize(500,200);

}

/**
 * If something in class changed signal changed is sent.
 * 
 **/
void ConfigWidget::hasChanged()
{
    Q_EMIT changed(true);
}

