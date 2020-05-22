#include <QVBoxLayout>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    qawidget = new QAWidget(QAWidget::TEST_QALIST);
    setCentralWidget(qawidget);
}
