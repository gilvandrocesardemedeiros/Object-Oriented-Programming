#include "circuito.h"
#include "ui_circuito.h"

circuito::circuito(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::circuito)
{
    ui->setupUi(this);
}

circuito::~circuito()
{
    delete ui;
}
