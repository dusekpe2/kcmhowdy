#include "howdy.h"
#include "ui_module.h"
#include <KPluginFactory>
#include <KAboutData>
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>
#include <KConfigGroup>
#include <KConfig>
#include <QDir>
#include <KLocalizedString>

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<Howdy>();)

using namespace std;

Howdy::Howdy(QWidget *parent, const QVariantList &args) :
    KCModule(parent, args)
{
    KAboutData* aboutData = new KAboutData(QStringLiteral("kcmsddm"), i18n("SDDM KDE Config"), QLatin1String("neco"));

    aboutData->setShortDescription(i18n("Login screen using the SDDM"));
    aboutData->setLicense(KAboutLicense::GPL_V2);
    aboutData->setHomepage(QStringLiteral("https://projects.kde.org/projects/kde/workspace/sddm-kcm"));

    aboutData->addAuthor(QStringLiteral("Reza Fatahilah Shah"), i18n("Author"), QStringLiteral("rshah0385@kireihana.com"));

    setAboutData(aboutData);

    mHowdyConfig = KSharedConfig::openConfig(QStringLiteral("@HOWDY_CONFIG_FILE@"), KConfig::CascadeConfig);

    QStringList configFiles = QDir(QLatin1String("@HOWDY_CONFIG_DIR@")).entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::LocaleAware),
                systemConfigFiles = QDir(QLatin1String("@HOWDY_SYSTEM_CONFIG_DIR@")).entryList(QDir::Files | QDir::NoDotAndDotDot, QDir::LocaleAware);

    transform(systemConfigFiles.begin(), systemConfigFiles.end(), systemConfigFiles.begin(),
                    [](const QString &filename) -> QString { return QStringLiteral("@HOWDY_SYSTEM_CONFIG_DIR@" "/") + filename; });
    transform(configFiles.begin(), configFiles.end(), configFiles.begin(),
                    [](const QString &filename) -> QString { return QStringLiteral("@HOWDY_CONFIG_DIR@" "/") + filename; });

    mHowdyConfig->addConfigSources(systemConfigFiles + configFiles);


    mMainLayout = new QHBoxLayout(this);
    mMainLayout->setContentsMargins(0, 0, 0, 0);

    if (!m_HowdyWidget) {
        m_HowdyWidget = new Widget(this);
         mMainLayout->addWidget(m_HowdyWidget);
    }
}

Howdy::~Howdy()
{

}

void Howdy::save()
{
//    QVariantMap args;

//    args[QStringLiteral("howdy.conf")] = QLatin1String("@HOWDY_CONFIG_FILE@");

//    KAuth::Action saveAction = authAction();

//    saveAction.setHelperId(QStringLiteral("org.kde.kcontrol.kcmsddm"));
//    saveAction.setArguments(args);

//    auto job = saveAction.execute();
//    job->exec();


}

void Howdy::load()
{

}

QString Howdy::quickHelp() const
{
    return "Ahoj toto je quickhelp";
}

bool Howdy::apply()
{
    return true;
}

void Howdy::changed()
{
    if(mDataChanged){
        KCModule::changed();
    }

}

QSize Howdy::sizeHint() const
{
    return QSize(0, 320);
}


#include "howdy.moc"
