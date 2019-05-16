//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_BLOCKWIDGET_H
#define HIPSEGMENTER_BLOCKWIDGET_H

#include <QWidget>
#include "ui_blockwidget.h"
#include "BlockOperation.h"

class BlockWidget  : public QWidget
{
    Q_OBJECT

public:
    explicit BlockWidget(QString name, BlockOperation *blkOperation, QWidget *parent = 0);
    ~BlockWidget();

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
    Ui::BlockWidget *ui;
    QString text;
    BlockOperation *operation;
};


#endif //HIPSEGMENTER_BLOCKWIDGET_H
