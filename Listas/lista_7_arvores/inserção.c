#include <stdlib.h>

typedef struct no {
  int chave;
  struct no *esq, *dir;
} no;

no *inserir(no *r, int x) {
  if(!r) {
    no *new = malloc(sizeof(no));
    new->chave = x;
    new->dir = NULL;
    new->esq = NULL;
    
    return new;
  }

  if(r->chave == x) return r;
  if(r->chave > x) 
    r->esq = inserir(r->esq, x);
  else 
    r->dir = inserir(r->dir, x);

  return r;
}
