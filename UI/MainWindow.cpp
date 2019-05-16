//
// Created by Dominika on 28.02.2019.
//
#include "MainWindow.h"
#include "BlockOperation.h"
#include <QApplication>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::run(int argc, char **argv) {
    Q_INIT_RESOURCE(resource);
    QApplication app(argc,argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}

void MainWindow::on_executeButton_clicked()
{
    list<BlockOperation*> *items = ui->listWidget->getAllItems();
    //FIXME : Memory leak! Creates list by new!
    for (BlockOperation* item : *items){
        item->execute();
    }
}
