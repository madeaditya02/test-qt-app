#include "newwindow.h"
#include "ui_newwindow.h"
#include "datamahasiswa.h"

NewWindow::NewWindow(DataMahasiswa *dataMhs, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewWindow)
{
    qInfo()<<dataMhs->head->nama;
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{
    delete ui;
}
