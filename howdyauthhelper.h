#ifndef HOWDYAUTHHELPER_H
#define HOWDYAUTHHELPER_H

#include<KAuth>

using namespace KAuth;

/**
 * Auth helper class header.
 * This class is needed and is known as helper, which can start commands as root
 * 
 **/
class HowdyAuthHelper : public QObject
{
    Q_OBJECT
public Q_SLOTS:
    ActionReply startcommand(const QVariantMap &args);
    ActionReply save(const QVariantMap &args);
};

#endif // HOWDYAUTHHELPER_H
