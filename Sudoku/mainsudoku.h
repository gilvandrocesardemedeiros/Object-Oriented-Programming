#ifndef MAINSUDOKU_H
#define MAINSUDOKU_H

#include <QMainWindow>
#include "sudoku.h"
#include <QLabel>

namespace Ui {
class MainSudoku;
}

class MainSudoku : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainSudoku(QWidget *parent = nullptr);
    ~MainSudoku();

    void exibirCelulaAtual(int i, int j, int valor);

    void exibirCelulaInicial(int i, int j, int valor);

    void set_background(QLabel *prov, int i, int j);

    void exibirAndamento(unsigned Ntab_testados, unsigned Ntab_gerados, unsigned Ntab_analisar);


private slots:

    void on_tab_atual_cellClicked(int row, int column);

    void on_spinbox_valor_valueChanged(int arg1);

    void on_button_jogar_clicked();

    void on_actionReiniciar_triggered();

    void on_actionNovo_triggered();

    void on_actionPreencher_Imediatas_triggered();

    void on_actionResolver_triggered();

    void on_actionSair_triggered();

    void on_button_continuar_clicked();

private:
    Ui::MainSudoku *ui;
    Sudoku inicial, atual;
    Jogada J;
};

#endif // MAINSUDOKU_H
