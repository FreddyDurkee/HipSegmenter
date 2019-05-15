#ifndef OPERATIONBLOCKWIDGET_H
#define OPERATIONBLOCKWIDGET_H

#include <QWidget>
#include "ui_operationblockwidget.h"

using namespace std;

class OperationBlockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OperationBlockWidget(QWidget *parent = 0);
    ~OperationBlockWidget();

    static OperationBlockWidget* of(const QString &text);

    void  setText(QString text);

    void execute();

    QString  getText() const;

    QPixmap getMini(){
        return this->grab();
    }

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void on_settingButton_clicked();

private:
    Ui::OperationBlockWidget *ui;
    QString text;
};

#endif // OPERATIONBLOCKWIDGET_H
