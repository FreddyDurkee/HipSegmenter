#include <QPushButton>
#include <QLineEdit>
#include <iostream>
#include "SettingsDialog.h"
#include "ui_settingsdialog.h"
#include "FileSettingWidget.h"

SettingsDialog::~SettingsDialog() {
    delete ui;
}


void SettingsDialog::createConfigRow(Parameter *config) {
    if (config->getParameterType() == Parameter::Type::File) {
        ui->widgetLayout->addWidget(new FileSettingWidget(config, this));
    } else {
        throw "[Critical] Widget type defined in config doesn't match any setting dialog in SettingDialog!";
    }
}

SettingsDialog::SettingsDialog(BlockConfig *blockConfig, QString windowTitle, QWidget *parent) : QDialog(parent),
                                                                            ui(new Ui::SettingsDialog),
                                                                            blockConfig(blockConfig) {
    ui->setupUi(this);
    setWindowTitle(windowTitle);
    map<string, Parameter *> params = blockConfig->getParams();
    auto it = params.begin();

    while (it != params.end()) {
        std::string parameterName = it->first;
        Parameter* description = it->second;
        createConfigRow(description);
        it++;
    }

    this->ui->buttonBox->addButton(QDialogButtonBox::Apply );
    QObject::connect(ui->buttonBox->button(QDialogButtonBox::Apply), &QPushButton::clicked,
                     this, &SettingsDialog::apply);
    QObject::connect(this, &QDialog::accepted,
                     this, &SettingsDialog::apply);
    QObject::connect(this, &QDialog::rejected,
                     this, &SettingsDialog::cleanup);
}

void SettingsDialog::apply() {
    for(int i=0; i<ui->widgetLayout->count();i++){
        ParameterChanger* changer = dynamic_cast<ParameterChanger*>(ui->widgetLayout->itemAt(i)->widget());
        changer->apply();
    }
}

void SettingsDialog::cleanup() {
    for(int i=0; i<ui->widgetLayout->count();i++){
        ParameterChanger* changer = dynamic_cast<ParameterChanger*>(ui->widgetLayout->itemAt(i)->widget());
        changer->reset();
    }
}





