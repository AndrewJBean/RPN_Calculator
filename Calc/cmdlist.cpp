#include <QApplication>
#include <QKeyEvent>

#include "cmdlist.h"

CmdList::CmdList(QFrame *parent)
    : QListWidget(parent)
{

}

void CmdList::keyPressEvent(QKeyEvent *event)
{
   if (event->key() == Qt::Key_Return)
   {
       Q_EMIT returnPressed();
   }
}
