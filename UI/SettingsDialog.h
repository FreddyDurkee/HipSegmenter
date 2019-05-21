#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <string>
#include <operations/parameters/Parameter.h>
#include "ui_settingsdialog.h"
#include <QVBoxLayout>
#include <operations/BlockConfig.h>

using namespace std;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(BlockConfig* blockConfig, QString windowTitle, QWidget *parent = 0);
    ~SettingsDialog();

private:
    BlockConfig* blockConfig;
    void createConfigRow(Parameter *);
    Ui::SettingsDialog* ui;
    void apply();
    void cleanup();
};

#endif // SETTINGSDIALOG_H
