#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "console.h"
#include "sudoku.h"

using namespace std;

/// Leh uma jogada do teclado
/// Significado dos valores:
/*
 \ i | i de 0-8 | i<0 | i>8 e j>=0 |
  \j |    e     | ou  |     ou     |
 v \ | j de 0-8 | j<0 | j>8 e i>=0 |
-----+----------+-----+------------+
1 a 9|   JOGAR  | FIM |  RESOLVER  |
  0  |  APAGAR  | FIM | PREENCHER  |
 > 9 |   NOVO   | FIM |   VOLTAR   |
 < 0 |    FIM   | FIM |     FIM    |
*/
void Jogada::ler()
{
  char tecla;

  Term.gotoYX(20,4);
  cout << "Linha [A-I; V=Voltar ao inicio; N=Novo; P=Preencher imediatas; R=Resolver; S=Sair]? ";
  do
  {
    tecla = toupper(getch());
  } while ((tecla<'A' || tecla>'I') && tecla!='V' && tecla!='N' && tecla!='P' && tecla!='R' && tecla!='S');
  cout << tecla << endl;
  Term.gotoYX(20,4);
  Term.limpar_linha();

  if (tecla=='V')
  {
    // Novo tabuleiro
    i = j = 10;
    v = 10;
    return;
  }
  if (tecla=='N')
  {
    // Novo tabuleiro
    i = j = 5;
    v = 10;
    return;
  }
  if (tecla=='P')
  {
    // Preencher as casas faceis (imediatas)
    i = j = 10;
    v = 0;
    return;
  }
  if (tecla=='R')
  {
    // Resolver o problema
    i = j = 10;
    v = 5;
    return;
  }
  if (tecla=='S')
  {
    // Sair do programa
    i = j = v = -1;
    return;
  }
  i = tecla-'A';  // De 0 a 8
  Term.gotoYX(7+i+i/3,1);
  Term.cores(CONSOLE_BLACK, CONSOLE_WHITE);
  cout << tecla;
  Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);

  Term.gotoYX(20,4);
  cout << "Coluna [1-9]? ";
  do
  {
    tecla = toupper(getch());
  } while (tecla<'1' || tecla>'9');
  cout << tecla << endl;
  Term.gotoYX(20,4);
  Term.limpar_linha();

  j = tecla-'1';  // De 0 a 8
  Term.gotoYX(5,4+2*(j+j/3));
  Term.cores(CONSOLE_BLACK, CONSOLE_WHITE);
  cout << tecla;
  Term.cores(CONSOLE_DEFAULT, CONSOLE_DEFAULT);

  Term.gotoYX(20,4);
  cout << "Valor [1-9; 0=apagar]? ";
  do
  {
    tecla = toupper(getch());
    //aceitar_valor_zero_para_apagar();
  } while (tecla<'0' || tecla>'9');
  cout << tecla << endl;
  Term.gotoYX(20,4);
  Term.limpar_linha();

  v = tecla-'0';  // De 0 a 9

  // Restaura as etiquetas normais
  Term.gotoYX(7+i+i/3,1);
  cout << char('A'+i);
  Term.gotoYX(5,4+2*(j+j/3));
  cout << j+1;
}

/// Imprime o conteudo do tabuleiro S na tela
/// O parametro booleano de entrada "inicial" indica a posicao da impressao:
/// true: lado direito da tela (tabuleiro inicial)
/// false: lado esquerdo da tela (tabuleiro atual)
void imprimir_nas_telas(const Sudoku &S, bool inicial)
{
  int J = (inicial ? 32 : 4);
  Term.ocultar_cursor();
  for (unsigned i=0; i<9; i++)
  {
    for (unsigned j=0; j<9; j++)
    {
      Term.gotoYX(7+i+i/3, J+2*(j+j/3));
      if (S(i,j)>=1 && S(i,j)<=9) cout << int(S(i,j));
      else cout << '-';
      cout << ' ';
      if (!Term.formatado()) if (j%3 == 2) cout << "| ";
    }
    cout << endl;
  }
}

/// Exibir o conteudo do tabuleiro atual
void Sudoku::exibir() const
{
  imprimir_nas_telas(*this, false);
}

/// Exibir o conteudo do tabuleiro inicial
void Sudoku::exibir_origem() const
{
  imprimir_nas_telas(*this, true);
}

/// Exibe os numeros de tabuleiros gerados, testados e a analisar
void Sudoku::exibir_andamento(unsigned Ntab_testados, unsigned Ntab_gerados, unsigned Ntab_analisar) const
{
  //Term.ocultar_cursor();
  Term.gotoYX(19,4);
  cout << "Gerados:          Testados:         A analisar:";
  Term.gotoYX(19,12);
  cout << Ntab_gerados << ' ';
  Term.gotoYX(19,31);
  cout << Ntab_testados << ' ';
  Term.gotoYX(19,51);
  if (Term.formatado()) cout << "    ";
  Term.gotoYX(19,51);
  cout << Ntab_analisar << endl;
}
