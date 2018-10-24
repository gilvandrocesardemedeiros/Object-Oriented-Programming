#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <QMainWindow>

namespace Ui {
class circuito;
}

class circuito : public QMainWindow
{
    Q_OBJECT

public:
    explicit circuito(QWidget *parent = nullptr);
    ~circuito();

private:
    Ui::circuito *ui;
};

#endif // CIRCUITO_H
