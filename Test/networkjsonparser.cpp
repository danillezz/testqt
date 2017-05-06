#include "networkjsonparser.h"

NetworkJSONParser::NetworkJSONParser()
{
    dbase=QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("Test.sqlite");
    dbase.open();
    QSqlQuery qry;
    qry.exec("select * from Times where ID=2");
    qry.first();
 networkManager = new QNetworkAccessManager();
 connect(networkManager, &QNetworkAccessManager::finished, this, NetworkJSONParser::parseJSON);
 timer = new QTimer();
 connect(timer, SIGNAL(timeout()), this, SLOT(InfoHandler()));
 timer->start(qry.value(2).toInt()*1000);
 InfoHandler();
 qry.clear();
}

NetworkJSONParser::~NetworkJSONParser()
{
 timer->stop();
 timer->deleteLater();
 networkManager->deleteLater();
 dbase.close();
}

void NetworkJSONParser::InfoHandler() {

    QSqlQuery qry;
    QString str;
    qry.exec("select * from Times where ID=2");
    qry.first();
    if (qry.value(2).toInt()*1000!=timer->interval())
        timer->start(qry.value(2).toInt()*1000);

    qry.exec("select * from Objects where FileName is null");
    while (qry.next()) {

        str ="http://api.openweathermap.org/data/2.5/weather?q={"
                      +qry.value(2).toString()+
                      "}&APPID=0ba9896801666e58519b0d89ccc2181e";

        // Получаем данные, а именно JSON файл с сайта по определённому url
        networkManager->get(QNetworkRequest(QUrl(str)));

    }
    qry.clear();
}

void NetworkJSONParser::parseJSON(QNetworkReply *reply) {

Object obj;
ObjectParam param;

if(!reply->error()){

        //----------------Парсим JSON-------------------------------------------------------
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

           if(!document.isEmpty()) {
           // Забираем из документа все объекты
           QJsonObject root = document.object();
           QString name = root.value("name").toString();
           QJsonObject jmain = root.value("main").toObject();
           QJsonObject jwind = root.value("wind").toObject();
           QJsonObject jcoord = root.value("coord").toObject();
           QJsonArray aclouds = root.value("weather").toArray();
           QJsonObject jclouds = aclouds.at(0).toObject();
           QJsonObject jsys = root.value("sys").toObject();

           // Определяем значения параметров
           qreal temp = jmain.value("temp").toDouble();
           qint32 pressure = jmain.value("pressure").toInt();
           qint8 humidity = jmain.value("humidity").toInt();
           qint8 wind = jwind.value("speed").toInt();
           QString clouds = jclouds.value("description").toString();
           qint64 sunset = jsys.value("sunset").toInt();
           qint64 sunrise = jsys.value("sunrise").toInt();
           qint64 DT = root.value("dt").toInt();
           qreal lon = jcoord.value("lon").toDouble();
           qreal lat = jcoord.value("lat").toDouble();
           QString coords = QString::number(lon)+"; "+QString::number(lat);
           QDateTime sunsets = QDateTime::fromTime_t(sunset);
           QDateTime sunrises = QDateTime::fromTime_t(sunrise);
           QDateTime DTs = QDateTime::fromTime_t(DT);

           // Сохраняем
           obj.objname=name;
           param.paramname="Температура"; param.value=temp;
           obj.params.append(param);
           param.paramname="Давление"; param.value=pressure;
           obj.params.append(param);
           param.paramname="Влажность"; param.value=humidity;
           obj.params.append(param);
           param.paramname="Скорость ветра"; param.value=wind;
           obj.params.append(param);
           param.paramname="Обчачность"; param.value=clouds;
           obj.params.append(param);
           param.paramname="Рассвет"; param.value=sunsets;
           obj.params.append(param);
           param.paramname="Закат"; param.value=sunrises;
           obj.params.append(param);
           param.paramname="Дата"; param.value=DTs;
           obj.params.append(param);
           param.paramname="Координаты"; param.value=coords;
           obj.params.append(param);
    }
    //----------------------------------------------------------------------------------
    }
    emit NewObjectData(obj);
    reply->deleteLater();

}


