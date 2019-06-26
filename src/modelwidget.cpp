#include "modelwidget.h"
#include "ui_modelwidget.h"
#include <QSignalMapper>
#include <QMessageBox>
#include <KAuth>

/**
 * Constructor
 * sets UI, updates Table and prepares UI
 * 
 **/
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

/**
 * Destructor
 * Deletes UI
 * 
 **/
ModelWidget::~ModelWidget()
{
    delete ui;

}

/**
 * Emits signal changed
 * It is called when check box is clicked
 * 
 **/
void ModelWidget::hasChanged()
{
    Q_EMIT changed(true);
}

/**
 * This function handles clear button when clicked
 * it starts HowdyAuthHelper and send it command "howdy clear" with name of actual user
 * shows error message when something went wrong
 **/
void ModelWidget::handleClearButton()
{

   QString answer = showDialog("Clear", "Remove all models?");

    if(answer == "y"){

        QVariantMap args;

        args["command"] = "howdy clear ";
        args[QStringLiteral("user")] = mActualUserName;

        KAuth::Action getModelsAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        getModelsAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        getModelsAction.setArguments(args);

        auto job = getModelsAction.execute();

        job->exec();

        if (job->error()){
            QMessageBox errorMessageBox;
            errorMessageBox.critical(0,"Error", job->errorString());
            errorMessageBox.setFixedSize(500,200);
        }
    }

}

/**
 * This function shows dialog to user.
 * He choose yes or now.
 * It is called by function handleClearButton
 * 
 **/
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

/**
 * Handles remove button when is clicked
 * When button in table is clicked it shows dialog if user wants to remove model
 * If user choose yeas it starts HowdyAuthHelper and send him command "howdy remove" with id of model to be removed
 * When something went wrong it shows MessageBox with error mesage
 * 
 **/
void ModelWidget::handleRemoveButton(int id)
{

    QString answer = this->showDialog("Remove", "Remove model with id " + QString::number(id) + "?");

    if(answer == "y")
    {

        QVariantMap args;

        args["command"] = "howdy remove ";
        args[QStringLiteral("user")] = mActualUserName;
        args[QStringLiteral("modelId")] = id;
        KAuth::Action saveAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
        saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
        saveAction.setArguments(args);

        auto job = saveAction.execute();

        job->exec();

        QMessageBox messageBox;

        if (job->error()){
            messageBox.critical(nullptr, "Error", job->errorString());
            messageBox.setFixedSize(500,200);
        }
    }
}

/**
 * This function handles check box when is clicked.
 * Also starts function hasChanged, which emits signal changed
 * 
 **/
void ModelWidget::handleCheckBox(bool state)
{
    mIsEnabled = state;
    hasChanged();

}

/**
 * This function saves new data to configuration file 
 * It is used because of check box for allow or disable howdy 
 * which is located in configuration file.
 * 
 **/
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

}

/**
 * Loads check box state from configuration file
 * 
 **/
void ModelWidget::load()
{
    mIsEnabled = (mConfig->entryMap(CORE)[DISABLED] =="false");
    ui->checkAllow->setChecked(mIsEnabled);
}

/**
 * Prepares UI
 * add tableview model and connects signal for clear button
 * 
 **/
void ModelWidget::prepareUi()
{

    connect(ui->checkAllow, SIGNAL(clicked(bool)), this, SLOT(handleCheckBox(bool)));

    ui->tableView->setModel(&mFacesModel);

    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(handleClearButton()));

}

/**
 * This function updates table.
 * It calls updateData from class mFaceModelsList and updates table.
 * It also creates delete buttons in rows of table and connect signals from them
 * to function handleRemoveButton
 * 
 **/
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

             connect(delButton, SIGNAL(clicked()), mapper, SLOT(map()));
             mapper->setMapping(delButton, mFacesModel.at(i).getId().toInt());
             connect(mapper, SIGNAL(mapped(int)), this, SLOT(handleRemoveButton(int)));
        }
    }
}
