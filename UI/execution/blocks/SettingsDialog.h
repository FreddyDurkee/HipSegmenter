#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <string>
#include <Parameter.h>
#include "ui_settingsdialog.h"
#include <QVBoxLayout>
#include <OperationConfig.h>

using namespace std;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(OperationConfig* blockConfig, QString windowTitle, QWidget *parent = 0);
    ~SettingsDialog();

private:
    OperationConfig* operationConfig;
    void createConfigRow(Parameter *);
    Ui::SettingsDialog* ui;
    void apply();
    void cleanup();
};

#endif // SETTINGSDIALOG_H
