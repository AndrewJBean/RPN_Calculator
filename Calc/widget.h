#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "rpn.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void setName(const QString &name);
    QString name() const;

private slots:
    void on_lineEdit_returnPressed();
    void on_listWidget_returnPressed();

private:
    Ui::Widget *ui;
    RPN calc;
};

#endif // WIDGET_H
