#ifndef MODULE_H
#define MODULE_H

#include <QString>
#include <QWidget>
#include <KCModule>
#include <QHBoxLayout>
#include "widget.h"
#include <KSharedConfig>

namespace Ui {
class module;
}



class Howdy : public KCModule
{
    Q_OBJECT

public:
    explicit Howdy(QWidget *parent = nullptr, const QVariantList &args = QVariantList());
    ~Howdy();

    QSize sizeHint() const override;

    QString quickHelp() const;
public Q_SLOTS:
    void save() override;
    void load() override;
    void changed();

private:
    Widget *m_HowdyWidget = nullptr;
    QHBoxLayout *mMainLayout = nullptr;
    bool mDataChanged = false;
    KSharedConfigPtr mHowdyConfig;

    bool apply();
};

#endif // MODULE_H
