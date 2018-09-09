#include "loja_heranca.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

istream &Produto::digitar(istream &I){
    float preco_prov;
    cout << "Entre com o nome do produto: " << endl;
    I >> ws;
    getline(I, nome);
    cout << "Entre com o preco, em centavos, do produto: " << endl;
    I >> preco_prov;
    I.ignore();
    while((int) preco_prov != preco_prov){
        preco_prov*=10;
    }
    preco = preco_prov;
    return I;
}

ostream &Produto::imprimir(ostream &O) const{
    O << '"' << nome << '";$' << preco/100 << '.' << preco%100 << ';';
    return O;
}

istream &Produto::ler(istream &arq){
    float preco_prov;
    arq.ignore(numeric_limits<streamsize>::max(), '"');
    getline(arq, nome, '"');
    arq >> preco_prov;
    arq.ignore();
    while((int) preco_prov != preco_prov){
        preco_prov*= 10;
    }
    preco = preco_prov;
    return arq;
}

istream &Livro::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com o autor do livro: " << endl;
//    I >> ws;
    getline(I,autor);
    return I;
}

ostream &Livro::imprimir(ostream &O) const{
    Produto::imprimir(O);
    O << '"' << autor << '"' << endl;
    return O;
}

istream &Livro::ler(istream &I){
    Produto::ler(I);
//    I.ignore();
    getline(I, autor, '"');
    return I;
}

istream &CD::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com o numero de faixas do CD: " << endl;
//    I >> ws;
    I >> numFaixas;
    I.ignore();
    return I;
}

ostream &CD::imprimir(ostream &O) const{
    Produto::imprimir(O);
    O << numFaixas << endl;
    return O;
}

istream &CD::ler(istream &I){
    Produto::ler(I);
    I >> numFaixas;
    I.ignore();
    return I;
}

istream &DVD::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com a duracao, em minutos, do DVD: " << endl;
//    I >> ws;
    I >> duracao;
    I.ignore();
    return I;
}

ostream &DVD::imprimir(ostream &O) const{
    Produto::imprimir(O);
    O << duracao << endl;
    return O;
}

istream &DVD::ler(istream &I){
    Produto::ler(I);
    I >> duracao;
    I.ignore();
    return I;
}

ListaLivro::~ListaLivro(){
    delete [] livros;
}

void ListaLivro::incluir(const Livro &L){
    Livro *prov;
    prov = new Livro [tam+1];
    for(int i = 0; i < tam; i++){
        prov[i] = livros[i];
    }
    prov[tam] = L;
    delete [] livros;
    livros = prov;
    delete [] prov;
}

void ListaLivro::excluir(const unsigned &id){
    if(id >= tam){
        cerr << "O item na lista de livros nao existe!" << endl;
        return;
    }
    Livro *prov;
    prov = new Livro[tam-1];
    for(int i = 0; i < id; i++){
        prov[i] = livros[i];
    }
    for(int i = id+1; i < tam-1; i++){
        prov[i-1] = livros[i];
    }
    delete [] livros;
    livros = prov;
    delete [] prov;
    tam--;
}

void ListaLivro::imprimir() const{
    cout << 'LISTALIVRO ' << tam << endl;
    for(int i = 0; i < tam; i++){
        cout << i << ') L: ';
        livros[i].imprimir(cout);
    }
}

void ListaLivro::ler(istream &I){
    unsigned cont;
    I.ignore(numeric_limits<streamsize>::max(), 'LISTALIVRO');
    I >> cont;
    I.ignore();
    for(int i = 0; i < cont; i++){
        livros[i].ler(I);
    }
}
