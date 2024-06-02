#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} no;

no* encontrar_antecessor(no* r) {
  no* atual = r->esq;
  while (atual->dir != NULL) {
    atual = atual->dir;
  }
  return atual;
}

no* remover(no* r, int x) {
  if (r == NULL) {
    return r;
  }

  if (x < r->chave) {
    r->esq = remover(r->esq, x);
  } else if (x > r->chave) {
    r->dir = remover(r->dir, x);
  } else {
    if (r->esq == NULL) {
      no* temp = r->dir;
      free(r);
      return temp;
    } else if (r->dir == NULL) {
      no* temp = r->esq;
      free(r);
      return temp;
    }

    no* antecessor = encontrar_antecessor(r);
    r->chave = antecessor->chave;
    r->esq = remover(r->esq, antecessor->chave);
  }

  return r;
}


