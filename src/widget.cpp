#include "widget.h"
#include "ui_widget.h"
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>
#include <QMessageBox>
#include <parser.h>
#include <QPushButton>
#include <QSignalMapper>
#include <QDebug>
#include <QVBoxLayout>
#include <KConfig>
#include <KConfigGroup>
#include <KAuth>
using namespace std;



Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    mConfig = new Config(this);
    mModel = new Model(this);


    QVBoxLayout *layoutConfig = new QVBoxLayout();
    ui->Config->setLayout(layoutConfig);
    layoutConfig->addWidget(mConfig);

    QVBoxLayout *layoutModel = new QVBoxLayout();
    ui->Model->setLayout(layoutModel);
    layoutModel->addWidget(mModel);

//    KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.howdy.command"));
//   saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.howdy"));

//   auto job = saveAction.execute();

//    QVariantMap args;
    KAuth::Action commandAction(QStringLiteral("org.kde.kcontrol.howdy.command"));

    commandAction.setHelperId(QStringLiteral("org.kde.kcontrol.howdy"));
//    commandAction.setArguments(args);

    KAuth::ExecuteJob *job = commandAction.execute();
    job->exec();

    if (job->error()){
        qDebug() << "Save Failed";
        qDebug() << job->errorString();
        qDebug() << job->errorText();
    } else {
        changed(false);
        qDebug() << "Option saved";
    }

//    connect(ui->comboDetectionNo tice, SIGNAL(currentTextChanged(QString)), this, SLOT(comboBoxChanged(QString)));
    load(); //SMAZAT!!!

    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(hasChanged()));
//    connect(ui->disableButton, SIGNAL(clicked()), this, SLOT(handleDisableButton()));
//    connect(ui->enableButton, SIGNAL(clicked()), this, SLOT(handleEnableButton()));
//    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));
//    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(handleAddButton()));

    connect(mModel, SIGNAL(disabledSignal(bool)), SIGNAL(changed(bool)));
    connect(mConfig, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
}

Widget::~Widget()
{
    delete ui;
    delete mConfig;
    delete mModel;
}

void Widget::hasChanged()
{
    Q_EMIT changed(true);
}

void Widget::save()
{
    mConfig->save();
}

void Widget::load()
{
    ui->textEdit->setText("");
    mConfig->load();
}


void Widget::handleAddButton()
{
//    QString modelName = ui->textEdit->toPlainText();
//    QByteArray ba = modelName.toLocal8Bit();
//    this->startCommand("pkexec sudo howdy add", "", ba.data());
//    this->updateTable();
//    ui->textEdit->clear();
}




