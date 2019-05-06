#include "kcmhowdy.h"

#include <QHBoxLayout>
#include <QTabWidget>

#include <KPluginFactory>

#include <KAboutData>

#include <KLocalizedString>
#include "config.h"
#include <QDebug>

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<KcmHowdy>();)

using namespace std;

KcmHowdy::KcmHowdy(QWidget *parent, const QVariantList &args) :
    KCModule(parent, args)
{

//    KAboutData *aboutData = new KAboutData(QStringLiteral("howdy"),
//                                       i18n("KDE howdy control module"),
//                                       QStringLiteral(""),
//                                       QString(),
//                                       KAboutLicense::GPL,
//                                       i18n("(c) 2019 Petr Dusek"));

//    aboutData->addAuthor(i18n("Petr Dusek"),
//                     QString(),
//                     QStringLiteral("dusekpe2@fit.cvut.cz"));
//    setAboutData(aboutData);


//    mMainLayout = new QHBoxLayout(this);
//    mMainLayout->setContentsMargins(0, 0, 0, 0);

//    if (!mHowdyWidget) {
//        mHowdyWidget = new Widget(this);
//         mMainLayout->addWidget(mHowdyWidget);
//    }
//    connect(mHowdyWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));

    prepareUi();
}

KcmHowdy::~KcmHowdy()
{
// delete mHowdyWidget;
}

void KcmHowdy::prepareUi()
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QTabWidget* tabHolder = new QTabWidget(this);
    layout->addWidget(tabHolder);


    mModelWidget = new ModelWidget(this);
    //connect(mModelWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));

    tabHolder->addTab(mModelWidget, "Model");

    mConfigWidget = new ConfigWidget(this);
    connect(mConfigWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    tabHolder->addTab(mConfigWidget, "Config");


//    connect(tabHolder, SIGNAL(currentChanged(int)), this, SLOT(load()));
}

void KcmHowdy::save()
{
    mConfigWidget->save();
}

void KcmHowdy::load()
{
    mConfigWidget->load();
}

QString KcmHowdy::quickHelp() const
{
    return "This configuration module allows you to configure howdy program.";
}

bool KcmHowdy::apply()
{
    return true;
}


//QSize KcmHowdy::sizeHint() const
//{
//    return QSize(0, 400);
//}


#include "kcmhowdy.moc"
