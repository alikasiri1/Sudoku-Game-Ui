#include "widget.h"
#include "username.h"

#include "beginning.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Beginning b ;
    b.show() ;

    return a.exec();
}
