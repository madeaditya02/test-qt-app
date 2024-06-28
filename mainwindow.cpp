#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "window2.h"
#include <QDebug>
#include <QtWidgets>
#include <QApplication>
#include "datamahasiswa.h"

#include <iostream>
using namespace std;

// struct Mahasiswa {
//     string nama;
//     string nim;
//     int ukt;
// };

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    DataMahasiswa *dataMhs = new DataMahasiswa();
    // DataMahasiswa *dataMhs = new DataMahasiswa();
    // qInfo()<<globalN;
    this->dataMhs = dataMhs;
    dataMhs->cetak();
    ui->setupUi(this);
    // qInfo()<<qApp->property("nama").toString();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_submitBtn_clicked()
{
    QString nama = ui->inputNama->text();
    Window2 *w2 = new Window2(dataMhs);
    ui->inputNIM->text();
    ui->resultInput->insert(nama);
    w2->show();
    this->close();
}

