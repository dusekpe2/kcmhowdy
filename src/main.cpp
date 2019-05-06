#include <QApplication>
#include <KCModule>
#include "modelwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ModelWidget w;
    w.show();


    return a.exec();
}
