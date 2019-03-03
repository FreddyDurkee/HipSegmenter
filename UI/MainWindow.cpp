//
// Created by Dominika on 28.02.2019.
//

#include "MainWindow.h"
#include <QApplication>

MainWindow::MainWindow() {

}

int MainWindow::run(int argc, char **argv) {
    QApplication app(argc,argv);
    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
