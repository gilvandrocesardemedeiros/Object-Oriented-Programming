#include <iostream>
#include <cstdlib> // para abs()
#include "sudoku_main.h"

using namespace std;

/* ===================================================================
AS FUNCOES DE ENTRADA/SAIDA FORMATADA
=================================================================== */

// Desenha os textos iniciais e molduras dos tabuleiros
void exibir_cabecalho()
{
  cout << " +-----------------------+\n";
  cout << " |         SUDOKU        |\n";
  cout << " +-----------------------+\n";
}

// Informa que o tabuleiro foi resolvido
void exibir_congratulacoes()
{
  cout << "PARABENS! JOGO CONCLUIDO!\n";
  espera_tecla();
}

// Exibe o numero de casas faceis preenchidas imediatamente
void exibir_preenchidas(int N)
{
  if (N != 0)
  {
    unsigned NN = abs(N);
    if (NN <= 81)
    {
      cout << NN << ' ';
      if (NN>1)
      {
        cout << "casas preenchidas.\n";
      }
      else
      {
        cout << "casa preenchida.\n";
      }
    }
    if (N < 0)
    {
      cout << "O TABULEIRO NAO TEM SOLUCAO!\n";
    }
    espera_tecla();
  }
}

// Espera para que o usuario veja a resposta do algoritmo de resolucao
void exibir_resposta()
{
  espera_tecla();
}

// Imprime msg e espera que o usuario digite uma tecla
void espera_tecla()
{
  char tecla;
  cout << "Qualquer tecla para continuar: ";
  cin >> tecla;
}

// Encerra o modo de exibicao formatada
void encerra_exibicao()
{
}
