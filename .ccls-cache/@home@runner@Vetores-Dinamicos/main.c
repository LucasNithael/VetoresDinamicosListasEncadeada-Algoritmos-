#include "lista_int.h"
#include "vetor_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t inicio, fim;
  inicio = clock();
  /*VETORES DINÂMICOS*/
  /*struct vetor_int *vetor = vetor_create(); // Cria vetor

  for (int i = 0; i < 12; i++)
    vetor_push(vetor, i); // Insere elementos no fim do vetor
  vetor_print(vetor); // Função para percorrer e mostrar elementos do vetor

  printf("\nElemento do índice %d : %d",5 ,vetor_get(vetor, 5)); // Busca
  elementos por indice

  printf("\n");

  for (int i = 0; i < 5; i++)
    vetor_pop(vetor); // Exclue elemento do fim do vetor

  vetor_print(vetor);

  printf("\nTamanho do vetor: %d", vetor_tamanho(vetor)); //Consultar tamanho do
  vetor

  printf("\nElemento: %d índice: %d", 10 ,vetor_find(vetor, 10)); //Consultar
  índice de elemento

  printf("\nInserir: %d no índice: %d\n",3 ,100);
   vetor_insert(vetor, 3, 100);          //insere elemento no índice desejado
  vetor_print(vetor);

  printf("\nRemover do índice: %d\n",3);
  vetor_remove(vetor,  3);    //Remove elemento do índice desejado
  vetor_print(vetor);

  printf("\nTamanho do vetor: %d", vetor_size(vetor));
  printf("\nCapacidade do vetor: %d", vetor_capacity(vetor));

  //vetor_destroy(vetor);

  printf("\nOcupação da capacidade do vetor: %.2lf", vetor_percent(vetor));*/

  /*  LISTA DUPLAMENTE LIGADA*/

  struct lista_ll *lista = lista_create();

  for (int i = 1; i < 5; i++) {
    lista_push(lista, i);
  }

  // remove_inicio(lista);

  lista_print(lista);

  // lista_print(lista);

  lista_insert_index(lista, 1, 5);
  lista_print(lista);
  
  printf("Tamanho da lista: %d\n", lista_size(lista));

  fim = clock();
  double elapsedTime = (fim - inicio) / (CLOCKS_PER_SEC / 1000.0);
  printf("\nTempo decorrido: %lfms\n", elapsedTime);

  return 0;
}