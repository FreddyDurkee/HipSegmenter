//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_BLOCKWIDGET_H
#define HIPSEGMENTER_BLOCKWIDGET_H

#include <QWidget>
#include <memory>
#include "ui_blockwidget.h"
#include "operations/BlockOperation.h"

using namespace std;

class BlockWidget : public QWidget {
Q_OBJECT

public:
    explicit BlockWidget(QString name, BlockOperation *blkOperation, QWidget *parent = 0);

    ~BlockWidget();

    void execute();

    QString getText() const;

    static shared_ptr<BlockWidget> sptr(QString qString, BlockOperation *pOperation);

    static unique_ptr<BlockWidget> uptr(QString qString, BlockOperation *pOperation);

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:

    void on_settingButton_clicked();

private:
    Ui::BlockWidget *ui;
    QString text;
    BlockOperation *operation;
};


using BlockWidgetSptr = shared_ptr<BlockWidget>;
using BlockWidgetUptr = unique_ptr<BlockWidget>;

#endif //HIPSEGMENTER_BLOCKWIDGET_H
