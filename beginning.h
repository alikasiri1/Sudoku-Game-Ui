#ifndef BEGINNING_H
#define BEGINNING_H

#include <QWidget>

namespace Ui {
class Beginning;
}

class Beginning : public QWidget
{
    Q_OBJECT

public:
    explicit Beginning(QWidget *parent = nullptr);
    ~Beginning();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Beginning *ui;
};

#endif // BEGINNING_H
