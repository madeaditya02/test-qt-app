#include "windowtambah.h"
#include "ui_windowtambah.h"
#include "window2.h"
#include "datamahasiswa.h"

WindowTambah::WindowTambah(DataMahasiswa *dataMhs, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WindowTambah)
{
    this->dataMhs = dataMhs;
    ui->setupUi(this);
}

WindowTambah::~WindowTambah()
{
    delete ui;
}

void WindowTambah::on_submitButton_clicked()
{
    // qInfo()<<dataMhs->head->nama;
    QString nama = ui->inputNama->text();
    QString nim = ui->inputNIM->text();
    dataMhs->insertData(nama, nim);
    Window2 *w2 = new Window2(dataMhs);
    w2->show();
    this->close();
}


void WindowTambah::on_cancelButton_clicked()
{
    Window2 *w2 = new Window2(dataMhs);
    w2->show();
    this->close();
}

