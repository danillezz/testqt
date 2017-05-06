#include "infohandler.h"

InfoHandler::InfoHandler(MainWindow *v):
    obj(new ObjectsInfo),
    win(v)
{
 connect(obj,&ObjectsInfo::NewObjectData,win,&MainWindow::NewObjectData);
}
