#include "vetor_int.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  clock_t inicio, fim;
  inicio = clock();
  struct vetor_int *vetor = vetor_create(); // Cria vetor

  for (int i = 0; i < 10; i++)
    vetor_push(vetor, i * 2); // Insere elementos no fim do vetor
  vetor_print(vetor); // Função para percorrer e mostrar elementos do vetor

  printf("\n%d ", vetor_get(vetor, 5)); // Busca elementos por indice

  printf("\n");
  
  for (int i = 0; i < 5; i++)
    vetor_pop(vetor); // Exclue elemento do fim do vetor

  vetor_print(vetor);
  
  printf("\nTamanho do vetor: %d", vetor_tamanho(vetor)); //Consultar tamanho do vetor
  
  printf("\nElemento: %d índice: %d", 10 ,vetor_find(vetor, 10)); //Consultar índice de elemento

  //printf("\nInserir: %d no índice: %d\n",3 ,100);
   //vetor_insert(vetor, 1, 100);          //insere elemento no índice desejado
  //vetor_print(vetor);

  printf("\nRemover do índice: %d\n",3);
  vetor_remove(vetor,  4);    //Remove elemento do índice desejado
  vetor_print(vetor);

  printf("\nCapacidade do vetor: %d", vetor_capacity(vetor));

  printf("\ncupação da capacidade do vetor: %.2lf", vetor_percent(vetor));

  
  
  fim = clock();
  double elapsedTime = (fim - inicio) / (CLOCKS_PER_SEC / 1000.0);
  printf("\nTempo decorrido: %lfms\n", elapsedTime);

  return 0;
}