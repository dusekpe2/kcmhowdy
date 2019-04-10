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
    void handleRemoveButton(int id);

private:
    Ui::Widget *ui;

    char* showDialog(QString name, QString message);
    void startCommand(QString command, QString argument, char *answer);
    void updateTable();

};

#endif // WIDGET_H
