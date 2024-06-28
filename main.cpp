#include "mainwindow.h"

#include <QApplication>
#include "QDebug"
#include "datamahasiswa.h"
#include "myapp.h"

// struct Mahasiswa
// {
//     QString nama;
//     struct Mahasiswa *next;
//     Mahasiswa(QString nama) {
//         // qInfo()<<nama;
//         this->nama = nama;
//     }
// };

int main(int argc, char *argv[])
{
    int n = 10;
    QApplication a(argc, argv);
    // MyApp a(argc, argv);
    MainWindow w;
    w.show();
    // struct Mahasiswa *mhs = new Mahasiswa("Aditya");
    // struct Mahasiswa *mhs2 = new Mahasiswa("Bisma");
    // mhs->next = mhs2;
    // mhs2->next = NULL;
    // qInfo()<<mhs->next->nama;
    a.setProperty("nama", "Aditt");
    return a.exec();
}
