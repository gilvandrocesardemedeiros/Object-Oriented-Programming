#include "mainsudoku.h"
#include "ui_mainsudoku.h"
#include <QString>

MainSudoku::MainSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSudoku),
    inicial("sudoku.txt"),
    atual(inicial),
    J(0,0,0)
{
    ui->setupUi(this);
    ui->button_continuar->hide();
    ui->table_inicial->setEnabled(false);
    ui->tab_atual->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tab_atual->setTabKeyNavigation(false);

    QLabel *prov;
    for(unsigned int i=0; i<9; i++){
        for(unsigned int j=0; j<9; j++){
        //cria e seta o QLabel da celula atual do TabAtual
        prov = new QLabel;
        prov->setAlignment(Qt::AlignCenter);
        prov->setGeometry(0,0,30,30);
        if(atual.at(i,j)==0){
            prov->setText("");
            ui->button_jogar->setEnabled(false);
            ui->NumL->setText("A");
            ui->NumC->setNum(1);
        }
        else{
        prov->setNum(atual.at(i,j));
        }
        if(i==0 && j==0){
            prov->setStyleSheet("background: lightyellow");
        }
        else{
            set_background(prov, int(i), int(j));
        }
        ui->tab_atual->setCellWidget(int(i),int(j),prov);
        //cria e seta o QLabel da celula atual do TabInicial
        prov = new QLabel;
        prov->setAlignment(Qt::AlignCenter);
        prov->setGeometry(0,0,30,30);
        if(inicial.at(i,j)==0) prov->setText("");
        else prov->setNum(inicial.at(i,j));
        set_background(prov, int(i), int(j));
        ui->table_inicial->setCellWidget(int(i),int(j),prov);
     }
}
    ui->spinbox_valor->setRange(0,9);
    ui->spinbox_valor->setWrapping(true);
    ui->spinbox_valor->setSpecialValueText("Apagar");
}

MainSudoku::~MainSudoku()
{
    delete ui;
}

void MainSudoku::on_tab_atual_cellClicked(int row, int column)
{
    QLabel *prov;
    prov = (QLabel*)ui->tab_atual->cellWidget(J.linha(),J.coluna());
    set_background(prov,J.linha(),J.coluna());
    J.setCell(row,column);
    prov = (QLabel*)ui->tab_atual->cellWidget(J.linha(),J.coluna());
    prov->setStyleSheet("background: lightyellow");
    ui->NumL->setText(QString(J.linha()+'A'));
    ui->NumC->setNum(J.coluna()+1);
    ui->spinbox_valor->setValue(atual.at(unsigned(row),unsigned(column)));
    MainSudoku::on_spinbox_valor_valueChanged(J.valor());
}

void MainSudoku::set_background(QLabel *prov, int i, int j)
{
    int II(i/3), JJ(j/3);
    if((II==0 || II==2) && JJ==1) prov->setStyleSheet("background: lightcyan");
    else if(II==1 && (JJ==0 ||JJ==2)) prov->setStyleSheet("background: lightcyan");
    else prov->setStyleSheet("background: white");
}

void MainSudoku::on_spinbox_valor_valueChanged(int arg1)
{
    J.setValue(arg1);
    if(atual.jogada_valida(J) || atual.apagamento_valido(J,inicial)) ui->button_jogar->setEnabled(true);
    else ui->button_jogar->setEnabled(false);
}

void MainSudoku::on_button_jogar_clicked()
{
    if(J.valor()==0) atual.apagar_jogada(J,inicial);
    else atual.fazer_jogada(J);
    exibirCelulaAtual(J.linha(),J.coluna(),J.valor());
    MainSudoku::on_spinbox_valor_valueChanged(J.valor());
}

void MainSudoku::on_actionReiniciar_triggered()
{
    atual=inicial;
    atual.exibir();
}

void MainSudoku::on_actionNovo_triggered()
{
    inicial.gerar();
    inicial.exibir_origem();
    atual=inicial;
    atual.exibir();
}

void MainSudoku::on_actionPreencher_Imediatas_triggered()
{
    int num = atual.resolver_casas_faceis();
    atual.exibir();
    if(num>0) ui->statusBar->showMessage(QString::number(num) + QString(" casas preenchidas"));
    else if(num<0 && num>-81) ui->statusBar->showMessage(QString("TABULEIRO INSOLÚVEL! ")+ ((-num==1) ? QString("%1 casa preenchida.").arg(-num) : QString("%1 casas preenchidas.").arg(-num)));
    else if(num<-81) ui->statusBar->showMessage(QString("TABULEIRO INSOLÚVEL!"));
}

void MainSudoku::on_actionResolver_triggered()
{
    atual.exibir_origem();
    atual.resolver();
    ui->tab_atual->setEnabled(false);
    ui->menuBar->setEnabled(false);
    ui->button_continuar->show();
    ui->button_jogar->setEnabled(false);
    ui->spinbox_valor->setEnabled(false);
}

void MainSudoku::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void MainSudoku::on_button_continuar_clicked()
{
    inicial.exibir_origem();
    atual.exibir();
    ui->statusBar->clearMessage();
    ui->tab_atual->setEnabled(true);
    ui->menuBar->setEnabled(true);
    ui->button_jogar->setEnabled(true);
    ui->spinbox_valor->setEnabled(true);
    ui->button_continuar->hide();
}

void MainSudoku::exibirCelulaAtual(int i, int j, int valor)
{
    QLabel *prov = (QLabel*)ui->tab_atual->cellWidget(i,j);
    if(valor==0) prov->setText("");
    else prov->setNum(valor);
}

void MainSudoku::exibirCelulaInicial(int i, int j, int valor)
{
    QLabel *prov = (QLabel*)ui->tab_atual->cellWidget(i,j);
    if(valor==0) prov->setText("");
    else prov->setNum(valor);
}

void MainSudoku::exibirAndamento(unsigned Ntab_testados, unsigned Ntab_gerados, unsigned Ntab_analisar)
{
    ui->statusBar->showMessage(QString("TABULEIROS: %1 testados; %2 gerados; %3 a analisar").arg(Ntab_testados).arg(Ntab_gerados).arg(Ntab_analisar));
}

