#include "kcmhowdy.h"

#include <QHBoxLayout>
#include <QTabWidget>
#include <QMessageBox>
#include <KPluginFactory>

#include <KAboutData>
#include "config.h"

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<KcmHowdy>();)

using namespace std;

/**
 * KCM module construtor
 * It gets name of actual user and sets configuration and models files.
 * It shows ErrorMessageBox when configuration file is not located in disk.
 * Connects signals to Watchers and add paths to watchers
 * 
 **/
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

/**
 *  Destructor
 * Nothing to do
 * 
 **/
KcmHowdy::~KcmHowdy()
{

}

/**
 * Adds path to mDataWatcher.
 * It is called when directory is changed, because of unexisting data file.
 * When data file is removed it looses connection. 
 * When directory is changed it should mean new file is added and it tries to 
 * add watcher for file with data of face models.
 **/
void KcmHowdy::addPath()
{
    mDataWatcher.addPath(mModelsFile);
}

/**
 *  Function which prepares UI.
 * It adds ConfigWidget, AddWidget and ModelWidget as tabholders.
 * 
 **/
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

/**
 *  Tells classes ConfigWidget and ModelWidget to save. 
 *  It is called when button Apply is clicked.
 * 
 **/
void KcmHowdy::save()
{
    mConfigWidget->save();
    mModelWidget->save();
}

/**
 * This function tells ConfigWidget and ModelWidget to load data.
 * It is called when module is started or when button reset is clicked.
 *
 **/
void KcmHowdy::load()
{
    mConfigWidget->load();
    mModelWidget->load();
}

/**
 * Tells ModelWidget to update table and data in it.
 * It is called by Watcher of data file.
 * 
 **/
void KcmHowdy::updateTable()
{
    mModelWidget->updateTable();
}

/**
 * Shows message about program.
 * 
 **/
QString KcmHowdy::quickHelp() const
{
    return "This configuration module allows you to configure Howdy program.";
}

#include "kcmhowdy.moc"
