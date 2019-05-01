#include "howdyauthhelper.h"
#include <QDebug>
#include <QProcess>

ActionReply HowdyAuthHelper::command(const QVariantMap &args)
{
    QString dpkg_command = "howdy list";
        QProcess *myProcess = new QProcess(this);
        myProcess->start(dpkg_command);
        myProcess->waitForFinished();

        QString output(myProcess->readAllStandardOutput());
        qDebug()<<"jebo"<<endl;
        qDebug()<<output<<endl;

        QStringList installedPaths;
        installedPaths.append(output);

        auto rc = ActionReply::SuccessReply();
        rc.addData("neco", installedPaths);
        return rc;
}

KAUTH_HELPER_MAIN("org.kde.kcontrol.howdy", HowdyAuthHelper);

#include "moc_howdyauthhelper.cpp"
