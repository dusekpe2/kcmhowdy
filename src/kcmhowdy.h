#ifndef MODULE_H
#define MODULE_H

#include <QFileSystemWatcher>
#include <QString>
#include <KCModule>
#include <KSharedConfig>

#include "modelwidget.h"
#include "configwidget.h"
#include "addwidget.h"

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
    void updateTable();
private:
    KSharedConfigPtr mHowdyConfig;
    ModelWidget *mModelWidget;
    ConfigWidget *mConfigWidget;
    AddWidget *mAddWidget;
    QFileSystemWatcher dataWatcher;
    QFileSystemWatcher configWatcher;
    QString actualUserName;

private:
    void prepareUi();
    bool apply();
};

#endif // MODULE_H
