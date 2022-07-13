#ifndef _ARRAY_INT_H_ 
#define _ARRAY_INT_H_

typedef struct vetor_int vetor_int;


void vetor_print(vetor_int *vetor);

vetor_int * vetor_create();

int vetor_get(vetor_int *vetor, int indice);

unsigned int vetor_push(vetor_int *vetor, int x);

unsigned int vetor_pop(vetor_int *vetor);

unsigned int vetor_size(vetor_int *vetor);

int vetor_find(vetor_int *vetor, int elemento);

int vetor_insert(vetor_int *vetor, int indice, int elemento);

int vetor_remove(vetor_int *vetor, int indice);

int vetor_capacity(vetor_int *vetor);

double vetor_percent(vetor_int *vetor);

void vetor_destroy(vetor_int *vetor);

#endif