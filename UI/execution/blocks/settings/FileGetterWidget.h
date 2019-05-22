#ifndef FILEGETTERWIDGET_H
#define FILEGETTERWIDGET_H

#include <QDir>
#include <QWidget>
#include <operations/parameters/StringParameter.h>
#include "ParameterChanger.h"

namespace Ui {
class FileGetterWidget;
}

class FileGetterWidget : public QWidget, public ParameterChanger
{
    Q_OBJECT

    // ParameterChanger interface
public:
    bool apply() override;
    void reset() override;

public:
    explicit FileGetterWidget(Parameter* parameter, QWidget *parent = nullptr);
    ~FileGetterWidget() override;

private slots:
    void on_browse_clicked();
    void on_files_currentRowChanged(int currentRow);

private:
    Ui::FileGetterWidget *ui;
    StringParameter* parameter;
    QDir selectedFolder;
    bool error;

};

#endif // FILEGETTERWIDGET_H
