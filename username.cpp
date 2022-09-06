#include "username.h"
#include "widget.h"
#include "ui_username.h"
#include "widget.h"
#include "ui_widget.h"
#include "create_account.h"
#include <fstream>
#include <iostream>
#include <string>
#include <QMessageBox>
using namespace std;
username::username(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::username)
{
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
    ui->setupUi(this);
    this->setFixedSize(355 , 155) ;

}
void username::setname(string x , int y)
{
    this->names[y] = x ;
}

username::~username()
{   
    delete ui;
}

void username::on_pushButton_clicked()
{
    bool n=false ;
        if(this->ui->pasword->text() =="" || this->ui->username_2->text() == "")
        {
            QMessageBox::critical( this , tr("File is required" ) , tr("Enter your password or username")) ;
        }
        else
        {
            for(int g=0 ;g<j; g++)
            {
                if(this->ui->username_2->text().toStdString() == this->names[g])
                {
                    if(this->ui->pasword->text().toStdString() == this->paswords[g])
                    {
                        user2=this->ui->username_2->text().toStdString();
                        n = true ;
                        this->close();
                        Widget *s = new Widget ;
                        s->user = QString::fromStdString(user2)  ;
                        s->j = this->j ;
                        s->show();
                    }
                }
            }
            if(n == false)
                QMessageBox::critical(this , tr("wrong username" ) , tr("Incorrect username or pasword !")) ;
        }
}

void username::on_pushButton_2_clicked()
{
    create_account *c = new create_account;
    this->close();
    c->show() ;

}
