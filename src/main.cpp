#include <QApplication>
#include <KCModule>
#include "widget.h"
#include "model.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


    return a.exec();
}
