#include "create_account.h"
#include "ui_create_account.h"
#include "username.h"
#include <fstream>
#include <iostream>
#include <QMessageBox>
create_account::create_account(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::create_account)
{
    this->setFixedSize(355 , 155) ;
    float num;
    string username,name , pasword ;
    ifstream z("leaderboard of sudoku game.txt" , ios::in | ios::binary);
    for(int i=0 ; ! z.eof() ; i++)
    {
        if(i%3==0)
        {
            z>>name;
            if(this->names[j-1]== name)
                break;
            this->names[j]=name;
            j++;
        }

        else if(i%3==1)
        {
            z >> pasword ;
            this->paswords[k] = pasword ;
            k++ ;
        }
        else
        {
            z>>num;
            this->scores[m]=num;
            m++;

        }

    }
    z.close();
    for(int p=0 ; p<j-1 ; p++)
        for(int l=p+1 ; l<j ; l++)
            if(scores[l] > scores[p])
            {
                int t=scores[l] ;
                scores[l]=scores[p];
                scores[p]=t;
                string f=names[l];
                names[l]=names[p];
                names[p]=f;
                string u = paswords[l] ;
                paswords[l] = paswords[p] ;
                paswords[p] = u ;
            }
    for(int i =0 ; i<100 ; i++)
        sc[i] = to_string(scores[i]) ;
    ui->setupUi(this);
}

create_account::~create_account()
{
    delete ui;
}

void create_account::on_pushButton_clicked()
{

    if(this->ui->lineEdit->text() =="" || this->ui->lineEdit_2->text() == "" || this->ui->lineEdit->text() ==" ")
    {
           QMessageBox::critical( this , tr("File is required" ) , tr("Enter your password or username")) ;
    }
    else
    {
        bool r(true);
            for(int i=0 ;i<j; i++)
            {
                if(this->ui->lineEdit->text().toStdString() == this->names[i])
                {
                    r = false ;
                    QMessageBox::critical( this , tr("wrong username" ) , tr("Username taken! Try another")) ;
                }
            }
        if(r!=false)
        {
            this->names[j] = this->ui->lineEdit_2->text().toStdString();
            this->paswords[k] = this->ui->lineEdit->text().toStdString() ;
            this->scores[m]=0;
            ofstream x("leaderboard of sudoku game.txt" , ios::app | ios::binary);
            x << this->ui->lineEdit->text().toStdString() << " " << this->ui->lineEdit_2->text().toStdString() << " " << 0 << endl;
            x.close();
            this->close();
            username *s = new username ;
            s->show();
        }
    }

}

void create_account::on_pushButton_2_clicked()
{
    this->close() ;
    username *u = new username;
    u->show() ;
}
