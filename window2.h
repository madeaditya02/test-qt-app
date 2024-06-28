#ifndef WINDOW2_H
#define WINDOW2_H
#include "QTableWidgetItem"

#include <QMainWindow>
#include "datamahasiswa.h"
// #include "my-definitions.h"

namespace Ui {
class Window2;
}

class Window2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window2(DataMahasiswa *dataMhs, QWidget *parent = nullptr);
    ~Window2();

private slots:
    void handleButtonDelete(QString nim);

    // void handleButtonDelete(QTableWidgetItem *item);

    void refreshTable();

    void on_tableWidget_cellChanged(int row, int column);

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

    void on_tableWidget_cellEntered(int row, int column);

    void on_tableWidget_itemChanged(QTableWidgetItem *item);

    void on_pushButton_clicked();

    void on_tableWidget_cellActivated(int row, int column);

    void on_tableWidget_cellClicked(int row, int column);

    void on_tableWidget_itemClicked(QTableWidgetItem *item);

    void on_searchButton_clicked();

private:
    Ui::Window2 *ui;
    bool finishRenderTable = false;
    DataMahasiswa *dataMhs;
    DataMahasiswa *searchResult;
    QString searchQuery;
    // mhsResult dataMhs;
    // mhsResult getDataMahasiswa() {
    //     struct Mahasiswa *head = new Mahasiswa(), *temp = new Mahasiswa();
    //     // head = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    //     head->nama = "I Kadek Bisma Yoga";
    //     head->nim = "2308561015";
    //     // head->nama = QString::fromStdString(nama);
    //     // head->nim = QString::fromStdString("2308561015");
    //     temp = head;
    //     int c = 1;
    //     for (int i = 0; i<9; i++) {
    //         struct Mahasiswa *node = new Mahasiswa();
    //         // node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
    //         // node->nama = QString::fromStdString(i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga");
    //         // node->nim = QString::fromStdString("2308561015");
    //         node->nama = i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga";
    //         node->nim = "2308561015";
    //         node->next = NULL;
    //         temp->next = node;
    //         temp = node;
    //         c++;
    //     }
    //     mhsResult result;
    //     result.data = head;
    //     result.count = c;
    //     return result;
    // }
    // string hello;
};

#endif // WINDOW2_H
