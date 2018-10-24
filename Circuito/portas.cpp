#include <iostream>
#include "portas.h"
#include "bool3S.h"

#define NUM_MAX_INPUTS_PORTA 4

using namespace std;

Porta::Porta(unsigned NI){
    if(NI > NUM_MAX_INPUTS_PORTA){
        Nin = 4;
        for (int i = 0; i < NUM_MAX_INPUTS_PORTA; ++i) id_in[i] = 0;
    }else{
        Nin = NI;
        for (int i = 0; i < NI; ++i) id_in[i] = 0;
    }
}

Porta::Porta(const Porta &){

}
