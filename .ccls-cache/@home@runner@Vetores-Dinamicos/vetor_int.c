#include "vetor_int.h"
#include <stdio.h>
#include <stdlib.h>

struct vetor_int {
  int *dado;
  unsigned int tamanho, capacidade;
};


/*
-Função sem retorno para mostrar os elementos do vetor inserido como arguemtno;
-Percorre o vetor de acordo com seu tamanho e imprime os elementos do índice 0 ao tamanho-1;
-Seu desempenho Big O: O(n);
*/
void vetor_print(vetor_int *vetor) {
  printf("{ ");
  for (int i = 0; i < vetor->tamanho; i++)
    printf("%d ", vetor->dado[i]);
  printf("}");
}

/*
-Função para criar um vetor com espaço de memória;
-*vetor: é criado o ponteiro que recebe o espaço de memória de acordo com tipo do struct que será retornado para o ponteiro que apontará para o mesmo espaço de memória;
-Tamanho: para esta função não é necessário definir o tamanho do vetor;
-Capacidade: o valor da capacidade é mutável para casos de testes;
-Dado: o espaço que ficará armazenado os valores definidos para o vetor será de acordo com a capacidade do vetor;
-Seu desempenho Big O: O(1);
*/
vetor_int *vetor_create() {
  vetor_int *vetor = (vetor_int *)malloc(sizeof(vetor_int));
  vetor->tamanho = 0;
  vetor->capacidade = 10;
  vetor->dado = (int*)malloc(sizeof(int)*vetor->capacidade);
  return vetor;
}

/*
-Função usada para consultar o elemento do índice recebido com parâmetro;
-É definida uma condição para verificar se o índice pertence ao intervalo valido para a consulta;
-È retornado o valor do índice;
-Desempenho Big O: O(1);
*/
int vetor_get(vetor_int *vetor, int indice) {
  if (indice >= 0 && indice <= vetor->tamanho - 1)
    return vetor->dado[indice];
  return 0;
}

/*
-Função usada para inserir elementos no fim do vetor;
-Sucesso: variável que define se a função foi executada com sucesso: sim!=0 , não=0;
-Verificação para saber se a quantidade de elementos chegou ao capacidade limite, se sim, a capacidade será incrementada 100% do seu valor;
-*opia: ponteiro que terá o tamanho da nova capacidade;
-*antigo: recebe os dados do *vetor;
-for: *copia recebe os elementos do *vetor apotados por *antigo
-Os dados do *vetor com capaciade antiga recebe os mesmo dados apontados por *copia com a capacidade acrescentada;
-Liberamos o espaço de memória de antigo;
-O elemento é inserido no índice tamnho++;
-Desempenho Big O: O(n);
*/
unsigned int vetor_push(vetor_int *vetor, int x) {
  int sucesso = 0;
  if (vetor->tamanho == vetor->capacidade) {
    vetor->capacidade = vetor->capacidade + vetor->capacidade;
    int *copia = (int *)malloc(sizeof(int) * (vetor->capacidade));
    int *antigo = vetor->dado;
    for (int i = 0; i < vetor->tamanho; i++)
      *(copia + i) = *(antigo + i);
    vetor->dado = copia;
    free(antigo);
    sucesso++;
  }
  vetor->dado[vetor->tamanho++] = x;
  return sucesso;
}

/*
-Função para excluir último elemento;
-Sucesso: variável que define se a função foi executada com sucesso: sim!=0 , não=0;
-Verifica se há elementos no vetor;
-
*/
unsigned int vetor_pop(vetor_int *vetor) {
  int sucesso = 0, i;
  if (vetor->tamanho > 0) {
    vetor->tamanho--;
    int *copia = (int *)malloc(sizeof(int) * (vetor->capacidade));
    for (i = 0; i < vetor->tamanho; i++)
      *(copia + i) = *(vetor->dado + i);
    vetor->dado = copia;
    sucesso++;
  }
  return sucesso;
}

unsigned int vetor_size(vetor_int *vetor) {
  if (vetor->tamanho > 0)
    return vetor->tamanho;
  return 0;
}

int vetor_find(vetor_int *vetor, int elemento) {
  int indice = -1;
  for (int i = 0; i < vetor->tamanho; i++)
    if (vetor->dado[i] == elemento)
      indice = i;
  return indice;
}

int vetor_insert(vetor_int *vetor, int indice, int elemento) {
  int sucesso = 0;
  if (vetor->tamanho == vetor->capacidade) {
    vetor->capacidade = vetor->capacidade + 10;
    int *copia = (int *)malloc(sizeof(int) * (vetor->capacidade));
    int *antigo = vetor->dado;
    for (int i = 0; i < vetor->tamanho; i++)
      *(copia + i) = *(antigo + i);
    vetor->dado = copia;
    free(antigo);
    sucesso++;
  }

  for (int i = vetor->tamanho; i >= indice; i--) {
    vetor->dado[i] = vetor->dado[i-1];
    
  }
  
  vetor->dado[indice] = elemento;
  vetor->tamanho++;
  return sucesso;
}

int vetor_remove(vetor_int *vetor, int indice) {
  int sucesso = 0;
  if (vetor->tamanho > 0)
    sucesso++;
  for (int i = indice; i < vetor->tamanho; i++)
    vetor->dado[i] = vetor->dado[i + 1];
  vetor->tamanho--;
  return sucesso;
}

int vetor_capacity(vetor_int *vetor) {
  int capacidade = -1;
  if (vetor->capacidade > 0)
    capacidade = vetor->capacidade;
  return capacidade;
}

double vetor_percent(vetor_int *vetor) {
  double percentual = 0, tamanho = vetor->tamanho,
         capacidade = vetor->capacidade;
  if (vetor->capacidade > 0)
    percentual = tamanho / capacidade;
  return percentual;
}

void vetor_destroy(vetor_int *vetor) { free(vetor); }
