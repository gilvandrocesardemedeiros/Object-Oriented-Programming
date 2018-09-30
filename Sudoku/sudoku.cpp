#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <fstream>
#include <string>
#include <stack>
#include <time.h>

#include "sudoku.h"

using namespace std;

/**********************************************************
 * CLASSE JOGADA                                          *
 **********************************************************/

/// Construtor (por default, cria Jogada que termina o jogo)
Jogada::Jogada(int I, int J, int V)
{
    setCell(I,J);
    setValue(V);
}

/// Fixa as coordenadas de uma jogada
/// Por default, cria Jogada que termina o jogo
void Jogada::setCell(int I, int J)
{
    if (I<0 || I>8) I=-1;
    if (J<0 || J>8) J=-1;
    i = I;
    j = J;
}

/// Fixa o valor de uma jogada
/// Por default, cria Jogada que termina o jogo
void Jogada::setValue(int V)
{
    if (V<0 || V>9) V=-1;
    v = V;
}

/**********************************************************
 * CLASSE SUDOKU                                          *
 **********************************************************/

/// Limpa o tabuleiro
void Sudoku::limpar()
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    set(i,j) = 0;
  }
}

/// Gera um novo tabuleiro preenchido de maneira aleatoria em algumas casas
/// Esse algoritmo nao eh otimizado, no sentido que nao hah garantia de que
/// o tabuleiro gerado tenha solucao ou que tenha solucao unica.
void Sudoku::gerar()
{
  Jogada J;
  int i,k,n;

  srand(time(NULL));

  do
  {
    // Inicia com o tabuleiro vazio
    limpar();

    // Sorteia o numero "n" de casas a serem preenchidas: de 17 a 27
    // Sabe-se que nao existe nenhum tabuleiro de Sudoku com menos de 17 pedras
    // iniciais que tenha solucao unica
    // O valor maximo 27 foi escolhido de forma arbitraria
    n = 17+rand()%11;

    // Preenche aleatoriamente "n" casas do tabuleiro
    for (i=0; i<n; i++)
    {
      do
      {
        J.i = rand()%9;
        J.j = rand()%9;
        J.v = 1+rand()%9;
      } while (!jogada_valida(J));
      fazer_jogada(J);
    }
    // Resolve as casas triviais
    k = resolver_casas_faceis();
    // Recalcula se o tabuleiro for insoluvel ou se jah tiver muitas casas preenchidas
  } while (k<0 || num_casas_vazias()<40);
}

/// Cria um tabuleiro com o conteudo do arquivo nome_arq
/// Caso nao consiga ler do arquivo, retorna tabuleiro vazio
/// ou lido parcialmente, caso contrario
Sudoku::Sudoku(const char *nome_arq): tab(81)
{
  // Comeca com tabuleiro vazio
  limpar();

  // Le o tabuleiro inicial de arquivo
  ifstream arq(nome_arq);
  if (!arq.is_open())
  {
    return;
  }

  string prov;
  int valor;

  arq >> prov;
  if (prov != "SUDOKU")
  {
    return;
  }

  // Leh as pedras do arquivo
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    arq >> valor;
    if (valor != 0)
    {
      Jogada J(i,j,valor);
      fazer_jogada(J);
    }
  }
  arq.close();
}

/// Compara se dois tabuleiros sao iguais
bool Sudoku::operator==(const Sudoku &S) const
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (at(i,j) != S(i,j)) return false;
  }
  return true;
}

/// Testa se a jogada J eh possivel para o tabuleiro
bool Sudoku::jogada_valida(Jogada J) const
{
  unsigned i,j;
  // Testar a jogada
  if (!J.jogada()) return false;

  // Testar se a casa nao estah vazia
  if (at(J.i,J.j) != 0) return false;

  // Testar a linha
  for (i=0; i<9; i++)
  {
    if (at(i,J.j) == J.v) return false;
  }
  // Testar a coluna
  for (j=0; j<9; j++)
  {
    if (at(J.i,j) == J.v) return false;
  }
  // Testar o bloco
  unsigned iIni = 3*(J.i/3);
  unsigned jIni = 3*(J.j/3);
  for (i=0; i<3; i++) for (j=0; j<3; j++)
  {
    if (at(iIni+i,jIni+j) == J.v) return false;
  }
  return true;
}

/// Testa se a jogada J eh um apagamento valido de uma casa para o tabuleiro,
/// levando em conta o tabuleiro original (nao eh permitido apagar casas que
/// estavam preenchidas no tabuleiro original)
bool Sudoku::apagamento_valido(Jogada J, const Sudoku &Origem) const
{
  // Testar a jogada
  if (!J.apagamento()) return false;

  // Testar se a casa estah vazia
  if (at(J.i,J.j) == 0) return false;

  // Testar se a casa do tabuleiro original nao estah vazia
  if (Origem(J.i,J.j) != 0) return false;

  return true;
}

/// Testa se o tabuleiro estah completo (fim de jogo)
bool Sudoku::fim_de_jogo() const
{
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (at(i,j) == 0) return false;
  }
  return true;
}

/// Retorna o numero de casas vazias no tabuleiro
unsigned Sudoku::num_casas_vazias() const
{
  unsigned N(0);
  for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
  {
    if (at(i,j) == 0) N++;
  }
  return N;
}

/// Calcula o valor possivel para preencher a casa (i,j)
/// utilizando apenas as regras "faceis" (linha, coluna e bloco)
/// Se houver mais de uma possibilidade de preenchimento, retorna 0
/// Se houver uma unica possibilidade de preenchimento, retorna o valor
/// Se nao houver nenhuma possibilidade de preenchimento, retorna <0
int Sudoku::calcular_possibilidades(unsigned i, unsigned j) const
{
  // A principio, todos os 9 valores de jogada sao possiveis
  bool valor_possivel[]={true,true,true,true,true,true,true,true,true};
  unsigned ii,I,jj,J,k;

  // Se a casa jah estiver preenchida, nao hah nenhuma possibilidade
  if (at(i,j)!=0) return -1;

  // Varre a linha
  for (k=0; k<9; k++)
  {
    if (at(i,k)>0) valor_possivel[at(i,k)-1] = false;
  }
  // Varre a coluna
  for (k=0; k<9; k++)
  {
    if (at(k,j)>0) valor_possivel[at(k,j)-1] = false;
  }
  // Varre a quadra
  I = 3*(i/3);
  J = 3*(j/3);
  for (ii=0; ii<3; ii++) for (jj=0; jj<3; jj++)
  {
    if (at(I+ii,J+jj)>0) valor_possivel[at(I+ii,J+jj)-1] = false;
  }
  // Conta o numero de valores possiveis
  unsigned num_possivel=0;
  for (k=0; k<9; k++)
  {
    if (valor_possivel[k]) num_possivel++;
  }
  // Nao hah nenhum valor possivel
  if (num_possivel == 0) return -1;
  // Hah mais de um valor possivel
  if (num_possivel > 1) return 0;
  // Hah uma unica possibilidade de preenchimento da casa
  // Retorna o valor possivel
  k = 0;
  while (!valor_possivel[k]) k++;
  return k+1;
}

/// Preenche todas as casas "faceis" do tabuleiro, ou seja, aquelas que tem um
/// unico valor possivel pelas regras do Sudoku
/// Retorna o numero de casas adicionais preenhidas (0 ou >0) ou entao
/// retorna <0 se houver alguma casa sem possibilidade de jogada (tabuleiro insoluvel)
/// Quando retorna um valor negativo (ou seja, o tabuleiro eh insoluvel), o numero
/// retornado serah o negativo do numero de casas preenchidas. Caso nenhuma casa
/// tenha sido preeenchida e o tabuleiro seja insoluvel, serah retornado um numero
/// negativo menor que -81.
int Sudoku::resolver_casas_faceis()
{
  unsigned num_casas=0;
  bool insoluvel(false),resolveu_alguma;
  unsigned i,j;
  int valor;

  do
  {
    resolveu_alguma = false;
    for (i=0; i<9; i++) for (j=0; j<9; j++) if (at(i,j)==0)
    {
      valor = calcular_possibilidades(i,j);
      if (valor < 0)
      {
        // Hah uma casa na qual nenhum valor eh possivel
        // O tabuleiro nao tem solucao
        insoluvel = true;
      }
      if (valor > 0)
      {
        set(i,j) = valor;
        resolveu_alguma = true;
        num_casas++;
      }
    }
  } while (resolveu_alguma);
  if (insoluvel)
  {
      if (num_casas==0) return -666;
      return (-num_casas);
  }
  return num_casas;
}

/// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
/// O parametro com_exibicao controla se o algoritmo deve (true) ou nao (false)
/// exibir os tabuleiros analisados e o numero de nohs durante o algoritmo
/// Retorna true se foi encontrada solucao

///
/// ATENCAO: ESSE ALGORITMO NAO EH O CORRETO!!!
/// Eh apenas um exemplo, que tenta resolver o problema aleatoriamente
/// Voces devem substituir pelo seu proprio algoritmo
///

bool Sudoku::resolver(bool com_exibicao)
{
  ///Pilha onde serah armazenado os Sudoku possiveis
  stack<Sudoku> tentativas;
  ///Adicionando o Sudoku base para a pilha "tentativas"
  tentativas.push(*this);
  /// Contadores do numero de tabuleiros gerados e testados
  int num_tab_gerados(1), num_tab_testados(1);
  /// Melhor serah o tabuleiro encontrado com mais casas preenchidas
  Sudoku Melhor(*this);
  ///Execute enquanto houver alguma tentativa no container
  while(tentativas.size() > 0){
 /* // Reinicializa o gerador de numeros aleatorios
  srand(time(NULL));
*/
  /// Testa se jah nao estah resolvido desde o inicio
  if (this->fim_de_jogo()) return true;
  // Numero de casas vazias do melhor tabuleiro ateh agora
  int num_vazias_melhor = Melhor.num_casas_vazias();

  // O tabuleiro em analise
  // Comeca a busca a partir do tabuleiro inicial
  Sudoku S(*this);
  // Numero de casas vazias do tabuleiro em analise
  int num_vazias;

  bool achou_solucao;
  int i,j,k;

  do
  {
    // Escolhe a primeira casa vaga
    i=0; j=0;
    while (i<9 && S(i,j) != 0)
    {
      j++;
      if (j>=9)
      {
        j=0;
        i++;
      }
    }
    if (i>=9)
    {
      // Nao existe casa vazia!
      // O que eh impossivel de acontecer, pois se o tabuleiro
      // fosse solucao, teria sido detectado no passo anterior
      // Nunca deve entrar aqui!!!
      *this = S;
      if (com_exibicao)
      {
        S.exibir();
      }
      return true;
    }

    // Sorteia um valor de jogada para a casa
    // Se soh houver um valor possivel, nao faz sorteio e joga esse valor
    Jogada J(i,j);
    // Calcula a(s) possibilidades de jogada na casa (i,j)
    k = S.calcular_possibilidades(i,j);
    if (k<0)
    {
      // Tabuleiro S nao tem solucao
      J.setValue(-1); // Jogada invalida
    }
    else if (k==0)
    {
      // Existe mais de uma possibilidade de jogada
      // Escolhe aleatoriamente
      do
      {
        J.setValue(1+rand()%9);
      } while (!S.jogada_valida(J));
    }
    else
    {
      // Soh existe uma possibilidade de jogada
      J.setValue(k);
    }

    if (!S.jogada_valida(J))
    {
      // Tabuleiro em analise tem uma casa sem possibilidade de preenchimento
      // Nao eh possivel gerar um novo tabuleiro a partir dele
      // Recomeca a busca a partir do tabuleiro inicial
      S = *this;
    }
    else
    {
      S.fazer_jogada(J);
      num_tab_gerados++;

      // Calcula quantas casas faltam no tabuleiro
      num_vazias = S.num_casas_vazias();
      if (num_vazias < num_vazias_melhor)
      {
        Melhor = S;
        num_vazias_melhor = num_vazias;
      }
      // Testa se o tabuleiro eh solucao
      achou_solucao = (num_vazias == 0);
      num_tab_testados++;

      // Exibe o andamento do algoritmo de resolucao
      if (com_exibicao)
      {
        // Exibe o tabuleiro que foi gerado e testado
        S.exibir();
        // O terceiro parametro eh o numero de nos gerados mas ainda nao testados;
        // nesse algoritmo incorreto, eh sempre zero
        S.exibir_andamento(num_tab_testados, num_tab_gerados, 0);
      }
    }
    // Para ao encontrar uma solucao ou ao atingir o numero maximo de nos
  } while(!achou_solucao && num_tab_gerados<5000);

  if (achou_solucao) *this = Melhor;
  if (com_exibicao)
  {
    Melhor.exibir();
  }
  return achou_solucao;
  }
}
