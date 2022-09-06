#include "table.h"

#include "ui_table.h"
#include "beginning.h"
table::table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::table)
{
    ui->setupUi(this);
}

table::~table()
{
    delete ui;
}

void table::on_pushButton_clicked()
{

    Beginning *w = new Beginning ;
    this->close();
    w->show();
}
