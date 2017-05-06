#ifndef MAINHANDLER_H
#define MAINHANDLER_H
#include <QObject>
#include <object.h>

class NetworkJSONParser;
class XMLParser;
class MainWindow;

class MainHandler : public QObject
{
    Q_OBJECT
public:
    explicit MainHandler(MainWindow *view, QObject *parent = 0);
    ~MainHandler();

private:
    XMLParser *xobj;
    NetworkJSONParser *jobj;
    MainWindow *mView;

};

#endif // MAINHANDLER_H
