#include <iostream>
#include "portas.h"
#include "bool3S.h"

#define NUM_MAX_INPUTS_PORTA 4

using namespace std;

Porta::Porta(unsigned NI){
    //Numero de inputs nao pode ser superior ao num_max_inputs nem inferior a 2
    if(NI < 2 || NI > NUM_MAX_INPUTS_PORTA){
        for(unsigned i = 0; i < NUM_MAX_INPUTS_PORTA; i++) id_in[i] = 0;
        return;
    }else{
        //Declara o numero de entradas NI e inicializa todas com indice = 0
        Nin = NI;
        for (unsigned i = 0; i < NI; ++i) id_in[i] = 0;
    }
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

void Porta::setSaida(bool3S s){
    saida = s;
}

void Porta::setId_in(unsigned i, int Id){
    if(i >= Nin){
        return;
    }
    else{
        id_in[i] = Id;
    }
}

void Porta::digitar(){
    unsigned N_inputs;
    do{
        cout << "Numero de entradas da porta: (2 a 4) ";
        cin >> N_inputs;
    }while(N_inputs < 2 || N_inputs > 4);
    Nin = N_inputs;
    for(unsigned i = 0; i < Nin; i++){
        cout<<"id da entrada " <<i + 1<< ": " << endl;
        cin >> id_in[i];
    }
}

bool Porta::ler(istream &I){
    unsigned N_inputs;
    I >> ws;
    I >> N_inputs;
    if( N_inputs < 2 || N_inputs > 4) return false;
    Nin = N_inputs;
    I.ignore(1,':');
    for(unsigned i = 0; i < Nin; i++){
        I >> id_in[i];
        if(id_in[i] == 0) return false;
    }
    return true;
}

ostream &Porta::imprimir(ostream &O) const{
    O << getNome() << " " << Nin << ":";
    for(unsigned i = 0; i < Nin; i++){
        O << " " << id_in[i];
    }
    O << "\n";
    return O;
}

void Porta_NOT::setNumInputs(unsigned N){
    if(N != 1){
        id_in[0] = 0;
        return;
    }else{
    Nin = N;
    id_in[0] = 0;
    }
}

void Porta_NOT::digitar(){
    unsigned N_inputs;
    do{
        cout << "Numero de entradas da porta: (Porta NOT aceita apenas 1 porta) ";
        cin >> N_inputs;
    }while(N_inputs != 1);
    Nin = N_inputs;
    cout<<"id da entrada " << 1 << ": " << endl;
    cin >> id_in[0];
}

bool Porta_NOT::ler(istream &I){
    unsigned N_inputs;
    I >> ws;
    I >> N_inputs;
    if( N_inputs != 1) return false;
    Nin = N_inputs;
    I.ignore(1,':');
    I >> id_in[0];
    if(id_in[0] == 0) return false;
    return true;
}

bool3S Porta_NOT::simular(const bool3S in[]){
    if(in[0] == TRUE_3S){
        saida = FALSE_3S;
        return saida;
    }else if(in[0] == FALSE_3S){
        saida = TRUE_3S;
        return saida;
    }else{
        saida = UNDEF_3S;
        return saida;
    }
}


/*bool Porta::ler(istream &I){
    string cabecalho1;
    I >> cabecalho1;
    if(cabecalho1 != "CIRCUITO:"){
        return  false;
    }
    unsigned N_inputs, N_outputs, N_portas;
    I >> N_inputs;
    if(N_inputs < 2 || N_inputs > 4) return false;
    I >> N_outputs;
    I >> N_portas;
    // Serah que vai precisar? I >> ws;
    string cabecalho2;
    I >> cabecalho2;
    if(cabecalho2 != "PORTAS:") return false;
    for(unsigned i = 0; i < N_portas; i++){
        unsigned indice_linha;
        I >> ws;
        I >> indice_linha;
        I.ignore();
        if(indice_linha != i+1) return  false;

    }
    Nin = N_inputs;
    I.ignore(1,':');
    for(unsigned i = 0 ; i < Nin ; i++)
      I >> id_in[i];
}
*/
