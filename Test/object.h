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

struct ObjectSettings {
int id;
QString objname;
QString engname;
QString filename;
};

#endif // OBJECT_H
