#ifndef FILESETTINGWIDGET_H
#define FILESETTINGWIDGET_H

#include <QDir>
#include <QWidget>
#include <operations/parameters/StringParameter.h>
#include "ParameterChanger.h"

namespace Ui {
class FileSettingWidget;
}

class FileSettingWidget : public QWidget, public ParameterChanger
{
    Q_OBJECT

    // ParameterChanger interface
public:
    bool apply() override;
    void reset() override;

public:
    explicit FileSettingWidget(Parameter* parameter, QWidget *parent = nullptr);
    ~FileSettingWidget() override;

private slots:
    void on_browse_clicked();
    void on_files_currentRowChanged(int currentRow);

private:
    Ui::FileSettingWidget *ui;
    StringParameter* parameter;
    QDir selectedFolder;
    bool error;

};

#endif // FILESETTINGWIDGET_H
