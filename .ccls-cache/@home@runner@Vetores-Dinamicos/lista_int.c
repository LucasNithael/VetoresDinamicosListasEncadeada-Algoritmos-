#include "lista_int.h"
#include <stdio.h>
#include <stdlib.h>

struct lista_ll *lista_create() {
  struct lista_ll *lista = (struct lista_ll *)malloc(sizeof(struct lista_ll));
  lista->primeiro = 0;
  lista->ultimo = 0;
  lista->tamanho = 0;
  return lista;
}

void lista_print(struct lista_ll *lista) {
  struct lista *current = lista->primeiro;
  // for(int i=0; i<lista->tamanho ; i++)
  while (current != 0) {
    printf("%d -> ", current->valor);
    current = current->proximo;
  }
  printf("NULL\n");
}

void inserir_inicio(struct lista_ll *lista, int elemento) {
  struct lista *novo = (struct lista *)malloc(sizeof(struct lista));
  novo->valor = elemento;
  novo->proximo = lista->primeiro;
  lista->primeiro = novo;
  lista->tamanho++;
}

unsigned int lista_size(struct lista_ll *lista) { return lista->tamanho; }

void lista_push(struct lista_ll *lista, int elemento) {
  struct lista *novo;
  struct lista *aux;
  novo = (struct lista *)malloc(sizeof(struct lista));
  novo->valor = elemento;
  novo->proximo = NULL;
  if (lista->primeiro == 0)
    lista->primeiro = novo;
  else {
    aux = lista->primeiro;
    while(aux->proximo!=0)
      aux = aux->proximo;
    aux->proximo = novo;
    
  }
  lista->tamanho++;
}

int lista_pop(struct lista_ll *lista) {
  if (lista->primeiro == 0)
    return -1;
  int r = lista->primeiro->valor;
  struct lista *novo = lista->primeiro;
  while (novo->proximo != lista->ultimo)
    novo = novo->proximo;
  novo->proximo = 0;
  free(lista->ultimo);
  lista->ultimo = novo;
  lista->tamanho--;
  return r;
}


int remove_inicio(struct lista_ll *lista){
  if(lista->primeiro==0)
    return -1;
  int r = lista->primeiro->valor;
  struct lista *velho = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  free(velho);
  return r;
}

void lista_insert_index(struct lista_ll *lista, int indice, int elemento){
  struct lista_ll *anterior;
  int i = 0;
  while(i!=indice){
    
  }

}