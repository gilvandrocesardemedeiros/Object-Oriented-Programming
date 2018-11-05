#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <QMainWindow>
#include <QLabel>
#include "newcircuito.h"

namespace Ui {
class circuito;
}

class circuito : public QMainWindow
{
    Q_OBJECT

public:
    explicit circuito(QWidget *parent = nullptr);
    ~circuito();

private slots:
    void on_actionNovo_triggered();

    void on_actionSair_triggered();

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

private:
    Ui::circuito *ui;
    NewCircuito newCircuito;        //
};

#endif // CIRCUITO_H
