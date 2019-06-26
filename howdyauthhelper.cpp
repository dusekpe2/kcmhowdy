#include "howdyauthhelper.h"
#include <QProcess>
#include <QString>
#include <QSharedPointer>
#include <KSharedConfig>
#include <KConfig>
#include <KConfigGroup>

/**
 * This function is started as admin and writes flags values to the configuration file of Howdy.
 * Values to be written is getted in parameter QVariantMap *args
 * 
 **/
ActionReply HowdyAuthHelper::save(const QVariantMap &args)
{
    KSharedConfigPtr howdyConfig = KSharedConfig::openConfig(args[QStringLiteral("conf")].toString());

    for(auto it  = args.constBegin(); it!= args.constEnd(); it++)
    {

        QStringList configFields = it.key().split('/');

        if(configFields.size()==2)
        {
            QString groupName = configFields[0];
            QString keyName = configFields[1];

            howdyConfig->group(groupName).writeEntry(keyName, it.value());
        }

    }

    if(!howdyConfig->sync())
    {
        return ActionReply::HelperErrorReply();
    }


    return ActionReply::SuccessReply();

}

/**
 * This function is started as admin and starts command, which is sent in parameter
 * QVariantMap &args.
 * Function checks if sudo is installed and if command, which was sent finished good.
 * If not it returns an Error with description what was the error
 **/
ActionReply HowdyAuthHelper::startcommand(const QVariantMap &args)
{
	QString dpkg_command = "";
	QProcess *testSudo = new QProcess(this);
	testSudo->start("sudo");
	testSudo->waitForFinished();
	if(testSudo->exitCode() == 1){
		dpkg_command += "sudo ";
	} else {
	      auto errorReplyAction = ActionReply::HelperErrorReply();
              errorReplyAction.setErrorDescription("Sudo must be installed");
              return errorReplyAction;
	
	}

        QString modelName = args["modelName"].toString();

        dpkg_command += args["command"].toString() + args["modelId"].toString() + " --user " + args["user"].toString();

        if(modelName.isNull() || modelName.isEmpty()){
            dpkg_command += " -y";
        }
        QProcess *proccessToStart = new QProcess(this);
        proccessToStart->start(dpkg_command);
        proccessToStart->waitForStarted();
        proccessToStart->waitForReadyRead();

        if(proccessToStart->exitCode())
        {
            auto errorReplyAction = ActionReply::HelperErrorReply();
            errorReplyAction.setErrorDescription("Howdy is not installed correctly");
            return errorReplyAction;
        }

        if(!modelName.isNull()){
            proccessToStart->write(modelName.toLatin1());

            proccessToStart->waitForBytesWritten();
            proccessToStart->closeWriteChannel();


        }

        proccessToStart->waitForFinished();

        QString replyFromCommand(proccessToStart->readAllStandardOutput());

        QStringList linesofReply = replyFromCommand.split("\n");

        QString replyMessage = linesofReply.at(linesofReply.size()-2);

        if(proccessToStart->exitCode())
        {
            auto errorReplyAction = ActionReply::HelperErrorReply();
            errorReplyAction.setErrorDescription(replyMessage);
            return errorReplyAction;
        }
        auto successReplyAction = ActionReply::SuccessReply();
        return successReplyAction;

}

KAUTH_HELPER_MAIN("org.kde.kcontrol.kcmhowdy", HowdyAuthHelper)

#include "moc_howdyauthhelper.cpp"
