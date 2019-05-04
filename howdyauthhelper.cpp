#include "howdyauthhelper.h"
#include <QDebug>
#include <QProcess>

ActionReply HowdyAuthHelper::getmodels(const QVariantMap &args)
{
        QString dpkg_command = "sudo howdy list --user petr";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());

        QVariantMap retdata;
           retdata["message"] = output;

        auto rc = ActionReply::SuccessReply();
        rc.setData(retdata);
        return rc;

}

ActionReply HowdyAuthHelper::save(const QVariantMap &args)
{
    return ActionReply::SuccessReply();
}

KAUTH_HELPER_MAIN("org.kde.kcontrol.howdy", HowdyAuthHelper);

#include "moc_howdyauthhelper.cpp"
