#include "widget.h"
#include "ui_widget.h"
#include "username.h"
#include "beginning.h"
#include <QToolButton>
#include <QComboBox>
#include <QDir>
#include <QFile>
#include <QGridLayout>
#include <QLabel>
#include <QStringListModel>
#include <QTextStream>
#include <QToolButton>
#include <iostream>
#include <fstream>
#include<iostream>
#include <string>
#include <windows.h>
#include<fstream>
#include <time.h>
#include<chrono>
#include<thread>
#include <QMessageBox>
QT_USE_NAMESPACE
using namespace std;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(370 , 415) ;
    this->ui->gridLayoutWidget->setEnabled(false) ;
    this->ui->gridLayoutWidget_2->setEnabled(false) ;
    this->ui->gridLayoutWidget_3->setEnabled(false) ;
    this->ui->gridLayoutWidget_4->setEnabled(false) ;
    this->ui->gridLayoutWidget_5->setEnabled(false) ;
    this->ui->gridLayoutWidget_6->setEnabled(false) ;
    this->ui->gridLayoutWidget_7->setEnabled(false) ;
    this->ui->gridLayoutWidget_8->setEnabled(false) ;
    this->ui->gridLayoutWidget_9->setEnabled(false) ;
}
Widget::~Widget()
{

    delete ui;

}
/////////////////////////////////////////////////////////////////////////////
bool rule( int tools[9][9] , int x , int y , int v)
{
    for(int i=0 ; i<9 ; i++)
    {
        if( (i != y) && (v==tools[x][i]) )
        {
            return false;
        }
        if( (i != x) && (v==tools[i][y]) )
        {
            return false;
        }
    }
    int ii= x-(x%3) ;
    int jj= y - (y%3) ;
    for(int i=ii ; i<ii+3 ; i++)
        for(int p=jj ; p<jj+3 ; p++)
        {
            if((i!=x || p!=y) && (v==tools[i][p]))
                return false;
        }
    return true;
}
/////////////////////////////////////////////////////////////////////////////
void init(int tools[9][9])
{
    for(int i=0 ; i<9 ; i++)
        for(int j=0 ; j<9 ; j++)
            tools[i][j] = 0 ;
}
/////////////////////////////////////////////////////////////////////////////
void rSudoku(int tools[9][9])
{
    init(tools) ;
    int r , temp , eror ;
    for(int i=0 ; i<9 ; i++)
        for(int p=0 ; p<9 ; p++)
        {
            eror=0 ;
            r = rand() % 10 + 1;
            if( r <= 10 )
            {
                do{
                    temp = rand()%9 + 1 ;
                    eror++ ;
                    if(eror == 20){
                        rSudoku(tools) ;
                        return;
                    }
                }while (!rule(tools , i , p , temp));
                tools[i][p] = temp ;
                }

            }
}
/////////////////////////////////////////////////////////////////////////////
int Widget::check(QToolButton  & x , int b )
{
        x.setCursor(QCursor(Qt::PointingHandCursor));
		if(tools[b/9][b%9 -1] == x.text().toInt())
			return 1;
//		if(x.text().toInt() == 1)
//			return 1;
        else
            return 0;
}

void Widget::fill_tools()
{

}
/////////////////////////////////////////////////////////////////////////////

void Widget::add_setText (QToolButton & x )
{
    int a= x.text().toInt();
    a++;
    x.setText(QString::number(a));
    if(a==10)
    {
        a=1;
        x.setText(QString::number(a));
    }
}
/////////////////////////////////////////////////////////////////////////////

void Widget::readfile(QToolButton & x , int a)
{

    x.setEnabled(false) ;
    x.setText(QString::number(tools[a/9][a%9 -1])) ;

}

/////////////////////////////////////////////////////////////////////////////

void Widget::on_pushButton_clicked()
{
    check_all();
    rSudoku(tools) ;
    readfile(*this->ui->toolButton_4 , 4 );
    readfile(*this->ui->toolButton_5 , 5 );
    readfile(*this->ui->toolButton_7 , 7 );
    readfile(*this->ui->toolButton_9 , 9 );
    readfile(*this->ui->toolButton_10 , 10 );
    readfile(*this->ui->toolButton_11 , 11 );
    readfile(*this->ui->toolButton_14 , 14 );
    readfile(*this->ui->toolButton_17 , 17 );
    readfile(*this->ui->toolButton_19 , 19 );
    readfile(*this->ui->toolButton_20 , 20 );
    readfile(*this->ui->toolButton_24 , 24 );
    readfile(*this->ui->toolButton_25 , 25 );
    readfile(*this->ui->toolButton_28 , 28 );
    readfile(*this->ui->toolButton_29 , 29 );
    readfile(*this->ui->toolButton_31 , 31 );
    readfile(*this->ui->toolButton_35 , 35 );
    readfile(*this->ui->toolButton_39 , 39 );
    readfile(*this->ui->toolButton_40 , 40 );
    readfile(*this->ui->toolButton_43 , 43 );
    readfile(*this->ui->toolButton_47 , 47 );
    readfile(*this->ui->toolButton_51 , 51 );
    readfile(*this->ui->toolButton_53 , 53 );
    readfile(*this->ui->toolButton_54 , 54 );
    readfile(*this->ui->toolButton_57 , 57 );
    readfile(*this->ui->toolButton_58 , 58 );
    readfile(*this->ui->toolButton_62 , 62 );
    readfile(*this->ui->toolButton_63 , 63 );
    readfile(*this->ui->toolButton_65 , 65 );
    readfile(*this->ui->toolButton_68 , 68 );
    readfile(*this->ui->toolButton_71 , 71 );
    readfile(*this->ui->toolButton_72 , 72 );
    readfile(*this->ui->toolButton_73 , 73 );
    readfile(*this->ui->toolButton_75 , 75 );
    readfile(*this->ui->toolButton_77 , 77 );
    readfile(*this->ui->toolButton_78 , 78 );
    this->ui->gridLayoutWidget->setEnabled(true) ;
    this->ui->gridLayoutWidget_2->setEnabled(true) ;
    this->ui->gridLayoutWidget_3->setEnabled(true) ;
    this->ui->gridLayoutWidget_4->setEnabled(true) ;
    this->ui->gridLayoutWidget_5->setEnabled(true) ;
    this->ui->gridLayoutWidget_6->setEnabled(true) ;
    this->ui->gridLayoutWidget_7->setEnabled(true) ;
    this->ui->gridLayoutWidget_8->setEnabled(true) ;
    this->ui->gridLayoutWidget_9->setEnabled(true) ;
    this->ui->pushButton->setEnabled(false);
}

/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////


void Widget::check_all()
{
    int s=0 ;
    s+=check(*this->ui->toolButton , 1) ;
    s+=check(*this->ui->toolButton_2 , 2) ;
    s+=check(*this->ui->toolButton_3 , 3) ;
    s+=check(*this->ui->toolButton_6 , 6) ;
    s+=check(*this->ui->toolButton_8 , 8) ;
    s+=check(*this->ui->toolButton_12 , 12) ;
    s+=check(*this->ui->toolButton_13 , 13) ;
    s+=check(*this->ui->toolButton_15 , 15) ;
    s+=check(*this->ui->toolButton_16 , 16) ;
    s+=check(*this->ui->toolButton_18 , 18) ;
    s+=check(*this->ui->toolButton_21 , 21) ;
    s+=check(*this->ui->toolButton_22 , 22) ;
    s+=check(*this->ui->toolButton_23 , 23) ;
    s+=check(*this->ui->toolButton_26 , 26) ;
    s+=check(*this->ui->toolButton_27 , 27) ;
    s+=check(*this->ui->toolButton_30 , 30) ;
    s+=check(*this->ui->toolButton_32 , 32) ;
    s+=check(*this->ui->toolButton_33 , 33) ;
    s+=check(*this->ui->toolButton_34 , 34) ;
    s+=check(*this->ui->toolButton_36 , 36) ;
    s+=check(*this->ui->toolButton_37 , 37) ;
    s+=check(*this->ui->toolButton_38 , 38) ;
    s+=check(*this->ui->toolButton_41 , 41) ;
    s+=check(*this->ui->toolButton_42 , 42) ;
    s+=check(*this->ui->toolButton_44 , 44) ;
    s+=check(*this->ui->toolButton_45 , 45) ;
    s+=check(*this->ui->toolButton_46 , 46) ;
    s+=check(*this->ui->toolButton_48 , 48) ;
    s+=check(*this->ui->toolButton_49 , 49) ;
    s+=check(*this->ui->toolButton_50 , 50) ;
    s+=check(*this->ui->toolButton_52 , 52) ;
    s+=check(*this->ui->toolButton_55 , 55) ;
    s+=check(*this->ui->toolButton_56 , 56) ;
    s+=check(*this->ui->toolButton_59 , 59) ;
    s+=check(*this->ui->toolButton_60 , 60) ;
    s+=check(*this->ui->toolButton_61 , 61) ;
    s+=check(*this->ui->toolButton_64 , 64) ;
    s+=check(*this->ui->toolButton_66 , 66) ;
    s+=check(*this->ui->toolButton_67 , 67) ;
    s+=check(*this->ui->toolButton_69 , 69) ;
    s+=check(*this->ui->toolButton_70 , 70) ;
    s+=check(*this->ui->toolButton_74 , 74) ;
    s+=check(*this->ui->toolButton_76 , 76) ;
    s+=check(*this->ui->toolButton_79 , 79) ;
    s+=check(*this->ui->toolButton_80 , 80) ;
    s+=check(*this->ui->toolButton_81 , 81) ;
     if(s==46)
     {
         string s2;
         username * u = new username ;
         for(int i=0 ; i<u->j ; i++)
         {
             if(u->names[i] == this->user.toStdString())
             {
                 u->scores[i] ++ ;
                   for(int p=0 ; p<j-1 ; p++)
                       for(int l=p+1 ; l<j ; l++)
                           if(u->scores[l] > u->scores[p])
                           {
                               int t=u->scores[l] ;
                               u->scores[l]=u->scores[p];
                               u->scores[p]=t;
                               string f=u->names[l];
                               u->names[l]=u->names[p];
                               u->names[p]=f;
                               string s = u->paswords[l] ;
                               u->paswords[l] = u->paswords[p] ;
                               u->paswords[p] = s ;
                           }
                   ofstream y("leaderboard of sudoku game.txt" , ios::in | ios::binary);
                   for(int h=0 ; h<j ; h++)
                       y << u->names[h] << "  " << u->paswords[h] << "  " << u->scores[h] << endl;
                   y.close();
                   break ;
             }
         }
		 QMessageBox::information(this , tr("you have won" ) , tr("good job! you solved it :)")) ;
		 Beginning *be = new Beginning ;
		 be->show();
         this->close();
     }
}
void Widget::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Test", "Are you sure?!",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        Beginning * b = new Beginning ;
        this->close();
        b->show() ;
    }
    else
    {

    }
}

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


void Widget::on_toolButton_clicked()
{
    add_setText(*this->ui->toolButton) ;
    check_all();
}

void Widget::on_toolButton_2_clicked()
{
    add_setText(*this->ui->toolButton_2) ;
    check_all();
}
void Widget::on_toolButton_3_clicked()
{
    add_setText(*this->ui->toolButton_3) ;
    check_all();
}
void Widget::on_toolButton_6_clicked()
{
    add_setText(*this->ui->toolButton_6) ;
    check_all();
}
void Widget::on_toolButton_8_clicked()
{
    add_setText(*this->ui->toolButton_8) ;
    check_all();
}
void Widget::on_toolButton_12_clicked()
{
    add_setText(*this->ui->toolButton_12) ;
    check_all();
}
void Widget::on_toolButton_13_clicked()
{
    add_setText(*this->ui->toolButton_13) ;
    check_all();
}
void Widget::on_toolButton_15_clicked()
{
    add_setText(*this->ui->toolButton_15) ;
    check_all();
}
void Widget::on_toolButton_16_clicked()
{
    add_setText(*this->ui->toolButton_16) ;
    check_all();
}
void Widget::on_toolButton_18_clicked()
{
    add_setText(*this->ui->toolButton_18) ;
    check_all();
}
void Widget::on_toolButton_21_clicked()
{
    add_setText(*this->ui->toolButton_21) ;
    check_all();
}
void Widget::on_toolButton_22_clicked()
{
    add_setText(*this->ui->toolButton_22) ;
    check_all();
}
void Widget::on_toolButton_23_clicked()
{
    add_setText(*this->ui->toolButton_23) ;
    check_all();
}
void Widget::on_toolButton_26_clicked()
{
    add_setText(*this->ui->toolButton_26) ;
    check_all();
}
void Widget::on_toolButton_27_clicked()
{
    add_setText(*this->ui->toolButton_27) ;
    check_all();
}
void Widget::on_toolButton_30_clicked()
{
    add_setText(*this->ui->toolButton_30) ;
    check_all();
}
void Widget::on_toolButton_32_clicked()
{
    add_setText(*this->ui->toolButton_32) ;
    check_all();
}
void Widget::on_toolButton_33_clicked()
{
    add_setText(*this->ui->toolButton_33) ;
    check_all();
}
void Widget::on_toolButton_34_clicked()
{
    add_setText(*this->ui->toolButton_34) ;
    check_all();
}
void Widget::on_toolButton_36_clicked()
{
    add_setText(*this->ui->toolButton_36) ;
    check_all();
}
void Widget::on_toolButton_37_clicked()
{
    add_setText(*this->ui->toolButton_37) ;
    check_all();
}
void Widget::on_toolButton_38_clicked()
{
    add_setText(*this->ui->toolButton_38) ;
    check_all();
}
void Widget::on_toolButton_41_clicked()
{
    add_setText(*this->ui->toolButton_41) ;
    check_all();
}
void Widget::on_toolButton_42_clicked()
{
    add_setText(*this->ui->toolButton_42) ;
    check_all();
}
void Widget::on_toolButton_44_clicked()
{
    add_setText(*this->ui->toolButton_44) ;
    check_all();
}
void Widget::on_toolButton_45_clicked()
{
    add_setText(*this->ui->toolButton_45) ;
    check_all();
}
void Widget::on_toolButton_46_clicked()
{
    add_setText(*this->ui->toolButton_46) ;
    check_all();
}

void Widget::on_toolButton_48_clicked()
{
    add_setText(*this->ui->toolButton_48) ;
    check_all();
}
void Widget::on_toolButton_49_clicked()
{
    add_setText(*this->ui->toolButton_49) ;
    check_all();
}
void Widget::on_toolButton_50_clicked()
{
    add_setText(*this->ui->toolButton_50) ;
    check_all();
}
void Widget::on_toolButton_52_clicked()
{
    add_setText(*this->ui->toolButton_52) ;
    check_all();
}
void Widget::on_toolButton_55_clicked()
{
    add_setText(*this->ui->toolButton_55) ;
    check_all();
}
void Widget::on_toolButton_56_clicked()
{
    add_setText(*this->ui->toolButton_56) ;
    check_all();
}
void Widget::on_toolButton_59_clicked()
{
    add_setText(*this->ui->toolButton_59) ;
    check_all();
}
void Widget::on_toolButton_60_clicked()
{
    add_setText(*this->ui->toolButton_60) ;
    check_all();
}
void Widget::on_toolButton_61_clicked()
{
    add_setText(*this->ui->toolButton_61) ;
    check_all();
}
void Widget::on_toolButton_64_clicked()
{
    add_setText(*this->ui->toolButton_64) ;
    check_all();
}
void Widget::on_toolButton_66_clicked()
{
    add_setText(*this->ui->toolButton_66) ;
    check_all();
}
void Widget::on_toolButton_67_clicked()
{
    add_setText(*this->ui->toolButton_67) ;
    check_all();
}
void Widget::on_toolButton_69_clicked()
{
    add_setText(*this->ui->toolButton_69) ;
    check_all();
}
void Widget::on_toolButton_70_clicked()
{
    add_setText(*this->ui->toolButton_70) ;
    check_all();
}
void Widget::on_toolButton_74_clicked()
{
    add_setText(*this->ui->toolButton_74) ;
    check_all();
}
void Widget::on_toolButton_76_clicked()
{
    add_setText(*this->ui->toolButton_76) ;
    check_all();
}
void Widget::on_toolButton_79_clicked()
{
    add_setText(*this->ui->toolButton_79) ;
    check_all();
}
void Widget::on_toolButton_80_clicked()
{
    add_setText(*this->ui->toolButton_80) ;
    check_all();
}
void Widget::on_toolButton_81_clicked()
{
    add_setText(*this->ui->toolButton_81) ;
    check_all();
}

