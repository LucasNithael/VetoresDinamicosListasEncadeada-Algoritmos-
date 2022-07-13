#ifndef _LIST_INT_H_
#define _LIST_INT_H_

struct lista {
  int valor;
  struct lista *proximo;
};

struct lista_ll {
  struct lista *primeiro;
  struct lista *ultimo;
  unsigned int tamanho;
};

struct lista_ll *lista_create();

void lista_print(struct lista_ll *lista);

void inserir_inicio(struct lista_ll *lista, int x);

unsigned int lista_size(struct lista_ll *lista);

void lista_push(struct lista_ll *lista, int x);

int lista_pop(struct lista_ll *lista);

int remove_inicio(struct lista_ll *lista);

void lista_insert_index(struct lista_ll *lista, int indice, int elemento);

#endif