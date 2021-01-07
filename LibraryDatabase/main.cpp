#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QLocale::setDefault(QLocale::Polish);

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
