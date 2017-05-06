#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iterator=0;
    sw = new SettingsWindow();
        //кнопки
        QObject::connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(next()));
        QObject::connect(ui->btnPrev, SIGNAL(clicked()), this, SLOT(prev()));
        QObject::connect(ui->btnSettings, SIGNAL(clicked()), this, SLOT(onShowSettings()));
        QObject::connect(sw, SIGNAL(SettingsChange()), this, SLOT(onSettingsChanged()));
        //установка таймера
        timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(next()));
        timer->start(settings.time1*1000);

}


void MainWindow::onNewObjectData(const QList<Object> &NewInfo){
//if (NewInfo.count()>=settings.count()) {
CurObjectInfo.clear();
CurObjectInfo.append(NewInfo);
//}
}

void MainWindow::onShowSettings() {
    sw->show();
}

void MainWindow::onSettingsChanged() {
    settings.Refresh();
    timer->start(settings.time1*1000);
    emit SettingsChange();
}

MainWindow::~MainWindow()
{
    model.clear();
    timer->stop();
    timer->deleteLater();
    CurObjectInfo.clear();
    settings.~Settings();
    delete ui;
}

void MainWindow::next() {
    iterator=iterator+1;
    if (iterator>=settings.count()-1) iterator=0;
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
    if (iterator<=0) iterator=settings.count()-1;
    model.clear();
    ui->lblObject->setText(CurObjectInfo.value(iterator).objname);
    for (int i=0; i<CurObjectInfo.value(iterator).params.count(); i++){
        QStandardItem *item = new QStandardItem(
                    tr("%0, %1")
                    .arg(CurObjectInfo.value(iterator).params.value(i).paramname)
                    .arg(CurObjectInfo.value(iterator).params.value(i).value.toString()));

    model.appendRow(item);
    }
    ui->tableView->setModel(&model);
}
