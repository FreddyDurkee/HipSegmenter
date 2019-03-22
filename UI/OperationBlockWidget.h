#ifndef OPERATIONBLOCKWIDGET_H
#define OPERATIONBLOCKWIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include "ui_operationblockwidget.h"

class OperationBlockWidget : public QWidget, public QListWidgetItem
{
    Q_OBJECT

public:
    explicit OperationBlockWidget(QListWidget *parent = 0);
    ~OperationBlockWidget();

    static OperationBlockWidget* of(const QString &text);

    void  setText(QString text);

    QString  getText() const;

    QPixmap getMini(){
        return this->grab();
    }

private:
    Ui::OperationBlockWidget *ui;
    QString text;
};

#endif // OPERATIONBLOCKWIDGET_H
