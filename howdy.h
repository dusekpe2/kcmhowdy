#ifndef MODULE_H
#define MODULE_H

#include <QString>
#include <QWidget>
#include <KCModule>
#include <QHBoxLayout>
#include "widget.h"
#include <KSharedConfig>


class Howdy : public KCModule
{
    Q_OBJECT

public:
    explicit Howdy(QWidget *parent, const QVariantList &args);
    ~Howdy();

    QSize sizeHint() const override;

    QString quickHelp() const;
public Q_SLOTS:
    void save() override;
    void load() override;

private:
    Widget *m_HowdyWidget = nullptr;
    QHBoxLayout *mMainLayout = nullptr;
    bool mDataChanged = false;
    KSharedConfigPtr mHowdyConfig;

    bool apply();
};

#endif // MODULE_H
