#include "FileGetterWidget.h"
#include "ui_FileGetterWidget.h"
#include <operations/parameters/StringParameter.h>
#include <Parameter.h>
#include <qfiledialog.h>
#include <util/FileUtil.h>
#include <qdebug.h>


FileGetterWidget::FileGetterWidget(Parameter *parameter, QWidget *parent):
        QWidget(parent),
        ui(new Ui::FileGetterWidget), error(false)
{
    ui->setupUi(this);
    this->parameter = dynamic_cast<StringParameter*>(parameter);

    if(this->parameter == NULL){
        throw "[Critical] - Illegal Parameter Type in FileGetterWidget!";
    }
    selectedFolder.setNameFilters(QStringList() << "*.bmp" << "*.dib" << "*.jpeg" << "*.jpg" << "*.gif" << "*.png" << "*.tif" << "*.tiff");

    reset();
}


FileGetterWidget::~FileGetterWidget()
{
    delete ui;
}

bool FileGetterWidget::apply()
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

void FileGetterWidget::reset()
{
    ui->path->setText( QString::fromStdString(parameter->getData()));
}

void FileGetterWidget::on_browse_clicked()
{
    QString selectedFilePath = QFileDialog::getOpenFileName(this,
                                                      tr("Open Image Folder"), "",
                                                      tr("JPEG (*.jpg);;PNG (*.png);;All Files (*)"));
    if(selectedFilePath.isEmpty()){
        return;
    }

    QString folderPath = FileUtil::getFolderPath(selectedFilePath);

    selectedFolder.setPath(folderPath);
    ui->files->clear();
    ui->files->addItems(selectedFolder.entryList());
    if(selectedFolder.entryList().size()>0){
        ui->files->setCurrentRow(0);
    }
}


void FileGetterWidget::on_files_currentRowChanged(int currentRow)
{
    if(currentRow > -1){
        QString selectedFile = ui->files->item(currentRow)->text();
        QString filePath = selectedFolder.filePath(selectedFile);
        ui->path->setText(filePath);
    }
}
