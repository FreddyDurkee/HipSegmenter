#include "FileSettingWidget.h"
#include "ui_FileSettingWidget.h"
#include <operations/StringParameter.h>
#include <operations/Parameter.h>


FileSettingWidget::FileSettingWidget(Parameter *parameter, QWidget *parent):
        QWidget(parent),
        ui(new Ui::FileSettingWidget), error(false)
{
    ui->setupUi(this);
    this->parameter = dynamic_cast<StringParameter*>(parameter);

    if(this->parameter == NULL){
        throw "[Critical] - Illegal Parameter Type in FileSettingWidget!";
    }
    reset();
}


FileSettingWidget::~FileSettingWidget()
{
    delete ui;
}

bool FileSettingWidget::apply()
{
    string value = ui->path->text().toStdString();
    bool isValid = parameter->isValid(value);
    if(isValid){
        this->error= false;
        parameter->set(value);
        return true;
    }else{
        this->error = true;
        return false;
    }
}

void FileSettingWidget::reset()
{
    ui->path->setText( QString::fromStdString(parameter->getData()));
}
