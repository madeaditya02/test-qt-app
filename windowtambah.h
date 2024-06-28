#ifndef WINDOWTAMBAH_H
#define WINDOWTAMBAH_H

#include <QMainWindow>
#include "datamahasiswa.h"

namespace Ui {
class WindowTambah;
}

class WindowTambah : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowTambah(DataMahasiswa *dataMhs, QWidget *parent = nullptr);
    ~WindowTambah();

private slots:
    void on_submitButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::WindowTambah *ui;
    DataMahasiswa *dataMhs;
};

#endif // WINDOWTAMBAH_H
