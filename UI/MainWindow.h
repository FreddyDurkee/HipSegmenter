//
// Created by Dominika on 28.02.2019.
//

#ifndef HIPSEGMENTER_MAINWINDOW_H
#define HIPSEGMENTER_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public  QMainWindow{
Q_OBJECT

public:
    MainWindow();
    static int run(int argc, char *argv[]);

};


#endif //HIPSEGMENTER_MAINWINDOW_H
