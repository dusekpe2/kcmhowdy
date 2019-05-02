#include "howdy.h"
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

    KAboutData *aboutData = new KAboutData(QStringLiteral("howdy"),
                                       i18n("KDE howdy control module"),
                                       QStringLiteral(""),
                                       QString(),
                                       KAboutLicense::GPL,
                                       i18n("(c) 2019 Petr Dusek"));

    aboutData->addAuthor(i18n("Petr Dusek"),
                     QString(),
                     QStringLiteral("dusekpe2@fit.cvut.cz"));
    setAboutData(aboutData);


    mMainLayout = new QHBoxLayout(this);
    mMainLayout->setContentsMargins(0, 0, 0, 0);

    if (!mHowdyWidget) {
        mHowdyWidget = new Widget(this);
         mMainLayout->addWidget(mHowdyWidget);
    }
    connect(mHowdyWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
}

Howdy::~Howdy()
{
 delete mHowdyWidget;
}

void Howdy::save()
{
    mHowdyWidget->save();
}

void Howdy::load()
{
    mHowdyWidget->load();
}

QString Howdy::quickHelp() const
{
    return "This configuration module allows you to configure howdy program.";
}

bool Howdy::apply()
{
    return true;
}


QSize Howdy::sizeHint() const
{
    return QSize(0, 320);
}


#include "howdy.moc"
