#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <config.h>
#include "model.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void load();
    void save();

public Q_SLOTS:
    void handleAddButton();
    void hasChanged();

    Q_SIGNALS:
    void changed(bool state);
private:
    Ui::Widget *ui;
    Config *mConfig;
    Model *mModel;
};

#endif // WIDGET_H
