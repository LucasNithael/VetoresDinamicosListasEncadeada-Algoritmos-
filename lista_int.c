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

unsigned int lista_size(struct lista_ll *lista) { return lista->tamanho; }

void lista_push(struct lista_ll *lista, int elemento) {
  struct lista *novo;
  struct lista *aux;
  novo = (struct lista *)malloc(sizeof(struct lista));
  novo->valor = elemento;
  novo->anterior = lista->ultimo;
  novo->proximo = NULL;
  if (lista->primeiro == 0){
    lista->primeiro = novo;
    novo->anterior=NULL;
  }
  else {
    aux = lista->primeiro;
    while (aux->proximo != 0)
      aux = aux->proximo;
    aux->proximo = novo;
    novo->anterior = aux;
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


/*Precisa de lista duplamente encadeada*/
void lista_insert_index(struct lista_ll *lista, int indice, int elemento) {
  struct lista *novo;
  novo->valor = elemento;
  struct lista *aux = lista->primeiro;
  for (int i = 0; i < indice; i++) {
    aux = aux->proximo;
  }
  novo->proximo = aux->proximo;  
  aux->proximo = novo;
  novo->anterior = aux;
  (novo->proximo)->anterior = novo;

}

/*int remove_inicio(struct lista_ll *lista){
  if(lista->primeiro==0)
    return -1;
  int r = lista->primeiro->valor;
  struct lista *velho = lista->primeiro;
  lista->primeiro = lista->primeiro->proximo;
  free(velho);
  return r;
}*/

/*void inserir_inicio(struct lista_ll *lista, int elemento) {
  struct lista *novo = (struct lista *)malloc(sizeof(struct lista));
  novo->valor = elemento;
  novo->proximo = lista->primeiro;
  lista->primeiro = novo;
  lista->tamanho++;
}*/