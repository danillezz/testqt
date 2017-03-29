#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <QApplication>
#include "QtSql"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
