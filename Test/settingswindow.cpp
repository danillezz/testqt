#include "settingswindow.h"
#include "ui_settingswindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

    dbase=QSqlDatabase::addDatabase("QSQLITE");
    dbase.setDatabaseName("Test.sqlite");
    dbase.open();

    model = new QSqlTableModel();
    model->setTable("Objects");
    model->select();

    ui->tableView->setModel(model);

    QSqlQuery qry;
    qry.exec("select * from Times order by ID");
    qry.next();
        ui->spinBox->setValue(qry.value(2).toInt());
    qry.next();
        ui->spinBox_2->setValue(qry.value(2).toInt());

    ui->tableView->resizeColumnsToContents();
    connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(onOk()));

}

SettingsWindow::~SettingsWindow()
{
    dbase.close();
    model->deleteLater();
    delete ui;
}

void SettingsWindow::onOk() {

 QSqlQuery qry;
    qry.exec("update Times set Value="+QString(ui->spinBox->value())+" where ID=1");
    qry.exec("update Times set Value="+QString(ui->spinBox_2->value())+" where ID=2");
    qry.exec("select * from Objects");
    qry.first();
 emit SettingsChange(ui->spinBox->value(), qry.record().count());
    qry.clear();

 this->hide();

 }

void SettingsWindow::Refresh() {

    QSqlQuery qry;
    qry.exec("select * from Times order by ID");
    qry.next();
        ui->spinBox->setValue(qry.value(2).toInt());
    qry.next();
        ui->spinBox_2->setValue(qry.value(2).toInt());

}


