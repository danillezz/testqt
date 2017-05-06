#ifndef OBJECT_H
#define OBJECT_H
#include <QString>
#include <QHash>
#include <QList>

struct ObjectParam {
QString paramname;
QVariant value;
};

struct Object {

QString objname;
QList <ObjectParam> params;

};



#endif // OBJECT_H
