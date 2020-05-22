#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication qguiapp(argc, argv);

    QLabel *label = new QLabel("Hello World!");
    label->show();

    return qguiapp.exec();
}
