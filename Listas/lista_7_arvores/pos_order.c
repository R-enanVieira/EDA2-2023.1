#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;

typedef struct sNode {
  int tam, topo;
  no** stack;
} sNode;

sNode *createStack(int size) {
  sNode *s = malloc(sizeof(sNode));
  s->tam = size;
  s->topo = -1;
  s->stack = (struct no**)malloc(s->tam *sizeof(no));
  return s;
}

bool isFull(sNode *s) {
  return s->topo - 1 == s->tam;
}

bool isEmpty(sNode *s) {
  return s->topo == -1;
}

void push(sNode *s, no *node) {
  if(isFull(s)) return;

  s->stack[++s->topo] = node;
} 

no *pop(sNode *s) {
  if(isEmpty(s)) return NULL;
  return s->stack[s->topo--];
}

void pos_ordem (no *raiz) {
  if(raiz == NULL) return;

  sNode *s1 = createStack(100);
  sNode *s2 = createStack(100); 
  
  push(s1, raiz);
  no *node;

  while(!isEmpty(s1)) {
    node = pop(s1);
    push(s2, node);

    if(node->esq) push(s1, node->esq);
    if(node->dir) push(s1, node->dir);
  }

  while(!isEmpty(s2)) {
    node = pop(s2);
    printf("%d ", node->dado);
  }
}
