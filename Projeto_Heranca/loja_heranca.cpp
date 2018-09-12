#include "loja_heranca.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

///Classe Produto -------------------------------------------------------------------

istream &Produto::digitar(istream &I){
    float preco_prov;
    cout << "Entre com o nome do produto: " << endl;
    I >> ws;
    getline(I, nome);
    cout << "Entre com o preco, em reais, do produto: " << endl;
    I >> preco_prov;
    preco = 100*preco_prov;
    return I;
}

ostream &Produto::imprimir(ostream &O) const{
    O << '"' << nome << '"' << ";$" << (float)preco/100 << ';';
    return O;
}

istream &Produto::ler(istream &arq){
    float preco_prov;
    arq.ignore(numeric_limits<streamsize>::max(), '"');
    getline(arq, nome, '"');
    arq.ignore(numeric_limits<streamsize>::max(), '$');
    arq >> preco_prov;
    preco = preco_prov*100;
    return arq;
}

///Classe Livro-------------------------------------------------------------------

istream &Livro::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com o autor do livro: " << endl;
    I >> ws;
    getline(I,autor);
    return I;
}

ostream &Livro::imprimir(ostream &O) const{
    O << "L: ";
    Produto::imprimir(O);
    O << '"' << autor << '"' << endl;
    return O;
}

istream &Livro::ler(istream &I){
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), '"');
    getline(I, autor, '"');
    return I;
}

///Classe CD-------------------------------------------------------------------

istream &CD::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com o numero de faixas do CD: " << endl;
    I >> ws;
    I >> numFaixas;
    return I;
}

ostream &CD::imprimir(ostream &O) const{
    O << "C: ";
    Produto::imprimir(O);
    O << numFaixas << endl;
    return O;
}

istream &CD::ler(istream &I){
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), ';');
    I >> numFaixas;
    return I;
}

///Classe DVD-------------------------------------------------------------------

istream &DVD::digitar(istream &I){
    Produto::digitar(I);
    cout << "Entre com a duracao, em minutos, do DVD: " << endl;
    I >> ws;
    I >> duracao;
    return I;
}

ostream &DVD::imprimir(ostream &O) const{
    O << "D: ";
    Produto::imprimir(O);
    O << duracao << endl;
    return O;
}

istream &DVD::ler(istream &I){
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(), ';');
    I >> duracao;
    return I;
}

///Classe ListaLivro-------------------------------------------------------------------

void ListaLivro::criar(unsigned const &T){
    if(T == 0){
        livros = NULL;
        tam = 0;
        return;
    }else{
        tam = T;
        livros = new Livro [T];
    }
}

void ListaLivro::copiar(const ListaLivro &prov){
    criar(prov.tam);
    for(unsigned i = 0; i < tam; i++){
        livros[i] = prov.livros[i];
    }
}

void ListaLivro::limpar(){
    if(livros != NULL){
        delete [] livros;
    }else{
        cerr << "Erro: Tentativa de apagar lista vazia." << endl;
    }
}

void ListaLivro::incluir(const Livro &L){
    Livro *prov;
    prov = new Livro [tam+1];
    for(unsigned i = 0; i < tam; i++){
        prov[i] = livros[i];
    }
    prov[tam] = L;
    if(livros != NULL){
        delete [] livros;
    }
    livros = prov;
    tam++;
}

void ListaLivro::excluir(const unsigned &id){
    if(id >= tam){
        cerr << "O item na lista de livros nao existe!" << endl;
        return;
    }
    Livro *prov;
    prov = new Livro[tam-1];
    for(unsigned i = 0; i < id; i++){
        prov[i] = livros[i];
    }
    for(unsigned i = id; i < tam-1; i++){
        prov[i] = livros[i+1];
    }
    delete [] livros;
    livros = prov;
    delete [] prov;
    tam--;
}

void ListaLivro::imprimir() const{
    cout << "LISTALIVRO " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        cout << i << ") ";
        livros[i].imprimir(cout);
    }
}

void ListaLivro::ler(istream &I){
    string tipo_lista;
    I >> ws;
    I >> tipo_lista;
    if(tipo_lista != "LISTALIVRO"){
        cerr << "Arquivo invalido para leitura." << endl;
        return;
    }
    I >> tam;
    livros = new Livro[tam];
    for(unsigned i = 0; i < tam; i++){
        livros[i].ler(I);
    }
}

void ListaLivro::salvar(ostream &O) const{
    O << "LISTALIVRO " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        livros[i].imprimir(O);
    }
}

///Classe ListaCD-------------------------------------------------------------------

void ListaCD::criar(unsigned const &T){
    if(T == 0){
        cds = NULL;
        tam = 0;
        return;
    }else{
        tam = T;
        cds = new CD [T];
    }
}

void ListaCD::copiar(const ListaCD &prov){
    criar(prov.tam);
    for(unsigned i = 0; i < tam; i++){
        cds[i] = prov.cds[i];
    }
}

void ListaCD::limpar(){
    if(cds != NULL){
        delete [] cds;
    }else{
        cerr << "Erro: Tentativa de apagar lista vazia." << endl;
    }
}

void ListaCD::incluir(const CD &L){
    CD *prov;
    prov = new CD [tam+1];
    for(unsigned i = 0; i < tam; i++){
        prov[i] = cds[i];
    }
    prov[tam] = L;
    if(cds != NULL){
        delete [] cds;
    }
    cds = prov;
    tam++;
}

void ListaCD::excluir(const unsigned &id){
    if(id >= tam){
        cerr << "O item na lista de cds nao existe!" << endl;
        return;
    }
    CD *prov;
    prov = new CD[tam-1];
    for(unsigned i = 0; i < id; i++){
        prov[i] = cds[i];
    }
    for(unsigned i = id; i < tam-1; i++){
        prov[i] = cds[i+1];
    }
    delete [] cds;
    cds = prov;
    delete [] prov;
    tam--;
}

void ListaCD::imprimir() const{
cout << "LISTACD " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        cout << i << ") ";
        cds[i].imprimir(cout);
    }
}

void ListaCD::ler(istream &I){
    string tipo_lista;
    I >> ws;
    I >> tipo_lista;
    if(tipo_lista != "LISTACD"){
        cerr << "Arquivo invalido para leitura." << endl;
        return;
    }
    I >> tam;
    cds = new CD[tam];
    for(unsigned i = 0; i < tam; i++){
        cds[i].ler(I);
    }
}

void ListaCD::salvar(ostream &O) const{
    O << "LISTACD " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        cds[i].imprimir(O);
    }
}

///Classe ListaDVD-------------------------------------------------------------------

void ListaDVD::criar(unsigned const &T){
    if(T == 0){
        dvds = NULL;
        tam = 0;
        return;
    }else{
        tam = T;
        dvds = new DVD [T];
    }
}

void ListaDVD::copiar(const ListaDVD &prov){
    criar(prov.tam);
    for(unsigned i = 0; i < tam; i++){
        dvds[i] = prov.dvds[i];
    }
}

void ListaDVD::limpar(){
    if(dvds != NULL){
        delete [] dvds;
    }else{
        cerr << "Erro: Tentativa de apagar lista vazia." << endl;
    }
}

void ListaDVD::incluir(const DVD &L){
    DVD *prov;
    prov = new DVD [tam+1];
    for(unsigned i = 0; i < tam; i++){
        prov[i] = dvds[i];
    }
    prov[tam] = L;
    if(dvds != NULL){
        delete [] dvds;
    }
    dvds = prov;
    tam++;
}

void ListaDVD::excluir(const unsigned &id){
    if(id >= tam){
        cerr << "O item na lista de dvds nao existe!" << endl;
        return;
    }
    DVD *prov;
    prov = new DVD[tam-1];
    for(unsigned i = 0; i < id; i++){
        prov[i] = dvds[i];
    }
    for(unsigned i = id; i < tam-1; i++){
        prov[i] = dvds[i+1];
    }
    delete [] dvds;
    dvds = prov;
    delete [] prov;
    tam--;
}

void ListaDVD::imprimir() const{
cout << "LISTADVD " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        cout << i << ") ";
        dvds[i].imprimir(cout);
    }
}

void ListaDVD::ler(istream &I){
    string tipo_lista;
    I >> ws;
    I >> tipo_lista;
    if(tipo_lista != "LISTADVD"){
        cerr << "Arquivo invalido para leitura." << endl;
        return;
    }
    I >> tam;
    dvds = new DVD[tam];
    for(unsigned i = 0; i < tam; i++){
        dvds[i].ler(I);
    }
}

void ListaDVD::salvar(ostream &O) const{
    O << "LISTADVD " << tam << endl;
    for(unsigned i = 0; i < tam; i++){
        dvds[i].imprimir(O);
    }
}

///Classe Loja-------------------------------------------------------------------

void Loja::imprimir() const{
    LL.imprimir();
    LC.imprimir();
    LD.imprimir();
}

void Loja::ler(const char* arq){
    ifstream arquivo(arq);
    if(arquivo.is_open()){
        LL.ler(arquivo);
        LC.ler(arquivo);
        LD.ler(arquivo);
    }
    arquivo.close();
}

void Loja::salvar(const char* arq) const{
    ofstream arquivo(arq);
    if(arquivo.is_open()){
        LL.salvar(arquivo);
        LC.salvar(arquivo);
        LD.salvar(arquivo);
    }
    arquivo.close();
}
