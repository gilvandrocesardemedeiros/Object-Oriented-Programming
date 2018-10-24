#include "circuito.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    circuito w;
    w.show();

    return a.exec();
}
