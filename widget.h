#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public Q_SLOTS:
    void handleDisableButton();
    void handleEnableButton();
    void handleClearButton();
    void handleAddButton();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
