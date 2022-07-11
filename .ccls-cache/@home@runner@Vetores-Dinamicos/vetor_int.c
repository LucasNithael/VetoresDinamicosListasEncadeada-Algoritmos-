#include "vetor_int.h"
#include <stdio.h>
#include <stdlib.h>

struct vetor_int {
  int *dado;
  unsigned int tamanho, capacidade;
};

void vetor_print(vetor_int *vetor) {
  printf("{ ");
  for (int i = 0; i < vetor->tamanho; i++)
    printf("%d ", vetor->dado[i]);
  printf("}");
}

vetor_int *vetor_create() {
  vetor_int *vetor = (vetor_int *)malloc(sizeof(vetor_int));
  vetor->dado = (int *)malloc(sizeof(int) * 10);
  vetor->tamanho = 0;
  vetor->capacidade = 10;
  return vetor;
}

int vetor_get(vetor_int *vetor, int indice) {
  if (indice >= 0 && indice <= vetor->tamanho - 1)
    return vetor->dado[indice];
  return -1;
}

unsigned int vetor_push(vetor_int *vetor, int x) {
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
  vetor->dado[vetor->tamanho++] = x;
  return sucesso;
}

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

unsigned int vetor_tamanho(vetor_int *vetor) {
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
  if (indice >= vetor->tamanho)
    for (int i = indice; i < vetor->tamanho + 1; i++) {
      vetor->dado[i + 1] = vetor->dado[i];
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

void vetor_destroy(vetor_int *vetor){
  free(vetor);
}
