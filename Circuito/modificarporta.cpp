#include "modificarporta.h"
#include "ui_modificarporta.h"
#include "circuito.h"
#include "portas.h"

extern Circuito C;

ModificarPorta::ModificarPorta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModificarPorta),
    idPorta(0)
{
    ui->setupUi(this);
    ui->comboTipoPorta->addItems(QStringList() << "NT" << "AN" << "OR" << "XO" << "NA" << "NO" << "NX");    
    ui->comboTipoPorta->setCurrentIndex(0);
    ui->spinNumInputs->setEnabled(false);
    ui->spinNumInputs->setValue(0);
    ui->labelInput2->setEnabled(false);
    ui->spinInput2->setEnabled(false);
    ui->labelInput3->setEnabled(false);
    ui->spinInput3->setEnabled(false);
    ui->labelInput4->setEnabled(false);
    ui->spinInput4->setEnabled(false);
}

ModificarPorta::~ModificarPorta()
{
    delete ui;
}

void ModificarPorta::numPorta(int n){
    ui->labelIdPorta->setNum(n);
}

void ModificarPorta::setPorta(int IdPorta)
{
    int numPortas = ((Circuito*)parentWidget())->getNumPortas();
    if (IdPorta>=1 && IdPorta<=numPortas)
    {
        idPorta = IdPorta;
        ui->labelIdPorta->setNum(idPorta);
    }
}

void ModificarPorta::setRangeInputs(int minimo, int maximo)
{
    ui->spinInput1->setRange(minimo,maximo);
    ui->spinInput2->setRange(minimo,maximo);
    ui->spinInput3->setRange(minimo,maximo);
    ui->spinInput4->setRange(minimo,maximo);
}

void ModificarPorta::on_comboTipoPorta_currentIndexChanged(const QString &arg1)
{
    if (arg1=="NT") ui->spinNumInputs->setRange(1,1);
    else ui->spinNumInputs->setRange(2,4);
}

void ModificarPorta::on_spinNumInputs_valueChanged(int arg1)
{
    ui->labelInput2->setEnabled(arg1 >= 2);
    ui->spinInput2->setEnabled(arg1 >= 2);
    ui->labelInput3->setEnabled(arg1 >= 3);
    ui->spinInput3->setEnabled(arg1 >= 3);
    ui->labelInput4->setEnabled(arg1 >= 4);
    ui->spinInput4->setEnabled(arg1 >= 4);
}

void ModificarPorta::on_buttonBox_accepted()
{
    QString tipoPorta = ui->comboTipoPorta->currentText();
    int numInputsPorta = ui->spinNumInputs->value();
    int idInputPorta[] = {ui->spinInput1->value(),
                          ui->spinInput2->value(),
                          ui->spinInput3->value(),
                          ui->spinInput4->value()};

    C.replace(idPorta-1,tipoPorta.toStdString(),numInputsPorta,idInputPorta);

    ((circuito*)parentWidget())->exibe_porta(idPorta-1);
}
