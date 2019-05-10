#include "modelwidget.h"
#include "ui_modelwidget.h"
#include <QProcess>
#include <QStandardItemModel>
#include <QTextStream>
#include <QSignalMapper>
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QSortFilterProxyModel>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <KAuth>
#include <KConfigGroup>
#include <QState>

ModelWidget::ModelWidget(const QString userName, const KSharedConfigPtr &config, const QString modelsFileName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModelWidget),
    mFacesModel(modelsFileName),
    mConfig(config),
    mActualUserName(userName)
{
    ui->setupUi(this); 

    prepareUi();
    updateTable();
}

ModelWidget::~ModelWidget()
{
    delete ui;

}

void ModelWidget::hasChanged()
{
    Q_EMIT changed(true);
}


void ModelWidget::handleClearButton()
{

   QString answer = showDialog("Clear", "Remove all models?");

    if(answer == "y"){

        QVariantMap args;

        args["command"] = "sudo howdy clear ";
        args[QStringLiteral("user")] = mActualUserName;

        KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        getModelsAction.setArguments(args);

        auto job = getModelsAction.execute();

        job->exec();

        if (job->error()){
            qDebug() << "Clear Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
        } else {
            qDebug() << "Cleared";
        }
    }

}

QString ModelWidget::showDialog(QString name, QString message)
{   
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, name, message,
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {

       return "y";
     } else {
        return "n";
     }

}

void ModelWidget::handleRemoveButton(int id)
{

    qDebug()<<"Remove: "<<id<<endl;
    QString answer = this->showDialog("Remove", "Remove model with id " + QString::number(id) + "?");

    if(answer == "y")
    {

        QVariantMap args;

        args["command"] = "sudo howdy remove ";
        args[QStringLiteral("user")] = mActualUserName;
        args[QStringLiteral("modelId")] = id;
        KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        saveAction.setArguments(args);

        auto job = saveAction.execute();

        job->exec();

        if (job->error()){
            qDebug() << "Save Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
        } else {
            qDebug() << "File saved";

            updateTable();
        }

    }
}

void ModelWidget::handleCheckBox(bool state)
{
    mIsEnabled = state;
    hasChanged();

}

void ModelWidget::save()
{
    QVariantMap args;
    args[QStringLiteral("conf")] = mConfig->name();
    args[CORE+"/"+DISABLED] = !mIsEnabled;

    KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.save"));
    saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    saveAction.setArguments(args);

    auto job = saveAction.execute();

    job->exec();

    if (job->error()){
            qDebug() << "Save Failed";
            qDebug() << job->errorString();
            qDebug() << job->errorText();
    } else {
        qDebug() << "File saved";
    }

}

void ModelWidget::load()
{
    mIsEnabled = (mConfig->entryMap(CORE)[DISABLED] =="false");
    ui->checkAllow->setChecked(mIsEnabled);
}

void ModelWidget::prepareUi()
{

    connect(ui->checkAllow, SIGNAL(clicked(bool)), this, SLOT(handleCheckBox(bool)));

    ui->tableView->setModel(&mFacesModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));

}

void ModelWidget::updateTable()
{
    if(mFacesModel.updateData())
    {
        ui->tableView->update();

        for(int i=0; i<mFacesModel.rowCount(); i++)
        {
            QPushButton *delButton = new QPushButton();
            delButton->setText("Delete");

             ui->tableView->setIndexWidget(mFacesModel.index(i,mFacesModel.columnCount()-1), delButton);

             QSignalMapper *mapper = new QSignalMapper();

            qDebug()<<mFacesModel.at(i).getId()<<endl;
             connect(delButton, SIGNAL(clicked()), mapper, SLOT(map()));
             mapper->setMapping(delButton, mFacesModel.at(i).getId().toInt());
             connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleRemoveButton(int)));
        }
    }
}
