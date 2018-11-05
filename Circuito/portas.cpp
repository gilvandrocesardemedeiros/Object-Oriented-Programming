#include <iostream>
#include "portas.h"
#include "bool3S.h"
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <limits>
#include <cmath>

#define NUM_MAX_INPUTS_PORTA 4

using namespace std;

extern Circuito C;

//Funcao utilizada para receber uma string informando o tipo da
//porta e retornar um ponteiro para a porta correspondente
ptr_Porta aloca(const string &T){
    int N = 256*toupper(T[0]) + toupper(T[1]);
    switch (N){
    case (256*'A' + 'N'):
        return new Porta_AND;
    case (256*'N' + 'A'):
        return new Porta_NAND;
    case (256*'O' + 'R'):
        return new Porta_OR;
    case (256*'N' + 'O'):
        return new Porta_NOR;
    case (256*'X' + 'O'):
        return new Porta_XOR;
    case (256*'N' + 'X'):
        return new Porta_NXOR;
    case (256*'N' + 'T'):
        return new Porta_NOT;
    default:
        return NULL;
    }
}

//Funcao utilizada recebendo uma string referente ao tipo da porta
//Retornando true se o tipo da porta eh valido ou false se nao eh valido
bool string_valida(const string &T){
    if((T != "AN") && (T!="NA") && (T!="OR") && (T!="NO") && (T!="XO") && (T!="NX") && T!="NT") return false;
    else return true;
}

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
    if(P.getNumInputs() == 0) return;
    *this = *P.clone();
}

int Porta::getId_in(unsigned i) const{
//    if(i > NUM_MAX_INPUTS_PORTA) return 0;
    if(i > Nin) return 0;
    else return id_in[i-1];
}

void Porta::setNumInputs(unsigned N){
    if(N > NUM_MAX_INPUTS_PORTA || N < 2) return;
    else Nin = N;
}

void Porta::setSaida(bool3S s){
    if(s != UNDEF_3S || s != FALSE_3S || s != TRUE_3S) return;
    saida = s;
}

void Porta::setId_in(unsigned i, int Id){
    if(i > Nin) return;
    else id_in[i-1] = Id;
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
    Nin = 0;
    I >> ws;
    I >> N_inputs;
    if( N_inputs < 2 || N_inputs > 4) return false;
    else{
        I.ignore(numeric_limits<streamsize>::max(),':');
        for(unsigned i = 0; i < N_inputs; i++){
            int prov;
            I >> prov;
            if(prov < -1*(C.getNumInputs()) || prov > C.getNumPortas()) return false;
            else id_in[i] = prov;
        }
    }
    Nin = N_inputs;
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
    if(N != 1) return;
    else Nin = 1;
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
    Nin = 0;
    I >> ws;
    I >> N_inputs;
    if( N_inputs != 1) return false;
    else{
        I.ignore(numeric_limits<streamsize>::max(),':');
        int prov;
        I >> prov;
        if(prov < -1*(C.getNumInputs()) || prov > C.getNumPortas()) return false;
        id_in[0] = prov;
        Nin = 1;
        return true;
    }
}

bool3S Porta_NOT::simular(const bool3S in[]){
    if(getNumInputs() != 1) return UNDEF_3S;
    else return ~in[0];
}

bool3S Porta_AND::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov & in[i];
    }
    return prov;
}

bool3S Porta_NAND::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov & in[i];
    }
    return ~prov;
}

bool3S Porta_OR::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov | in[i];
    }
    return prov;
}

bool3S Porta_NOR::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov | in[i];
    }
    return ~prov;
}

bool3S Porta_XOR::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov ^ in[i];
    }
    return prov;
}

bool3S Porta_NXOR::simular(const bool3S in[]){
    bool3S prov = in[0];
    unsigned numIn = getNumInputs();
    if(numIn < 2) return UNDEF_3S;
    for(unsigned i = 1; i < numIn; i++){
        prov = prov ^ in[i];
    }
    return ~prov;
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
    if(NI < 1 || NO < 1 || NP < 1) return;
    for(unsigned i = 0; i < NI; i++) inputs.push_back(UNDEF_3S);
    for(unsigned i = 0; i < NO; i++) id_out.push_back(0);
    for(unsigned i = 0; i < NP; i++) portas.push_back(NULL);
}

void Circuito::copiar(const Circuito &C){
    unsigned Ninputs = C.getNumInputs();
    unsigned Nout = C.getNumOutputs();
    unsigned Nportas = C.getNumPortas();
    if(Ninputs < 1 || Nout < 1 || Nportas < 1) return;
    for(unsigned i = 0; i < Ninputs; i++) inputs.push_back(C.inputs[i]);
    for(unsigned i = 0; i < Nout; i++) id_out.push_back(C.id_out[i]);
    for(unsigned i = 0; i < Nportas; i++) portas.push_back(C.portas[i]->clone());
}

string Circuito::getNomePorta(unsigned IdPorta) const{
    if(IdPorta > portas.size() || portas[IdPorta-1] == NULL) return "ERRO";
    return portas[IdPorta-1]->getNome();
}

unsigned Circuito::getNumInputsPorta(unsigned IdPorta) const{
    if(IdPorta > portas.size()) return 0;
    return portas[IdPorta-1]->getNumInputs();
}

int Circuito::getId_inPorta(unsigned IdPorta, unsigned i) const{
    if(IdPorta > portas.size()) return 0;
    if(i > getNumInputsPorta(IdPorta)) return 0;
    return portas[IdPorta-1]->getId_in(i-1);
}

bool3S Circuito::getSaida(unsigned IdOut) const{
    if(IdOut > id_out.size()) return UNDEF_3S;
    return portas[IdOut-1]->getSaida();
}

int Circuito::getIdOutput(unsigned IdOut) const{
    if(IdOut > id_out.size()) return 0;
    return id_out[IdOut-1];
}

bool Circuito::valido() const{
    for(unsigned i = 0; i < inputs.size(); i++){
        if(inputs[i] != UNDEF_3S || inputs[i] != FALSE_3S || inputs[i] != TRUE_3S) return false;
    }
    for(unsigned i = 0; i < id_out.size(); i++){
        if(id_out[i] < (-inputs.size()) || id_out[i] > portas.size() || id_out[i] == 0) return false;
    }
    for(unsigned i = 0; i < portas.size(); i++){
        unsigned numPortas = portas[i]->getNumInputs();
        for(unsigned j = 0; j < numPortas; j++){
            if(portas[i]->getId_in(j)==0) return false;
        }
    }
    return true;
}

void Circuito::setPorta(unsigned IdPorta, const string &T, unsigned NIn){
    if(IdPorta>portas.size() || IdPorta == 0) return;
    if(!string_valida(T)) return;
    if(T == "NT" && NIn != 1) return;
    if((NIn < 2 || NIn > NUM_MAX_INPUTS_PORTA)) return;
    portas[IdPorta-1] = aloca(T);
}

void Circuito::setId_inPorta(unsigned IdPorta, unsigned I, int Id) const
{
    if(IdPorta < 1 || I < 1 || Id == 0) return;
    if(IdPorta > portas.size() || I > portas[IdPorta-1]->getNumInputs()) return;
    if(Id < (-1*inputs.size()) || Id > inputs.size()) return;
    portas[IdPorta-1]->setId_in(I,Id);
}

void Circuito::setIdOutput(unsigned IdOut, int Id)
{
    if(IdOut > id_out.size() || IdOut == 0) return;
    if(Id > -1*inputs.size() || Id > portas.size()) return;
    id_out[IdOut-1] = Id;
}

//Falta implementar!!
void Circuito::digitar(){

}

bool Circuito::ler(const string &arq){
    limpar();
    ifstream arquivo(arq);
    if(!arquivo.is_open()) return false;
    string prov;
    getline(arquivo,prov,':');
    if(prov != "CIRCUITO") return false;
    else{
        unsigned Num_inputs, Num_outputs, Num_portas;
        arquivo.ignore(numeric_limits<streamsize>::max(), ':');
        arquivo >> Num_inputs >> Num_outputs >> Num_portas;
        this->alocar(Num_inputs, Num_outputs, Num_portas);
        getline(arquivo,prov,':');
        if(prov != "PORTAS") return false;
        else{
            for(unsigned i = 0; i < Num_portas; i++){
            int id;
            arquivo >> id;
            if(id != i+1) return false;
            arquivo.ignore(numeric_limits<streamsize>::max(), ' ');
            string nome;
            getline(arquivo,nome,' ');
            ptr_Porta p = aloca(nome);
            if(p == NULL) return false;
            portas[i] = p;
            bool ok = p->ler(arquivo);
            if(!ok) {
                this->limpar();
                //return false;
                    }
                }
            }
        arquivo.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(arquivo,prov,':');
        if(prov != "SAIDAS") return false;
        else{
            for(unsigned i=0; i<Num_outputs; i++){
            int id;
            arquivo>>id;
            if(id!=i+1) return false;
            arquivo.ignore(numeric_limits<streamsize>::max(), ')');
            arquivo>>id;
            if(id < -(getNumInputs()) || id > getNumPortas()) return false;
                id_out[i] = id;
            }
        }
    }
    return true;
}

//Falta implementar!!
ostream &Circuito::imprimir(ostream &O) const{

}

//Falta implementar!!
bool Circuito::salvar(const string &arq) const{

}
//Falta implementar!!
void Circuito::digitarEntradas(){

}

//Falta implementar!!
void Circuito::imprimirEntradas(void) const{

}
//Falta implementar!!
void Circuito::imprimirSaidas(void) const{

}
//Falta implementar!!


void Circuito::simular(){
    for(unsigned i = 0; i < portas.size(); i++) portas[i]->setSaida(UNDEF_3S);
    bool tudo_def, alguma_def;
    bool3S *in_porta;
    do{
        tudo_def = true;
        alguma_def = false;
        for(unsigned i = 0; i < portas.size(); i++){
            if(portas[i]->getSaida() == UNDEF_3S){
                in_porta = new bool3S [portas[i]->getNumInputs()];
                int IdAux;
                for(unsigned j = 0; j < getNumInputsPorta(i); j++){
                    IdAux = portas[i]->getId_in(j);
                    if(IdAux < 0) in_porta[j] = inputs[(-IdAux)-1];
                    in_porta[i] = inputs[i];
                    in_porta[j] = portas[IdAux]->getSaida();
                }
                portas[i]->simular(in_porta);
                delete [] in_porta;
                if(portas[i]->getSaida() == UNDEF_3S) tudo_def = false;
                else alguma_def = true;
            }
        }
    }while(!tudo_def && alguma_def);
}

bool Circuito::simular(vector<bool3S> Inputs){
    if(Inputs.size() != getNumInputs()) return false;
        for(unsigned i=0; i<getNumInputs(); i++){
            inputs[i] = Inputs[i];
        }
    simular();
    return true;
}

void Circuito::gerarTabela(void){
    int i;
    for(unsigned j = 0; j < getNumInputs(); j++) inputs[j]= FALSE_3S;
    do{
        simular(inputs);
        i = int(getNumInputs()-1);
        while(i >= 0 && inputs[unsigned(i)]== UNDEF_3S){
            inputs[unsigned(i)] = FALSE_3S;
            i--;
        }
        if(i>=0){
            if(inputs[unsigned(i)] == FALSE_3S){
                inputs[unsigned(i)] = TRUE_3S;
            }
            else{
                inputs[unsigned(i)] = UNDEF_3S;
            }
        }
    }while(i>=0);
}

