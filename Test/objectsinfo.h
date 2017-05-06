#ifndef OBJECTSINFO_H
#define OBJECTSINFO_H
#include <QList>
#include <object.h>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <settings.h>
#include <QObject>
#include <QXmlStreamReader>

class ObjectsInfo: public QObject
{
    Q_OBJECT

public:
    ObjectsInfo();
    ~ObjectsInfo();
public slots:
    void onSettingsChanged();

signals:
void NewObjectData(const QList<Object> &NewInfo);

private:
QList <Object> allinfo;
QNetworkAccessManager *networkManager;
QTimer *timer;
QList <ObjectSettings> objsettings;
Settings settings;

void parseXML(QFile *file);

private slots:
void InfoHandler();
void parseJSON(QNetworkReply *reply);


};

#endif // OBJECTSINFO_H
