#include "erro.h"
#include "ui_erro.h"

erro::erro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::erro)
{
    ui->setupUi(this);
}

erro::~erro()
{
    delete ui;
}
void erro::on_buttonBox_accepted()
{

}
