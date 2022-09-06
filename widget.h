#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QToolButton;
QT_END_NAMESPACE


class Widget : public QWidget
{

    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int tools[9][9] ;
    QString user ;
    int j=0 ;
private slots:
    void on_toolButton_2_clicked();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void fill_tools();
    void readfile(QToolButton & x , int a);
    void add_setText (QToolButton & x ) ;
    int check(QToolButton  & x , int b ) ;
    void check_all() ;

    void on_toolButton_clicked();
    void on_toolButton_3_clicked();
    void on_toolButton_6_clicked();
    void on_toolButton_8_clicked();
    void on_toolButton_12_clicked();
    void on_toolButton_13_clicked();
    void on_toolButton_15_clicked();
    void on_toolButton_16_clicked();
    void on_toolButton_18_clicked();
    void on_toolButton_21_clicked();
    void on_toolButton_22_clicked();
    void on_toolButton_23_clicked();
    void on_toolButton_26_clicked();
    void on_toolButton_27_clicked();
    void on_toolButton_30_clicked();
    void on_toolButton_32_clicked();
    void on_toolButton_33_clicked();
    void on_toolButton_34_clicked();
    void on_toolButton_36_clicked();
    void on_toolButton_37_clicked();
    void on_toolButton_38_clicked();
    void on_toolButton_41_clicked();
    void on_toolButton_42_clicked();
    void on_toolButton_44_clicked();
    void on_toolButton_45_clicked();
    void on_toolButton_46_clicked();
    void on_toolButton_48_clicked();
    void on_toolButton_49_clicked();
    void on_toolButton_50_clicked();
    void on_toolButton_52_clicked();
    void on_toolButton_55_clicked();
    void on_toolButton_56_clicked();
    void on_toolButton_59_clicked();
    void on_toolButton_60_clicked();
    void on_toolButton_61_clicked();
    void on_toolButton_64_clicked();
    void on_toolButton_66_clicked();
    void on_toolButton_67_clicked();
    void on_toolButton_69_clicked();
    void on_toolButton_70_clicked();
    void on_toolButton_74_clicked();
    void on_toolButton_76_clicked();
    void on_toolButton_79_clicked();
    void on_toolButton_80_clicked();
    void on_toolButton_81_clicked();

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
