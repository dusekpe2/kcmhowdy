#ifndef ADDWIDGET_H
#define ADDWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class AddWidget;
}

/**
 * Class AddWidget.
 * Secures adding new face model to program Howdy
 **/
class AddWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AddWidget(const QString userName, QWidget *parent = nullptr);
    ~AddWidget();

public Q_SLOTS:
    void handleAddButton();

private:
    Ui::AddWidget *ui;
    QString actualUserName;
};

#endif // ADDWIDGET_H
