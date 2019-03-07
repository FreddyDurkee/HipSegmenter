//
// Created by Dominika on 28.02.2019.
//
#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui_MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::run(int argc, char **argv) {
    QApplication app(argc,argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
