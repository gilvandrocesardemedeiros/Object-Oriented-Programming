#ifndef _LOJA_H_
#define _LOJA_H_

#include <iostream>
#include <string>

using namespace std;

class Produto{
private:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &arq);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    inline string getNome() const {return nome;}
    inline unsigned getPreco() const {return preco;}
};

inline istream &operator>>(istream &I, Produto &P) {return P.digitar(I);}
inline ostream &operator<<(ostream &O, Produto &P) {return P.imprimir(O);}

class Livro: public Produto{
private:
    string autor;
public:
    inline Livro(const char *N="", unsigned P=0, const char *A =""): Produto(N, P), autor(A) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    inline string getAutor() const {return autor;}
};

inline istream &operator>>(istream &I, Livro &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &X) {return X.imprimir(O);}

class CD: public Produto{
private:
    unsigned numFaixas;
public:
    inline CD(const char *N="", unsigned P=0, unsigned F = 0): Produto(N, P), numFaixas(F) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
    inline unsigned getNumFaixas() {return numFaixas;}
};

inline istream &operator>>(istream &I, CD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, CD &X) {return X.imprimir(O);}

class DVD: public Produto{
private:
    unsigned duracao;
public:
    inline DVD(const char *N="", unsigned P=0, unsigned D = 0): Produto (N,P), duracao(D) {}
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const {return imprimir(O);}
};

inline istream &operator>>(istream &I, DVD &X) {return X.digitar(I);}
inline ostream &operator<<(ostream &O, DVD &X) {return X.imprimir(O);}

class ListaLivro{
private:
    Livro *livros;
    unsigned tam;
    void criar(unsigned const &T);
    void copiar(const ListaLivro &prov);
    void limpar();
public:
    inline ListaLivro() {criar(0);}
    inline ListaLivro(unsigned const &T) {criar(T);}
    inline ListaLivro(const ListaLivro &prov) {copiar(prov);}
    inline ~ListaLivro() {limpar();}
    void incluir(const Livro &L);
    void excluir(const unsigned &id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaCD{
private:
    CD *cds;
    unsigned tam;
    void criar(unsigned const &T);
    void copiar(const ListaCD &prov);
    void limpar();
public:
    inline ListaCD() {criar(0);}
    inline ListaCD(unsigned const &T) {criar(T);}
    inline ListaCD(const ListaCD &prov) {copiar(prov);}
    inline ~ListaCD() {limpar();}
    void incluir(const CD &L);
    void excluir(const unsigned &id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaDVD{
private:
    DVD *dvds;
    unsigned tam;
    void criar(unsigned const &T);
    void copiar(const ListaDVD &prov);
    void limpar();
public:
    inline ListaDVD() {criar(0);}
    inline ListaDVD(unsigned const &T) {criar(T);}
    inline ListaDVD(const ListaDVD &prov) {copiar(prov);}
    inline ~ListaDVD() {limpar();};
    void incluir(const DVD &L);
    void excluir(const unsigned &id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class Loja{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X) {LL.incluir(X);}
    inline void excluirLivro(unsigned const &id) {LL.excluir(id);}
    inline void incluirDVD(const DVD &X) {LD.incluir(X);}
    inline void excluirDVD(unsigned const &id) {LD.excluir(id);}
    inline void incluirCD(const CD &X) {LC.incluir(X);}
    inline void excluirCD(unsigned const &id) {LC.excluir(id);}
    void imprimir() const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};
#endif // _LOJA_H_
