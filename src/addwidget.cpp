#include "addwidget.h"
#include "ui_addwidget.h"

#include <KAuth>
#include <QMessageBox>

const int MAX_LENGTH = 24;

/**
 *  Constructor.
 *  Sets UI and max length of lineEdit.
 * Also connects signal from pushButton to slot handleAddButton
 * 
 **/
AddWidget::AddWidget(const QString userName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget),
    actualUserName(userName)
{
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(MAX_LENGTH);

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(handleAddButton()));
}

/**
 * Destructor.
 * Deletes ui
 * 
 **/
AddWidget::~AddWidget()
{
    delete ui;
}

/**
 * This function is handling add button, when is clicked.
 * It gets name of model from lineEdit and send command "howdy add" with name of model to the helper.
 * It also shows MessageBox, which inform users to Look at the camera.
 * If there is some error in Helper function shows error MessageBox
 * If there is success message from Helper it also shows MessageBox telling user about success.
 * 
 **/
void AddWidget::handleAddButton()
{
    QVariantMap args;

    args["modelName"] = ui->lineEdit->text();


    args["command"] = "howdy add ";

    args[QStringLiteral("user")] = actualUserName;

    KAuth::Action startCommandAction(QStringLiteral("org.kde.kcontrol.kcmhowdy.startcommand"));
    startCommandAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmhowdy"));
    startCommandAction.setArguments(args);

    QMessageBox infoBox;
    infoBox.information(nullptr, "Info", "Look at the camera until success appear");
    infoBox.setFixedSize(500,200);

    auto job = startCommandAction.execute();

    job->exec();

    QMessageBox messageBox;

    if (job->error()){
        messageBox.critical(nullptr, "Error", job->errorString());
        messageBox.setFixedSize(500,200);
    } else {
        messageBox.information(nullptr, "Success", "Added model for user " + actualUserName);
        messageBox.setFixedSize(500,200);

    }

}
