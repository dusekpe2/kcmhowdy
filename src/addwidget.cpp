#include "addwidget.h"
#include "ui_addwidget.h"

#include <KAuth>
#include <QMessageBox>

const int MAX_LENGTH = 24;

AddWidget::AddWidget(const QString userName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddWidget),
    actualUserName(userName)
{
    ui->setupUi(this);

    ui->lineEdit->setMaxLength(MAX_LENGTH);

    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(handleAddButton()));
}

AddWidget::~AddWidget()
{
    delete ui;
}

void AddWidget::handleAddButton()
{
    QVariantMap args;

    args["modelName"] = ui->lineEdit->text();


    args["command"] = "sudo howdy add ";

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
