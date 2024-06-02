#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} no;

int altura(no* r) {
  if(r == NULL) 
    return 0;
  else {
    int left_h = altura(r->esq);
    int right_h = altura(r->dir);

    return (left_h > right_h ? left_h +1: right_h+1);
  }

}
