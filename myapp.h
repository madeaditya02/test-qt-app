#ifndef MYAPP_H
#define MYAPP_H

#include <QApplication>

class MyApp : public QApplication
{
public:
    // MyApp();
    ~MyApp() {
        qInfo()<<"Closed";
    }
};

#endif // MYAPP_H
