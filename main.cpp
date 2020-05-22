#include <QApplication>
#include "qawidget.h"

int main(int argc, char *argv[])
{
    QApplication qguiapp(argc, argv);

    QAWidget *widget = new QAWidget("Hello", "World");
    widget->show();

    return qguiapp.exec();
}
