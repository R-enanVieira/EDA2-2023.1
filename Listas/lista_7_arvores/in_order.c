#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no {
  int dado;
  struct no *esq, *dir;
} no;

typedef struct stack {
  no *t;
  struct stack *next;
} sNode;

void push(sNode** sHead, no* t) {
  sNode *newNode = malloc(sizeof(sNode));

  newNode->t = t;
  newNode->next = *sHead;
  (*sHead) = newNode;
}

no *pop(sNode** sHead) {
  no *res;
  sNode *top;

  top = *sHead;
  res = top->t;
  *sHead = top->next;
  free(top);
  return res;
}

bool isEmpty(sNode *top) {
  return (top == NULL ? true : false);
}

void em_ordem (no *raiz) {
  no *current = raiz;
  sNode *s = NULL;

  bool ok = false;

  while(!ok) {
    if(current != NULL) {
      push(&s, current);
      current = current->esq;
    }else {
      if(!isEmpty(s)) {
        current = pop(&s);
        printf("%d ", current->dado);

        current = current->dir;
      } else {
        ok = true;
      }
    }
  }
}
