#include "loja_heranca.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

istream &Produto::digitar(istream &I)
{
    float preco_prov;
    cout << "Entre com o nome do produto: " << endl;
    cin >> ws;
    getline(I, nome);
    cout << "Entre com o preco, em centavos, do produto: " << endl;
    cin >> preco_prov;
    while((int) preco_prov != preco_prov){
        preco_prov*=10;
    }
    preco = preco_prov;
    return I;
}

ostream &Produto::imprimir(ostream &O) const
{
    O << nome << ";" << preco << ";";
    return O;
}

istream &Produto::ler(istream &arq)
{
    arq.ignore(numeric_limits<streamsize>::max(), '"');
    getline(arq, nome, ';');
    arq >> preco;

}
