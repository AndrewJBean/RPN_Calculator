#include "widget.h"
#include "ui_widget.h"
#include <QTextCursor>
#include <cmath>
#include <iostream>
using namespace std;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(1);
    ui->plainTextEdit->setLineWrapMode(QPlainTextEdit::NoWrap);
    ui->label->setText(">>>");
    QString setBoxText("");
    setBoxText += "Copyright (C) 2013 Andrew Joseph Bean.\n\n";
    setBoxText += "Select history items and press RETURN to\n evaluate.\n\n";
    setBoxText += "History items are evaluated in the order\n";
    setBoxText += " the selections were made.";
    ui->plainTextEdit->setPlainText(setBoxText);

    ui->lineEdit->setFocus();
    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    calc.ResetStack();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setName(const QString &name)
{
    ui->lineEdit->setText(name);
}

QString Widget::name() const
{
    return ui->lineEdit->text();
}

void Widget::on_lineEdit_returnPressed()
{
    if(calc.Compile(ui->lineEdit->text().toLatin1().data()))
    {
        ui->plainTextEdit->setPlainText("Parsing error, invalid syntax...\n");
    }
    else
    {
        calc();
        QString DispString = "";
        for(int loop=calc.GetDepth();loop>0;loop--)
        {
            int numDigits = (int)log10((double)calc.GetDepth())
                - (int)log10((double)loop);
            DispString += " <<" ;
            for(int j = numDigits;j>0;j--)
                DispString += "0";
            DispString += QString::number( loop ) + ">>  " + QString::number( calc[loop-1] ) + "\n";
        }

        if(!calc.GetDepth())
            DispString += "Empty Stack\n";
        ui->plainTextEdit->setPlainText(DispString);
        ui->plainTextEdit->moveCursor(QTextCursor::End);
        ui->plainTextEdit->centerCursor();
    }
    if(! ui->lineEdit->text().trimmed().isEmpty())
    {
        ui->listWidget->addItem(ui->lineEdit->text().trimmed());
        ui->listWidget->scrollToBottom();
    }
    ui->lineEdit->setText("");
}





void Widget::on_listWidget_returnPressed()
{
    QList<QListWidgetItem *> cmds = ui->listWidget->selectedItems();
    for(int i=0;i<cmds.size();i++)
    {
        if(!calc.Compile( cmds.at(i)->text().toStdString().c_str() ))
            calc();
    }
    QString DispString = "";
    for(int loop=calc.GetDepth();loop>0;loop--)
    {
        int numDigits = (int)log10((double)calc.GetDepth())
            - (int)log10((double)loop);
        DispString += " <<" ;
        for(int j = numDigits;j>0;j--)
            DispString += "0";
        DispString += QString::number( loop ) + ">>  " + QString::number( calc[loop-1] ) + "\n";
    }

    if(!calc.GetDepth())
        DispString += "Empty Stack\n";
    ui->plainTextEdit->setPlainText(DispString);
    ui->plainTextEdit->moveCursor(QTextCursor::End);
    ui->plainTextEdit->centerCursor();
}
