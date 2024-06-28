#ifndef DATAMAHASISWA_H
#define DATAMAHASISWA_H

#include <QObject>

struct Mahasiswa
{
    QString nama;
    QString nim;
    struct Mahasiswa *next;
    struct Mahasiswa *prev;
    Mahasiswa() {}
};

class DataMahasiswa : public QObject
{
    Q_OBJECT
public:
    explicit DataMahasiswa(QObject *parent = nullptr);
    Mahasiswa *head;
    Mahasiswa *searchResult;
    int count;
    int countSearchResult;
    QString filePath = "C:/Made Aditya/Sublime Text/Belajar C - C++/qt-app/test-app/test-data.txt";
    void cetak();
    void getData();
    void insertData(QString nama, QString nim);
    void updateData(int row, int col, QString value);
    int deleteData(QString nim);
    void cetakData();
    void searchData(QString query);

signals:
};

#endif // DATAMAHASISWA_H
