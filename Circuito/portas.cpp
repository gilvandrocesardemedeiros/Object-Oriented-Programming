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
    if(Nin != 1){
        return UNDEF_3S;
    }
    if(in[0] == TRUE_3S){
        saida = FALSE_3S;
        return saida;
    }
    if(in[0] == FALSE_3S){
        saida = TRUE_3S;
        return saida;
    }
    else{
        saida = UNDEF_3S;
        return saida;
    }
}

bool3S Porta_AND::simular(const bool3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 3:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S || in[2] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S && in[2] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 4:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S || in[2] == FALSE_3S || in[3] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S && in[2] == TRUE_3S && in[3] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        default:
            return UNDEF_3S;
    }
}

bool3S Porta_NAND::simular(const bool3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 3:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S || in[2] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S && in[2] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 4:
            if(in[0] == FALSE_3S || in[1] == FALSE_3S || in[2] == FALSE_3S || in[3] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == TRUE_3S && in[1] == TRUE_3S && in[2] == TRUE_3S && in[3] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        default:
            return UNDEF_3S;
    }
}

bool3S Porta_OR::simular(const bool3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 3:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S && in[2] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 4:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S || in[3] == TRUE_3S){
                saida = TRUE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S && in[2] == FALSE_3S && in[3] == FALSE_3S){
                saida = FALSE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        default:
            return UNDEF_3S;
    }
}

bool3S Porta_NOR::simular(const bool3S in[]){
    switch (Nin){
        case 2:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 3:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S && in[2] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        case 4:
            if(in[0] == TRUE_3S || in[1] == TRUE_3S || in[2] == TRUE_3S || in[3] == TRUE_3S){
                saida = FALSE_3S;
                return saida;
            }
            if(in[0] == FALSE_3S && in[1] == FALSE_3S && in[2] == FALSE_3S && in[3] == FALSE_3S){
                saida = TRUE_3S;
                return saida;
            }
            else{
                saida = UNDEF_3S;
                return saida;
            }
        default:
            return UNDEF_3S;
    }
}

bool3S Porta_XOR::simular(const bool3S in[]){
    unsigned cont_True = 0, cont_False = 0, cont_Undef = 0;
    if(Nin <= 0){
        return UNDEF_3S;
    }

    for(unsigned i = 0; i < Nin; i++){
        if(in[i] == TRUE_3S){
            cont_True++;
            continue;
        }
        if(in[i] == FALSE_3S){
            cont_False++;
            continue;
        }
        else{
            cont_Undef++;
            break;
        }
    }

    if(cont_Undef > 0){
            return UNDEF_3S;
    }
    else{
        if(cont_True % 2 == 0) return FALSE_3S;
        else return TRUE_3S;
    }
}

bool3S Porta_NXOR::simular(const bool3S in[]){
    unsigned cont_True = 0, cont_False = 0, cont_Undef = 0;
    if(Nin <= 0){
        return UNDEF_3S;
    }

    for(unsigned i = 0; i < Nin; i++){
        if(in[i] == TRUE_3S){
            cont_True++;
            continue;
        }
        if(in[i] == FALSE_3S){
            cont_False++;
            continue;
        }
        else{
            cont_Undef++;
            break;
        }
    }

    if(cont_Undef > 0){
            return UNDEF_3S;
    }
    else{
        if(cont_True % 2 == 0) return TRUE_3S;
        else return FALSE_3S;
    }
}

void Circuito::limpar(){
    unsigned Nportas = getNumPortas();
    for(unsigned i = 0; i < Nportas; i++){
        delete portas[i];
    }
    inputs.clear();
    id_out.clear();
    portas.clear();
}

void Circuito::alocar(unsigned NI, unsigned NO, unsigned NP){
    limpar();
    for(unsigned i = 0; i < NI; i++) inputs.push_back(UNDEF_3S);
    for(unsigned i = 0; i < NO; i++) id_out.push_back(0);
    for(unsigned i = 0; i < NP; i++) portas.push_back(NULL);
}

void Circuito::copiar(const Circuito &C){
    limpar();
    unsigned Ninputs = C.getNumInputs();
    unsigned Nout = C.getNumOutputs();
    unsigned Nportas = C.getNumPortas();
    for(unsigned i = 0; i < Ninputs; i++) inputs.push_back(C.inputs[i]);
    for(unsigned i = 0; i < Nout; i++) id_out.push_back(C.id_out[i]);
    for(unsigned i = 0; i < Nportas; i++) inputs.push_back(new C.portas[i]);
}
