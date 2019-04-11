#include "howdy.h"
#include "ui_module.h"
#include <KPluginFactory>
#include <KAboutData>
#include <QStandardItemModel>
#include <QProcess>
#include <iostream>
#include <QTextStream>

K_PLUGIN_FACTORY(howdyConfigFactory, registerPlugin<Howdy>();)

using namespace std;

Howdy::Howdy(QWidget *parent, const QVariantList &args) :
    KCModule(parent, args)
{
    mMainLayout = new QHBoxLayout(this);
    mMainLayout->setContentsMargins(0, 0, 0, 0);

    if (!m_HowdyWidget) {
        m_HowdyWidget = new Widget(this);
         mMainLayout->addWidget(m_HowdyWidget);
    }
}

Howdy::~Howdy()
{

}

void Howdy::save()
{

}

void Howdy::load()
{

}

void Howdy::defaults()
{

}


QString Howdy::quickHelp() const
{
    return "Ahoj toto je quickhelp";
}

bool Howdy::apply()
{
    return true;
}


#include "howdy.moc"
