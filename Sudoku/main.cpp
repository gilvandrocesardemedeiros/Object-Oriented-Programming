#include "mainsudoku.h"
#include "sudoku.h"
#include <QApplication>

MainSudoku *pt_w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSudoku w;
    pt_w = &w;
    w.show();

    return a.exec();
}
