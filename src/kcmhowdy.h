#ifndef MODULE_H
#define MODULE_H

#include <QFileSystemWatcher>
#include <QString>
#include <KCModule>
#include <KSharedConfig>

#include "modelwidget.h"
#include "configwidget.h"
#include "addwidget.h"

/**
 * Main class for KCM module 
 * 
 **/
class KcmHowdy : public KCModule
{
    Q_OBJECT

public:
    explicit KcmHowdy(QWidget *parent, const QVariantList &args);
    ~KcmHowdy();

    QString quickHelp() const override;
public Q_SLOTS:
    void save() override;
    void load() override;
    void addPath();
    void updateTable();
private:
    KSharedConfigPtr mHowdyConfig;
    ModelWidget *mModelWidget;
    ConfigWidget *mConfigWidget;
    AddWidget *mAddWidget;
    QFileSystemWatcher mDataWatcher;
    QFileSystemWatcher mConfigWatcher;
    QString mActualUserName;
    QString mModelsFile;

private:
    void prepareUi();
};

#endif // MODULE_H
