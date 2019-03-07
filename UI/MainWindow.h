//
// Created by Dominika on 28.02.2019.
//

#ifndef HIPSEGMENTER_MAINWINDOW_H
#define HIPSEGMENTER_MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <ImageFormat.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static int run(int argc, char *argv[]);
    ~MainWindow();

private:
    Ui_MainWindow *ui;
};


#endif //HIPSEGMENTER_MAINWINDOW_H
