#include "newcircuito.h"
#include "ui_newcircuito.h"
#include "circuito.h"
#include "portas.h"
#include <QMessageBox>


NewCircuito::NewCircuito(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCircuito)
{
    ui->setupUi(this);
}

NewCircuito::~NewCircuito()
{
    delete ui;
}

// Cria um novo circuito com as dimensoes especificadas pelo usuario
// Deve chamar a funcao apropriada da classe Circuito
void NewCircuito::on_NewCircuito_accepted()
{
    // Cria um novo circuito com os parametros digitados
    int numInputs, numOutputs, numPortas;
    numInputs = ui->spinNumIn->value();
    numOutputs = ui->spinNumOut->value();
    numPortas = ui->spinNumPortas->value();

    // O circuito deve ser criado usando a funcao apropriada da classe Circuito

    // Provisoriamente, estamos apenas exibindo uma msg


   // C.newCircuito(numInputs,numOutputs,numPortas); -> NAO ENTENDI

    // Depois do novo circuito criado, as tabelas devem ser redimensionadas
    //((Circuito*)parentWidget())->redimensiona_tabelas(); -> NAO ENTENDI
}
