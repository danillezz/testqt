#include "mainwindow.h"
#include <QApplication>
#include "mainhandler.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    MainHandler mainHandler(&w);

    return a.exec();
}
