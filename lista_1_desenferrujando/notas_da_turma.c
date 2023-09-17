#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media) {
  celula *p;
  p = le->prox;
  while(p != NULL) {
    if(p->mediaAtividades <= media) {
      l1->prox = p;
      l1 = l1->prox;
    } else {
      l2->prox = p;
      l2 = l2->prox;
    }
    p = p->prox;
  }
  l1->prox = NULL;
  l2->prox = NULL;
}
