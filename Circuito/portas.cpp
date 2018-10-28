#include <iostream>
#include "portas.h"
#include "bool3S.h"

#define NUM_MAX_INPUTS_PORTA 4

using namespace std;

Porta::Porta(unsigned NI){
    //Numero de inputs nao pode ser superior ao num_max_inputs
    if(NI > NUM_MAX_INPUTS_PORTA){
        ///Essa eh uma boa pratica de programacao??
        for(unsigned i = 0; i < NUM_MAX_INPUTS_PORTA; i++) id_in[i] = 0;
        return;
    }
    //Declara o numero de entradas NI e inicializa todas com indice = 0
    Nin = NI;
    for (unsigned i = 0; i < NI; ++i) id_in[i] = 0;
}

Porta::Porta(const Porta &P){
    Nin = P.Nin;
    saida = P.saida;
    for(unsigned i = 0; i < NUM_MAX_INPUTS_PORTA; i++) id_in[i] = P.id_in[i];
}

int Porta::getId_in(unsigned i) const{
    ///Maior ou maior ou igual???
    if(i >= Nin) return 0;
    else{
        return id_in[i];
    }
}

void Porta::setNumInputs(unsigned N){
    if(N > NUM_MAX_INPUTS_PORTA || N < 2){
        for(unsigned i = 0; i < NUM_MAX_INPUTS_PORTA; i++) id_in[i] = 0;
        return;
    }else{
    Nin = N;
    for(unsigned i = 0; i < N; i++) id_in[i] = 0;
    }
}

 void setSaida(bool3S s);
