#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtSql"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lblObject->setText(db.GetNextCity());
    db.GetWeather(&model);

    ui->tableView->setModel(&model);
    ui->tableView->setColumnWidth(1,125);

    //кнопки
    QObject::connect(ui->btnNext, SIGNAL(clicked()), this, SLOT(next()));
    QObject::connect(ui->btnPrev, SIGNAL(clicked()), this, SLOT(prev()));

    //установка таймера
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(next()));
    timer->start(5000);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::next() {
    ui->lblObject->setText(db.GetNextCity());
    db.GetWeather(&model);
    ui->tableView->setModel(&model);
}

void MainWindow::prev() {
    ui->lblObject->setText(db.GetPrevCity());
    db.GetWeather(&model);
    ui->tableView->setModel(&model);
}
