#include "datamahasiswa.h"
#include <QDebug>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QMessageBox>

DataMahasiswa::DataMahasiswa(QObject *parent)
    : QObject{parent}
{
    getData();
}

void DataMahasiswa::cetak()
{
    int row = 3;
    qInfo()<<"Hello World";
}

void DataMahasiswa::getData()
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }
    QTextStream in(&file);
    int c = 1;
    struct Mahasiswa *currentHead = NULL, *temp = NULL;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        if (currentHead == NULL) {
            currentHead = new Mahasiswa();
            currentHead->nama = fields[0];
            currentHead->nim = fields[1];
            currentHead->next = NULL;
            currentHead->prev = NULL;
            temp = currentHead;
        } else {
            struct Mahasiswa *node = new Mahasiswa();
            node->nama = fields[0];
            node->nim = fields[1];
            node->next = NULL;
            node->prev = temp;
            temp->next = node;
            temp = node;
        }
        c++;
    }
    file.close();

    // currentHead = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    // currentHead->nama = "I Kadek Bisma Yoga";
    // currentHead->nim = "2308561015";
    // currentHead->nama = QString::fromStdString(nama);
    // currentHead->nim = QString::fromStdString("2308561015");
    // temp = currentHead;
    // int c = 1;
    // for (int i = 0; i<9; i++) {
    //     struct Mahasiswa *node = new Mahasiswa();
    //     // node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    //     // node->nama = QString::fromStdString(i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga");
    //     // node->nim = QString::fromStdString("2308561015");
    //     node->nama = i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga";
    //     node->nim = "2308561015";
    //     node->next = NULL;
    //     temp->next = node;
    //     temp = node;
    //     c++;
    // }
    // qInfo()<<currentHead->nama;
    head = currentHead;
    count = c;
}

void DataMahasiswa::insertData(QString nama, QString nim)
{
    Mahasiswa *mhsBaru = new Mahasiswa();
    mhsBaru->nama = nama;
    mhsBaru->nim = nim;
    mhsBaru->next = head;
    mhsBaru->prev = NULL;
    head->prev = mhsBaru;
    head = mhsBaru;
    count++;
    QFile file(filePath);
    QString str = "";
    Mahasiswa *temp = head;
    int i = 0;
    while (temp != NULL) {
        str += temp->nama + "," + temp->nim + "\n";
        temp = temp->next;
        i++;
    }
    if(file.open(QIODevice::ReadWrite)) {
        // qInfo()<<str;
        file.write(str.toUtf8());
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

void DataMahasiswa::updateData(int row, int col, QString value)
{
    QFile file(filePath);
    QString str = "";
    Mahasiswa *temp = head;
    int i = 0;
    while (temp != NULL) {
        if (i == row) {
            if (col == 0)
                temp->nama = value;
            else if (col == 1)
                temp->nim = value;
        }
        str += temp->nama + "," + temp->nim + "\n";
        temp = temp->next;
        i++;
    }
    if(file.open(QIODevice::ReadWrite)) {
        // qInfo()<<str;
        file.write(str.toUtf8());
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
}

int DataMahasiswa::deleteData(QString nim) {
    Mahasiswa *temp = head, *hapus;
    int i = 0, deletedIndex = 0;
    bool deleted = false;
    // if (temp->nim == nim) {
    //     qInfo()<<"Delete row : "<<nim.compare(temp->nim);
    // }
    // qInfo()<<"Delete row : "<<nim.compare(temp->nim);
    QFile file(filePath);
    QString str = "";
    if(file.open(QIODevice::WriteOnly)) {
        qInfo()<<str;
        // file.write("");
        // file.write(str.toUtf8());
        QTextStream out(&file);
        // out<<str;
        while (temp != NULL) {
            if (temp->nim == nim) {
                qInfo()<<nim;
                if (temp == head) {
                    hapus = temp;
                    temp = head = head->next;
                    delete hapus;
                } else if (temp->next == NULL) {
                    hapus = temp;
                    temp->prev->next = temp->next;
                    temp = temp->next;
                    delete hapus;
                }
                else {
                    hapus = temp;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    temp = temp->next;
                    delete hapus;
                }
                count--;
                deleted = true;
            } else {
                out<<temp->nama<<","<<temp->nim<<"\n";
                temp = temp->next;
            }
            deletedIndex += deleted ? 0 : 1;
            i++;
        }
    } else {
        QMessageBox::information(0, "error", file.errorString());
    }
    file.close();
    return deletedIndex;
    // cetakData();
}

void DataMahasiswa::cetakData() {
    Mahasiswa *temp = head;
    qInfo()<<"Cetak Data Mhs";
    while (temp != NULL) {
        qInfo()<<temp->nama<<" - "<<temp->nim;
        temp = temp->next;
    }
    qInfo()<<"End of Cetak Data Mhs";
}

void DataMahasiswa::searchData(QString query) {
    searchResult = NULL;
    int i = 0;
}
