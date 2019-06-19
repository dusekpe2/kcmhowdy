#include "kcmhowdy.h"

#include <QHBoxLayout>
#include <QTabWidget>
#include <QMessageBox>
#include <KPluginFactory>

#include <KAboutData>
#include "config.h"

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<KcmHowdy>();)

using namespace std;

KcmHowdy::KcmHowdy(QWidget *parent, const QVariantList &args) :
    KCModule(parent, args)
{
    mActualUserName = qgetenv("USER");

    mModelsFile = HOWDY_DATA_FILES_DIR + mActualUserName + ".dat";

    mHowdyConfig = KSharedConfig::openConfig(HOWDY_CONFIG_FILE);

    mDataWatcher.addPath(mModelsFile);
    mDataWatcher.addPath(HOWDY_DATA_FILES_DIR);
    connect(&mDataWatcher, SIGNAL(fileChanged(QString)), this, SLOT(updateTable()));
    connect(&mDataWatcher, SIGNAL(directoryChanged(QString)), this, SLOT(addPath()));

    bool configFound = mConfigWatcher.addPath(mHowdyConfig->name());

    if(!configFound)
    {
        QMessageBox errorMessageBox;
        errorMessageBox.critical(0,"Error", "Howdy config file not found\n Location is " + HOWDY_CONFIG_FILE);
        errorMessageBox.setFixedSize(700,300);

    }

    connect(&mConfigWatcher, SIGNAL(fileChanged(QString)), this, SLOT(load()));

    prepareUi();
}

KcmHowdy::~KcmHowdy()
{

}

void KcmHowdy::addPath()
{
    mDataWatcher.addPath(mModelsFile);
}

void KcmHowdy::prepareUi()
{
    QHBoxLayout* layout = new QHBoxLayout(this);
    QTabWidget* tabHolder = new QTabWidget(this);
    layout->addWidget(tabHolder);

    setButtons(Apply);

    mModelWidget = new ModelWidget(mActualUserName, mHowdyConfig, mModelsFile, this);
    connect(mModelWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    tabHolder->addTab(mModelWidget, "Model");

    mAddWidget = new AddWidget(mActualUserName, this);
    tabHolder->addTab(mAddWidget, "Add");

    mConfigWidget = new ConfigWidget(mHowdyConfig, this);
    connect(mConfigWidget, SIGNAL(changed(bool)), SIGNAL(changed(bool)));
    tabHolder->addTab(mConfigWidget, "Config");

}

void KcmHowdy::save()
{
    mConfigWidget->save();
    mModelWidget->save();
}

void KcmHowdy::load()
{
    mConfigWidget->load();
    mModelWidget->load();
}

void KcmHowdy::updateTable()
{
    mModelWidget->updateTable();
}

QString KcmHowdy::quickHelp() const
{
    return "This configuration module allows you to configure Howdy program.";
}

bool KcmHowdy::apply()
{
    return true;
}

#include "kcmhowdy.moc"
