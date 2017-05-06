#ifndef OBJECTSINFO_H
#define OBJECTSINFO_H
#include <object.h>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QObject>
#include <QtSql>

class NetworkJSONParser: public QObject
{
    Q_OBJECT

public:
    NetworkJSONParser();
    ~NetworkJSONParser();

signals:
void NewObjectData(const Object NewObj);

private:
QSqlDatabase dbase;
QNetworkAccessManager *networkManager;
QTimer *timer;

private slots:
void InfoHandler();
void parseJSON(QNetworkReply *reply);


};

#endif // OBJECTSINFO_H
