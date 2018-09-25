#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "console.h"
#include "sudoku_main.h"

using namespace std;

/* ===================================================================
AS FUNCOES DE ENTRADA/SAIDA FORMATADA
=================================================================== */

/// Desenha as linhas dos tabuleiros direito (incial=true) e esquerdo (inicial=false)
void desenha_moldura(bool inicial)
{
  Term.ocultar_cursor();
  int J = (inicial ? 29 : 1);

  // Muda para o modo de desenho de linhas
  Term.modo_linhas();

  for (unsigned i=7; i<=17; i++)
  {
    Term.gotoYX(i,J+1);
    cout << "x       x       x       x";  // |   |   |   |
  }
  for (unsigned i=0; i<4; i++)
  {
    Term.gotoYX(6,J+1);
    cout << "lqqqqqqqwqqqqqqqwqqqqqqqk";  // -------------
    Term.gotoYX(10,J+1);
    cout << "tqqqqqqqnqqqqqqqnqqqqqqqu";  // -------------
    Term.gotoYX(14,J+1);
    cout << "tqqqqqqqnqqqqqqqnqqqqqqqu";  // -------------
    Term.gotoYX(18,J+1);
    cout << "mqqqqqqqvqqqqqqqvqqqqqqqj";  // -------------
  }

  // Retorna para o modo normal
  Term.modo_texto();

  // Imprime as etiquetas
  for (unsigned i=0; i<9; i++)
  {
    Term.gotoYX(7+i+i/3,J);
    cout << char('A'+i);
    Term.gotoYX(5,J+3+2*(i+i/3));
    cout << i+1;
  }
}

/// Desenha os textos iniciais e molduras dos tabuleiros
void exibir_cabecalho()
{
  if (!Term.formatado())
  {
    cerr << "O terminal nao permite saida formatada!\n";
    cerr << "Este arquivo soh pode ser executado no Windows 10\n";
    cerr << "Compile com o arquivo na versao nao formatada (sudoku_main_form_none)\n";
    cerr << "Saindo...\n";
    exit(1);
  }

  Term.tela_alternativa();
  Term.clrscr();

  Term.modo_linhas();
  Term.cores(CONSOLE_BRIGHT_YELLOW, CONSOLE_DEFAULT);
  cout << " lqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqk \n";
  cout << " x                                                   x \n";
  cout << " mqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqj \n";
  Term.modo_texto();
  Term.gotoYX(2,3);
  Term.cores(CONSOLE_BRIGHT_BLACK, CONSOLE_BRIGHT_YELLOW);
  cout << "                      SUDOKU                       ";
  Term.cores(CONSOLE_BRIGHT_WHITE, CONSOLE_DEFAULT);
  Term.gotoYX(4,7);
  cout << "TABULEIRO ATUAL";
  Term.gotoYX(4,34);
  cout << "TABULEIRO INICIAL";
  Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);

  desenha_moldura(true);
  desenha_moldura(false);
}

/// Informa que o tabuleiro foi resolvido
void exibir_congratulacoes()
{
  Term.gotoYX(20,16);
  Term.limpar_linha();
  Term.cores(CONSOLE_BRIGHT_GREEN, CONSOLE_DEFAULT);
  cout << "PARABENS! JOGO CONCLUIDO!";
  Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);
  espera_tecla();
  Term.gotoYX(20,4);
  Term.limpar_linha();
}

/// Exibe o numero de casas faceis preenchidas imediatamente
void exibir_preenchidas(int N)
{
  if (N != 0)
  {
    unsigned NN = abs(N);
    if (NN <= 81)
    {
      Term.gotoYX(19,4);
      cout << NN << ' ';
      if (NN>1)
      {
        cout << "casas preenchidas.";
      }
      else
      {
        cout << "casa preenchida.";
      }
    }
    if (N < 0)
    {
      Term.gotoYX(20,4);
      cout << "O TABULEIRO NAO TEM SOLUCAO!\n";
    }
    espera_tecla();
    Term.gotoYX(20,1);
    Term.limpar_linha();
    Term.gotoYX(19,1);
    Term.limpar_linha();
  }
}

/// Espera para que o usuario veja a resposta do algoritmo de resolucao
void exibir_resposta()
{
  espera_tecla();
  Term.gotoYX(20,1);
  Term.limpar_linha();
  Term.gotoYX(19,1);
  Term.limpar_linha();
}

/// Imprime msg e espera que o usuario digite uma tecla
void espera_tecla()
{
  Term.exibir_cursor();
  Term.gotoYX(22,13);
  cout << "Qualquer tecla para continuar: ";
  getch();
  cout << endl;
  Term.gotoYX(22,1);
  Term.limpar_linha();
}

/// Encerra o modo de exibicao formatada
void encerra_exibicao()
{
  Term.tela_normal();
}
