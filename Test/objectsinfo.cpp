#include "objectsinfo.h"

ObjectsInfo::ObjectsInfo()
{
 networkManager = new QNetworkAccessManager();
 connect(networkManager, &QNetworkAccessManager::finished, this, ObjectsInfo::parseJSON);
 timer = new QTimer();
 connect(timer, SIGNAL(timeout()), this, SLOT(InfoHandler()));
 timer->start(settings.time2*1000);
 InfoHandler();

}

ObjectsInfo::~ObjectsInfo()
{
 timer->stop();
 timer->deleteLater();
 allinfo.clear();
 networkManager->deleteLater();
 objsettings.clear();
}

void ObjectsInfo::onSettingsChanged() {
    settings.Refresh();
    timer->start(settings.time2*1000);
}

void ObjectsInfo::InfoHandler() {

    allinfo.clear();
    objsettings.clear();
    objsettings=settings.GetSettings();

    for (int i=0; i<objsettings.count(); i++) {
    QString str = objsettings.value(i).filename;
    QFile *file= new QFile(str);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
        str ="http://api.openweathermap.org/data/2.5/weather?q={"
                      +objsettings.value(i).engname+
                      "}&APPID=0ba9896801666e58519b0d89ccc2181e";

                  // Получаем данные, а именно JSON файл с сайта по определённому url
        networkManager->get(QNetworkRequest(QUrl(str)));
        }
    else {
        parseXML(file);
        }
    }

}

void ObjectsInfo::parseJSON(QNetworkReply *reply) {

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
           allinfo.append(obj);
    }
    //----------------------------------------------------------------------------------
    }
    emit NewObjectData(allinfo);
    reply->deleteLater();

}

void ObjectsInfo::parseXML(QFile *file) {
    Object obj;
    ObjectParam param;
    QXmlStreamReader xml(file);
    while (!xml.atEnd() && !xml.hasError())
        {
            QXmlStreamReader::TokenType token = xml.readNext();
            if (token == QXmlStreamReader::StartDocument)
                continue;
            if (token == QXmlStreamReader::StartElement)
            if (xml.name() == "cityinfo") {
                while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "cityinfo"))
                    {
                        if (xml.tokenType() == QXmlStreamReader::StartElement)
                        {
                         if (xml.name() == "name"){
                            xml.readNext();
                            obj.objname=xml.text().toString();}
                         if (xml.name() == "temp"){
                             xml.readNext();
                             param.paramname="Температура"; param.value=xml.text().toDouble();
                             obj.params.append(param);
                               }
                         if (xml.name() == "pressure"){
                             xml.readNext();
                            param.paramname="Давление"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                             }
                         if (xml.name() == "humidity"){
                             xml.readNext();
                            param.paramname="Влажность"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                             }
                         if (xml.name() == "wind"){
                             xml.readNext();
                            param.paramname="Скорость ветра"; param.value=xml.text().toDouble();
                            obj.params.append(param);
                            }
                         if (xml.name() == "clouds"){
                             xml.readNext();
                            param.paramname="Облачность"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "sunset"){
                             xml.readNext();
                            param.paramname="Рассвет"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "sunrise"){
                             xml.readNext();
                            param.paramname="Закат"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                            if (xml.name() == "date"){
                                xml.readNext();
                            param.paramname="Дата"; param.value=xml.text().toString();
                            obj.params.append(param);
                         }
                         if (xml.name() == "coords"){
                             xml.readNext();
                            param.paramname="Координаты"; param.value=xml.text().toString();
                            obj.params.append(param);
                        }
                        }
                        xml.readNext();
                    }

      }
    }

    allinfo.append(obj);
    emit NewObjectData(allinfo);

}
