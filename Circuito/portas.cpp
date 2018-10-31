#include <iostream>
#include "portas.h"
#include "bool3S.h"

#define NUM_MAX_INPUTS_PORTA 4

using namespace std;

Porta::Porta(unsigned NI){
    //Numero de inputs nao pode ser superior ao num_max_inputs nem inferior a 2
    if(NI < 2 || NI > NUM_MAX_INPUTS_PORTA){
        //Vale a pena / pode ser feito isso aqui?
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
    if(i > Nin) return 0;
    else{
        return id_in[i-1];
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
    //Porque esse metodo nao pode ser inline?
    saida = s;
}

void Porta::setId_in(unsigned i, int Id){
    if(i > Nin){
        return;
    }
    else{
        id_in[i-1] = Id;
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
    I.ignore(1,':');
    for(unsigned i = 0; i < N_inputs; i++){
        I >> id_in[i];
        if(id_in[i] == 0) return false;
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
    if(N != 1){
        id_in[0] = 0;
        return;
    }else{
    Nin = 1;
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
    I.ignore(1,':');
    I >> id_in[0];
    if(id_in[0] == 0) return false;
    Nin = 1;
    return true;
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

//O que faz essa funcao alocar??
void Circuito::alocar(unsigned NI, unsigned NO, unsigned NP){
    limpar();
    if(NI < 1 || NO < 1 || NP < 1) return;
    for(unsigned i = 0; i < NI; i++) inputs.push_back(UNDEF_3S);
    for(unsigned i = 0; i < NO; i++) id_out.push_back(0);
    for(unsigned i = 0; i < NP; i++) portas.push_back(NULL);
}


//Esse metodo estah implementado da forma correta?
void Circuito::copiar(const Circuito &C){
    limpar();
    unsigned Ninputs = C.getNumInputs();
    unsigned Nout = C.getNumOutputs();
    unsigned Nportas = C.getNumPortas();
    if(Ninputs < 1 || Nout < 1 || Nportas < 1) return;
    //Isso estah errado?
    for(unsigned i = 0; i < Ninputs; i++) inputs.push_back(C.inputs[i]);
    for(unsigned i = 0; i < Nout; i++) id_out.push_back(C.id_out[i]);
    //Isso aqui estah certo??
    for(unsigned i = 0; i < Nportas; i++) portas.push_back(C.portas[i]->clone());
}

string Circuito::getNomePorta(unsigned IdPorta) const{
    if(IdPorta > portas.size()) return "ERRO";
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

//Falta implementar
bool Circuito::valido() const{

}

//FALTA FAZER A PORTA SER DO TIPO FORNECIDO PELA STRING T!!!!
//COMO FAZER??
void Circuito::setPorta(unsigned IdPorta, const string &T, unsigned NIn){
    if(IdPorta > portas.size()) return;
    portas[IdPorta-1]->setNumInputs(NIn);
}

void Circuito::setId_inPorta(unsigned IdPorta, unsigned I, int Id) const
{
    if(IdPorta < 1 || I < 1) return;
    if(IdPorta > portas.size() || I > portas[IdPorta-1]->getNumInputs()) return;
    if(unsigned(abs(Id)) > portas[Id-1]->getNumInputs()) return;
    portas[IdPorta-1]->setId_in(I,Id);
}

void Circuito::setIdOutput(unsigned IdOut, int Id)
{
    if(IdOut > id_out.size() || unsigned(abs(Id)) > portas.size() || unsigned(abs(Id)) > inputs.size()) return;
    id_out[IdOut] = Id;

}

void Circuito::simular()
{
    for(unsigned i=0; i<getNumPortas(); i++) portas[i]->setSaida(UNDEF_3S);
    bool tudo_def, alguma_def;
    bool3S *in_porta;

    do{
        tudo_def = true;
        alguma_def = false;
        for(unsigned i=0; i<getNumPortas(); i++)
        {
            if(portas[i]->getSaida() == UNDEF_3S)
            {
                in_porta = new bool3S [getNumInputsPorta(i)];

                for(unsigned j=0; j<getNumInputsPorta(i); j++) in_porta[i] = inputs[i];

                portas[i]->simular(in_porta);

                delete [] in_porta;

                if(portas[i]->getSaida() == UNDEF_3S) tudo_def = false;
                else
                {
                    alguma_def = true;
                }
            }

        }
    }while(!tudo_def && alguma_def);
}

void Circuito::gerarTabela(void){
   int i;
    for(unsigned j=0; j<getNumInputs(); j++) inputs[j]=bool3S(false);
    do{
        simular();
        i = int(getNumInputs()-1);
        while(i>=0 && inputs[unsigned(i)]==UNDEF_3S)
        {
            inputs[unsigned(i)] = bool3S(false);
            i--;
        }
        if(i>=0)
        {
            if(inputs[unsigned(i)] == false)
            {
                inputs[unsigned(i)] = bool3S(true);
            }
            else
            {
                inputs[unsigned(i)] = UNDEF_3S;
            }
        }
    }while(i>=0);
}
