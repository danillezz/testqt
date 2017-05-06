#include "mainhandler.h"
#include "networkjsonparser.h"
#include "xmlparser.h"
#include "mainwindow.h"

#include <QApplication>


MainHandler::MainHandler(MainWindow *view, QObject *parent) :
    QObject(parent),
    mView(view),
    jobj(new NetworkJSONParser),
    xobj(new XMLParser)
{
    connect(jobj,&NetworkJSONParser::NewObjectData,view,&MainWindow::onNewObjectData);
    connect(xobj,&XMLParser::NewObjectDataXml,view,&MainWindow::onNewObjectData);
}

MainHandler::~MainHandler() {
jobj->deleteLater();
xobj->deleteLater();
}
