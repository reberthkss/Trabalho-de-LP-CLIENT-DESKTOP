#include "mainwindow.h"
#include "fm.h"
#include <QMessageBox>

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
