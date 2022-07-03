#include <stdio.h>
#include "vetor_int.h"

int main(void) {
  int capacidade=10, tamanho=0;
  int a[capacidade];
  for(int i=0 ; i<10 ; i++)
    tamanho = append_int(a, tamanho, capacidade, i*2);
  for(int i=0 ; i<10 ; i++)
    printf("%d ", a[i]);
  
  return 0;
}