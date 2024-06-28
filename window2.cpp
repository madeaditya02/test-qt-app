#include "window2.h"
#include "ui_window2.h"
#include "QPushButton"
// #include "my-definitions.h"
#include "datamahasiswa.h"
#include<QDebug>
#include "mainwindow.h"
#include "windowtambah.h"

Window2::Window2(DataMahasiswa *dataMhs, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Window2)
{
    // dataMhs = getDataMahasiswa();
    this->dataMhs = dataMhs;
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    QStringList columnNames;
    columnNames<<"Nama"<<"NIM"<<"Aksi";
    // mhsResult dataMhs = getData();
    // struct Mahasiswa *mhs = dataMhs.data;
    dataMhs->cetakData();
    ui->tableWidget->setHorizontalHeaderLabels(columnNames);
    refreshTable();
    // for (int i = 0; i < 10; ++i) {
    //     QTableWidgetItem* item = new QTableWidgetItem();
    //     // item->setText(QString::fromStdString(mhs->nama));
    //     item->setText(QString::fromStdString("Made Aditya"));
    //     ui->tableWidget->setItem(i, 0, item);
    //     QTableWidgetItem* item2 = new QTableWidgetItem();
    //     // item2->setText(QString::fromStdString(mhs->nim));
    //     item2->setText("2308561015");
    //     ui->tableWidget->setItem(i, 1, item2);
    //     QPushButton* btn_delete;
    //     btn_delete = new QPushButton();
    //     btn_delete->setText("Delete");
    //     ui->tableWidget->setCellWidget(i,2,(QWidget*)btn_delete);
    //     // mhs = mhs->next;
    //     i++;
    // }
    finishRenderTable = true;
}

Window2::~Window2()
{
    delete ui;
}

void Window2::refreshTable()
{
    // searchResult = dataMhs->head;
    struct Mahasiswa *mhs = dataMhs->head;
    int i = 0;
    ui->tableWidget->setRowCount(dataMhs->count-1);
    QTableWidget *currentTable = ui->tableWidget;
    while (mhs != NULL) {
        if (mhs->nim == searchQuery || searchQuery == "") {
            QTableWidgetItem* item = new QTableWidgetItem();
            item->setText(mhs->nama);
            // item->setText(QString::fromStdString("Made Aditya"));
            ui->tableWidget->setItem(i, 0, item);
            QTableWidgetItem* item2 = new QTableWidgetItem();
            item2->setText(mhs->nim);
            // item2->setText("2308561015");
            ui->tableWidget->setItem(i, 1, item2);
            QPushButton *btn_delete;
            btn_delete = new QPushButton();
            btn_delete->setText("Delete");
            // connect(btn_delete, &QPushButton::released, this, Window2::handleButtonDelete);
            connect(btn_delete, &QPushButton::released, this,
                    [this, mhs]()
                    {
                        // handleButtonDelete(i);
                        handleButtonDelete(mhs->nim);
                    });
            ui->tableWidget->setCellWidget(i,2,(QWidget*)btn_delete);
            // ui->tableWidget->setItem(i,2,(QTableWidgetItem*)btn_delete);
            i++;
            // if (searchResult) {
            //     searchResult = mhs;
            // }
            // else
            //     searchResult->ne
        }
        mhs = mhs->next;
    }
    ui->tableWidget->setRowCount(i);
    qInfo()<<i;
}

void Window2::on_tableWidget_cellChanged(int row, int column)
{
    if (finishRenderTable) {
        int i = 0;
        QString val = ui->tableWidget->item(row, column)->text();
        dataMhs->updateData(row, column, val);
    }
}


void Window2::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    // qInfo()<<currentRow<<currentColumn<<previousRow<<previousColumn;
}


void Window2::on_tableWidget_cellEntered(int row, int column)
{
    // qInfo()<<row<<column;
}


void Window2::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    // qInfo()<<item->text();
}


void Window2::on_pushButton_clicked()
{
    // MainWindow *m = new MainWindow();
    // m->show();
    WindowTambah *wt = new WindowTambah(dataMhs);
    wt->show();
    this->close();
    // this->destroy();
}

void Window2::on_tableWidget_cellActivated(int row, int column)
{
    qInfo()<<row<<" "<<column;
}


void Window2::on_tableWidget_cellClicked(int row, int column)
{
    qInfo()<<row<<" "<<column;
}


void Window2::on_tableWidget_itemClicked(QTableWidgetItem *item)
{
    qInfo()<<item->text();
}

void Window2::handleButtonDelete(QString nim) {
    // qInfo()<<nim;
    // ui->tableWidget->cellClicked(row, 2);
    // QWidget *item = (QWidget*)(sender()->parent());
    // qInfo()<<item;v
    // qInfo()<<this->parent()->objectName();
    // int row = dataMhs->deleteData(nim);
    int row = -1;
    Mahasiswa *temp = dataMhs->head;
    dataMhs->deleteData(nim);

    qInfo()<<row;
    // dataMhs->deleteData(nim);
    // ui->tableWidget->removeRow(row);
    refreshTable();
    // dataMhs->cetakData();
}

void Window2::on_searchButton_clicked()
{
    searchQuery = ui->searchInput->text();
    refreshTable();
}

