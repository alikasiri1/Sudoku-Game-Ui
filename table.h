#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include "create_account.h"
namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();
    string users[10] ;
    string scorse[10] ;
private slots:
    void on_pushButton_clicked();

private:
    Ui::table *ui;
};

#endif // TABLE_H
