#include "circuito.h"
#include "ui_circuito.h"
#include "portas.h"
#include <QStringList>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <time.h>
#include <vector>


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

void circuito::on_actionNovo_triggered()
{
    newCircuito.show();
}

void circuito::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void circuito::on_actionLer_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Arquivo de circuito"), QString(),
            tr("Circuitos (*.txt);;Todos (*.*)"));

    bool valido = true;
    if (!fileName.isEmpty()) {
        //valido = C.ler(fileName.toStdString().c_str());
       // redimensiona_tabelas();
    }
    if (!valido){
      //  erroarq.show();
        //C.limpar();
       // redimensiona_tabelas();
    }
}

void circuito::on_actionSalvar_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Arquivo de circuito"), QString(),
            tr("Circuitos (*.txt);;Todos (*.*)"));

    bool valido = true;
    if (!fileName.isEmpty()) {
        if (!fileName.isEmpty()) {
           // valido = C.salvar(fileName.toStdString().c_str());
        }
    }
    if (!valido){
       // valido_circ.show();
    }
}
