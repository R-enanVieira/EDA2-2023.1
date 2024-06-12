#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1048709
#define Key(v, M) (v % M)

typedef struct words {
  char s[11];
  struct words *left, *right;
} dict;

typedef struct no {
  long long int value;
  dict *root;
  struct no *prox;
} node;

node *h;

dict *createNode(char *value) {
  dict *newNode = (dict *)malloc(sizeof(dict));
  if (newNode == NULL) return NULL;

  strcpy(newNode->s, value);
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

bool findWord(dict **root, char *value) {
  if (*root == NULL) {
    *root = createNode(value);
    return false;  // Indica que a palavra foi inserida (não era duplicada)
  }

  if (!strcmp((*root)->s, value)) return true;

  if (strcmp(value, (*root)->s) < 0)
    return findWord(&(*root)->left, value);
  else
    return findWord(&(*root)->right, value);
}

void hashInit() {
  h = malloc(M * sizeof(node));
  for (int i = 0; i < M; i++) h[i].prox = NULL, h[i].root = NULL;
}

bool hashInsert(node *h, long long int k, long long int v, char *s) {
  node *currentNo = &h[k];

  while (currentNo->prox != NULL) {
    currentNo = currentNo->prox;
    if (currentNo->value == v) {
      if (findWord(&currentNo->root, s))
        return false;
      else
        return true;
    }

    if (currentNo->prox == NULL) break;
  }

  node *no = malloc(sizeof(node));
  dict *word = createNode(s);

  no->value = v;
  no->prox = NULL;
  no->root = word;

  currentNo->prox = no;

  return true;
}

int main() {
  long long int c;
  char s[11];

  hashInit();

  while (scanf("%lld %s", &c, s) != EOF) {
    if (!hashInsert(h, Key(c, M), c, s)) printf("%lld\n", c);
  }

  return 0;
}
