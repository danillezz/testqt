#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iterator=0;
    time=5;
        //кнопки
        QObject::connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(next()));
        QObject::connect(ui->btnPrev, SIGNAL(clicked()), this, SLOT(prev()));
        QObject::connect(ui->btnSettings, SIGNAL(clicked()), this, SLOT(onShowSettings()));
        sw = new SettingsWindow();
        connect(sw,&SettingsWindow::SettingsChange,this,&MainWindow::onSettingsChanged);
        //установка таймера
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(next()));
        sw->onOk();
}


void MainWindow::onNewObjectData(const Object &NewInfo){
int nom;

if (CurObjectInfo.count()>=objectscount){
for (int i=0; i<CurObjectInfo.count();i++)  {
if (NewInfo.objname==CurObjectInfo.value(i).objname)
    nom=i;
}
CurObjectInfo.insert(nom,NewInfo);}
else {
CurObjectInfo.append(NewInfo);
}

}

void MainWindow::onShowSettings() {
    sw->Refresh();
    sw->show();
}

void MainWindow::onSettingsChanged(const int newtime, const int newcount) {
time=newtime;
objectscount=newcount;
if (time*1000!=timer->interval())
    timer->start(time*1000);
}

MainWindow::~MainWindow()
{
    model.clear();
    timer->stop();
    timer->deleteLater();
    CurObjectInfo.clear();
    delete ui;
}

void MainWindow::next() {
    iterator=iterator+1;
    if (iterator>=CurObjectInfo.count()-1) iterator=0;
    model.clear();
    ui->lblObject->setText(CurObjectInfo.value(iterator).objname);
    for (int i=0; i<CurObjectInfo.value(iterator).params.count(); i++){
        QStandardItem *item_col_01 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).paramname);
        QStandardItem *item_col_02 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).value.toString());
        model.appendRow(QList<QStandardItem*>() << item_col_01 << item_col_02);
    }
    ui->tableView->setModel(&model);
}

void MainWindow::prev() {
    iterator=iterator-1;
    if (iterator<=0) iterator=CurObjectInfo.count()-1;
    model.clear();
    ui->lblObject->setText(CurObjectInfo.value(iterator).objname);
    for (int i=0; i<CurObjectInfo.value(iterator).params.count(); i++){
        QStandardItem *item_col_01 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).paramname);
        QStandardItem *item_col_02 = new QStandardItem(CurObjectInfo.value(iterator).params.value(i).value.toString());
        model.appendRow(QList<QStandardItem*>() << item_col_01 << item_col_02);
    }
    ui->tableView->setModel(&model);
}
