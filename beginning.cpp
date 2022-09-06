#include "beginning.h"
#include "ui_beginning.h"
#include "username.h"
#include "table.h"
#include<QTableWidget>
#include<QLabel>
#include<QPushButton>
#include <QMessageBox>
Beginning::Beginning(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Beginning)
{
	this->setFixedSize(350 , 320) ;
    ui->setupUi(this);
}

Beginning::~Beginning()
{
    delete ui;
}

void Beginning::on_pushButton_2_clicked()
{
    this->close();
    username *w = new username ;
    w->show();
}

void Beginning::on_pushButton_3_clicked()
{
     QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Test", "Quit?",
                                     QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes)
     {
         this->close();
     }
     else
     {

     }
}

void Beginning::on_pushButton_clicked()
{
    table *w = new table ;
    w->show() ;
    this->close();
}
