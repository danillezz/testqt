#include "database.h"

Database::Database(){
    int i,j,k=0;
                dbase=QSqlDatabase::addDatabase("QSQLITE");
                dbase.setDatabaseName("Test.sqlite");
                dbase.open();

    QSqlQuery qry1,qry2,qry3;

                qrycity = QSqlQuery("select * from Objects");

                if (qrycity.isActive())
                    qrycity.first();
                else
                return;


                qry1.exec("delete from Mirror");
                qry1.exec("select * from Objects");
                qry1.first();

    QString str_insert = "INSERT INTO Mirror(ID, ObjId, ParamId, Value) "
                        "VALUES (%1, '%2', %3, %4);";
    QString str;
                do  {
                    qry2.clear();
                    qry2.exec("select * from Params");
                    qry2.first();
                     do {
                     k=k+1;
                     i=qry1.value(0).toInt();
                     j=qry2.value(0).toInt();
                        str = str_insert.arg(k)
                        .arg(i)
                        .arg(j)
                        .arg(k);
                        qry3.exec(str);
                        } while(qry2.next());
                } while(qry1.next());
    dbase.commit();

    //------------Синхронизация с сайтом---------------------------------------------------
    ParseJSON();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(ParseJSON()));
    timer->start(30000);

}

Database::~Database(){
    dbase.close();
}

QString Database::GetNextCity() {
   if (qrycity.next()) {
    return qrycity.value(1).toString();
   }
   else {
   qrycity.first();
   return qrycity.value(1).toString();
   }
}

QString Database::GetPrevCity() {
   if (qrycity.previous()) {
    return qrycity.value(1).toString();
   }
   else {
   qrycity.last();
   return qrycity.value(1).toString();
   }
}

void Database::GetWeather(QSqlQueryModel* model){
QString obj_id, str;
    obj_id=qrycity.value(0).toString();
    str="select p.Param as \"Параметр\",m.Value as \"Значение\" from Params p, Mirror m"
        " where m.ObjId="+obj_id+
        " and m.ParamId=p.ID"
        " order by p.ID";
    model->setQuery(str);
}


void Database::ParseJSON(){

  QEventLoop loop;
  QNetworkAccessManager *networkManager;
  networkManager = new QNetworkAccessManager();
  QNetworkReply *reply;
  QSqlQuery qryloop, qry;
    //-----------------Выбор всех объектов----------------------------------------------
  qryloop.exec("select * from Objects");
  while (qryloop.next()) {
        QString str ="http://api.openweathermap.org/data/2.5/weather?q={"
                +qryloop.value(2).toString()+
                "}&APPID=0ba9896801666e58519b0d89ccc2181e";
        //-----------------Запрос на сайт---------------------------------------------------
        reply=networkManager->get(QNetworkRequest(QUrl(str)));
        connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
        loop.exec();

  if(!reply->error()){

        //----------------Парсим JSON-------------------------------------------------------
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

           if(!document.isEmpty()) {
           // Забираем из документа все объекты
           QJsonObject root = document.object();
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

           // Записываем в базу
           str = "update Mirror set Value="+QString::number(temp)+
                   " where ObjId="+qryloop.value(0).toString()+" and ParamId=1";
           qry.exec(str);
           str = "update Mirror set Value='"+clouds+
                   "' where ObjId="+qryloop.value(0).toString()+" and ParamId=2";
           qry.exec(str);
           str = "update Mirror set Value='"+DTs.toString("dd.MM.yyyy hh:mm:ss")+
                   "' where ObjId="+qryloop.value(0).toString()+" and ParamId=3";
           qry.exec(str);
           str = "update Mirror set Value="+QString::number(wind)+
                   " where ObjId="+qryloop.value(0).toString()+" and ParamId=4";
           qry.exec(str);
           str = "update Mirror set Value="+QString::number(pressure)+
                   " where ObjId="+qryloop.value(0).toString()+" and ParamId=5";
           qry.exec(str);
           str = "update Mirror set Value="+QString::number(humidity)+
                   " where ObjId="+qryloop.value(0).toString()+" and ParamId=6";
           qry.exec(str);
           str = "update Mirror set Value='"+sunrises.toString("hh:mm:ss")+
                   "' where ObjId="+qryloop.value(0).toString()+" and ParamId=7";
           qry.exec(str);
           str = "update Mirror set Value='"+sunsets.toString("hh:mm:ss")+
                   "' where ObjId="+qryloop.value(0).toString()+" and ParamId=8";
           qry.exec(str);
           str = "update Mirror set Value='"+coords+
                   "' where ObjId="+qryloop.value(0).toString()+" and ParamId=9";
           qry.exec(str);

    }
    //----------------------------------------------------------------------------------
    }
    reply->deleteLater();
    }

}
