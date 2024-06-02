#include <stdlib.h>
#include <stdio.h>

typedef struct no {
   int dado;
   struct no *esq, *dir;
} no;

typedef struct celula {
   no *conteudo; 
   struct celula *prox;
} celula;

celula *criapilha (void) {
   celula *pi;
   pi = malloc (sizeof (celula)); // cabeça
   pi->prox = NULL;
   return pi;
}

void empilha (celula *pi, no *r) { 
   celula *nova;
   nova = malloc (sizeof (celula));
   nova->conteudo = r;
   nova->prox  = pi->prox;
   pi->prox = nova; 
}

no *desempilha (celula *pi) {
  celula *p;
  p = pi->prox;
  no *r = p->conteudo;
  pi->prox = p->prox;
  free (p);
  return r; 
}

int pilhavazia(celula *pi) {
   return (pi->prox == NULL);
}

void pre_ordem(no *raiz) {
  celula *pilha = criapilha();
  empilha(pilha, raiz);
  while(!pilhavazia(pilha)) {
    no *x = desempilha(pilha);
    if(!x) continue;
    printf("%d ", x->dado);
    if(x->dir != NULL)
      empilha(pilha, x->dir);
    if(x->esq != NULL)
      empilha(pilha, x->esq); 
  }
}
