
#include "loing.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Loing w;
    w.show();
    qDebug() << QSqlDatabase::drivers();

    return a.exec();
}
