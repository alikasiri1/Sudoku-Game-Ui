#ifndef USERNAME_H
#define USERNAME_H


#include <QWidget>
#include "widget.h"
#include "ui_username.h"
#include "widget.h"
#include "ui_widget.h"
#include "create_account.h"
#include<string>
using namespace std;
namespace Ui {
class username;
}

class username : public QWidget
{
    Q_OBJECT

public:
    explicit username(QWidget *parent = nullptr);
    ~username();

    bool name() ;
    string names[100] ;
    string user2 ;
    string paswords[100] ;
    int scores[100] ;
    int j=0 , m=0 , k=0 ;
private slots:
    void on_pushButton_clicked();
    void setname(string x , int y);
    void on_pushButton_2_clicked();

private:
    Ui::username *ui;

};

#endif // USERNAME_H
