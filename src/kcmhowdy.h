#ifndef MODULE_H
#define MODULE_H

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

//    QSize sizeHint() const override;

    QString quickHelp() const override;
public Q_SLOTS:
    void save() override;
    void load() override;

private:
    ModelWidget *mModelWidget;
    ConfigWidget *mConfigWidget;
    AddWidget *maddWidget;

private:
    void prepareUi();
    bool apply();
};

#endif // MODULE_H
