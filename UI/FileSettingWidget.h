#ifndef FILESETTINGWIDGET_H
#define FILESETTINGWIDGET_H

#include <QWidget>
#include <operations/StringParameter.h>
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
    ~FileSettingWidget();

private:
    Ui::FileSettingWidget *ui;
    StringParameter* parameter;
    bool error;

};

#endif // FILESETTINGWIDGET_H
