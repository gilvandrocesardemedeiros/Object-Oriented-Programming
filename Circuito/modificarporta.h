#ifndef MODIFICARPORTA_H
#define MODIFICARPORTA_H

#include <QDialog>

namespace Ui {
class ModificarPorta;
}

class ModificarPorta : public QDialog
{
    Q_OBJECT

public:
    explicit ModificarPorta(QWidget *parent = nullptr);
    ~ModificarPorta();
    void numPorta(int n);
    void setRangeInputs(int minimo, int maximo);
    void setPorta(int IdPorta);
signals:
    void sinalModificar();
private slots:
    void on_comboTipoPorta_currentIndexChanged(const QString &arg1);
    void on_spinNumInputs_valueChanged(int arg1);
    void on_buttonBox_accepted();
private:
    Ui::ModificarPorta *ui;
    int idPorta;
};

#endif // MODIFICARPORTA_H
