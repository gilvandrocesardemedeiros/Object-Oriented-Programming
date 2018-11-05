#ifndef ERRO_H
#define ERRO_H

#include <QDialog>

namespace Ui {
class erro;
}

class erro : public QDialog
{
    Q_OBJECT

public:
    explicit erro(QWidget *parent = 0);
    ~erro();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::erro *ui;
};

#endif // ERRO_H
