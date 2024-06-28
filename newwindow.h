#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include <QDialog>
#include "datamahasiswa.h"

namespace Ui {
class NewWindow;
}

class NewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewWindow(DataMahasiswa *dataMhs, QWidget *parent = nullptr);
    ~NewWindow();

private:
    Ui::NewWindow *ui;
};

#endif // NEWWINDOW_H
