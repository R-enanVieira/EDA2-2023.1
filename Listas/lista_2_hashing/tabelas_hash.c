#include <stdio.h>
#include <stdlib.h>

typedef struct no {
  int value;
  struct no *prox;
} node;

int hash(int k, int m) { return k % m; }

void hashInsert(node *hash, int k, int v) {
  node *no = malloc(sizeof(node));
  node *currentNo = malloc(sizeof(node));
  currentNo = &hash[k];
  while (currentNo->prox != NULL) {
    currentNo = currentNo->prox;
  }
  no->value = v;
  no->prox = currentNo->prox;
  currentNo->prox = no;
}

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int m, c;
    scanf("%d %d", &m, &c);

    node h[m];
    for (int i = 0; i < m; i++) h[i].prox = NULL;

    while (c--) {
      int key;
      scanf("%d", &key);
      hashInsert(h, hash(key, m), key);
    }

    for (int i = 0; i < m; i++) {
      node *current = h[i].prox;
      printf("%d ->", i);
      while (current != NULL)
        printf(" %d ->", current->value), current = current->prox;
      printf(" \\\n");
    }
  }
}
