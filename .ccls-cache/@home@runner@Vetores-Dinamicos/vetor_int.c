#include "vetor_int.h"

int append_int(int a[], int tamanho, int capacidade, int x){
  if(tamanho!=capacidade)
    a[tamanho++]=x;
  return tamanho;
}