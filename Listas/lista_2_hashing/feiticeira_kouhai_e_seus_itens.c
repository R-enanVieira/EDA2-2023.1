#include <stdio.h>
#include <stdlib.h>

#define M 262147
#define Q 536870912
#define Key(A) \
  { A % M }

typedef struct no {
  int quantity;
  struct no *prox;
} node;

void hashInit(node *h) { h = malloc(M * sizeof(node)); }

int main() {
  int n;
  scanf("%d", &n);

  node *h;
  hashInit(h);
}
