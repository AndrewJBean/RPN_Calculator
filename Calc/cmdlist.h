#pragma once

#include <QListWidget>

class CmdList : public QListWidget
{
    Q_OBJECT

public:
    CmdList(QFrame *parent = 0);

signals:
    void returnPressed();

protected:
    void keyPressEvent(QKeyEvent * e);
};
