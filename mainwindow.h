#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window2.h"
#include "datamahasiswa.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    // MainWindow(int *globalN, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_submitBtn_clicked();

private:
    Ui::MainWindow *ui;
    DataMahasiswa *dataMhs;
};
#endif // MAINWINDOW_H
