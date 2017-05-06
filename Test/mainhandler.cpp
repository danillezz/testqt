#include "mainhandler.h"
#include "objectsinfo.h"
#include "mainwindow.h"

#include <QApplication>


MainHandler::MainHandler(MainWindow *view, QObject *parent) :
    QObject(parent),
    mView(view),
    objinf(new ObjectsInfo)
{
    connect(objinf,&ObjectsInfo::NewObjectData,view,&MainWindow::onNewObjectData);
    connect(view,&MainWindow::SettingsChange,objinf,&ObjectsInfo::onSettingsChanged);
}

MainHandler::~MainHandler() {
objinf->~ObjectsInfo();
}
