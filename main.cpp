#include "mainwindow.h"
#include "graphwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Form f;
    w.show();
//    f.show();

    return a.exec();
}
