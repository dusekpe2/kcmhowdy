#ifndef MODULE_H
#define MODULE_H

#include <QString>

#include <QWidget>
#include <KCModule>

namespace Ui {
class module;
}

class Howdy : public KCModule
{
    Q_OBJECT

public:
    explicit Howdy(QWidget *parent = nullptr, const QVariantList &args = QVariantList());
    ~Howdy();

    QString quickHelp() const;
public Q_SLOTS:
    void save() override;
    void load() override;
    void defaults() override;
    void handleDisableButton();
    void handleEnableButton();


private:
    Ui::module *ui;
};

#endif // MODULE_H
