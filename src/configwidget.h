#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H
#include <QWidget>
#include <QString>

#include <KConfig>
#include <KConfigGroup>
#include <KSharedConfig>
#include "config.h"


using namespace std;

namespace Ui {
class ConfigWidget;
}

/**
 * Class, which secures adding and loading from konfiguration files of Howdy. 
 * 
 * 
 **/
class ConfigWidget : public QWidget
{
    Q_OBJECT
public:

    explicit ConfigWidget( const KSharedConfigPtr &config, QWidget *parent = nullptr);
    ~ConfigWidget();
    void load();

public Q_SLOTS:
    void hasChanged();
    void save();
    void chooseButtonClicked();


Q_SIGNALS:
void changed(bool state);

private:
    Ui::ConfigWidget *ui;
    QString mDeviceUrl;

    KSharedConfigPtr mConfig;
    KConfigGroup coreGroup;
    KConfigGroup videoGroup;
    KConfigGroup debugGroup;


private:

};

#endif // CONFIGWIDGET_H
