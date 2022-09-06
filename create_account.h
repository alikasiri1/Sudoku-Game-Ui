#ifndef CREATE_ACCOUNT_H
#define CREATE_ACCOUNT_H

#include <QWidget>
#include "username.h"
#include<string>
using namespace std;
namespace Ui {
class create_account;
}

class create_account : public QWidget
{
    Q_OBJECT

public:
    explicit create_account(QWidget *parent = nullptr);
    ~create_account();

    int j=0 , m=0 , k=0 ;
    string names[100] ;
    string paswords[100] ;
    int scores[100] ;
    string sc[100] ;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::create_account *ui;
};

#endif // CREATE_ACCOUNT_H
