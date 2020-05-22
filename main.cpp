#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication qguiapp(argc, argv);

    MainWindow *window = new MainWindow;
    window->show();

    return qguiapp.exec();
}
