#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <config.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void loadDefaults();
    void save();

public Q_SLOTS:
    void handleDisableButton();
    void handleEnableButton();
    void handleClearButton();
    void handleAddButton();
    void handleRemoveButton(int id);
    void hasChanged();

    Q_SIGNALS:
    void changed(bool state);
private:
    Ui::Widget *ui;
    Config *mConfig;
    char* showDialog(QString name, QString message);
    void startCommand(QString command, QString argument, char *answer);
    void updateTable();
    void readFile();

};

#endif // WIDGET_H
