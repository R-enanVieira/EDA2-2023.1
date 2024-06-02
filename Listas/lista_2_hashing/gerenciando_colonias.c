#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1048709
#define Key(v, M) (v % M)

typedef struct words{
  char s[11];
  struct words *prox; 
} dict;

typedef struct no {
  int value;
  dict *next;
  struct no *prox;
} node;

node *h;

int stringHash(char *s) {
  int h = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    h += s[i] * i;
  }
  return h%M;
}

bool stringComp(char *v, char *w) {
  for(int i = 0, j = 0; v[i] != '\0' || w[j] != '\0'; i++, j++) 
    if(v[i] != w[j]) 
      return false;
  
  return true;
}

void hashInit() {
  h = malloc(M * sizeof(node));
  for (int i = 0; i < M; i++) h[i].prox = NULL, h[i].next = NULL;
}

bool findWord(dict *d, char *s) {
  dict *currentWord = d;

  while(currentWord != NULL) {
    if(stringComp(currentWord->s, s)) return true;
    if(currentWord->prox == NULL) break;
    currentWord = currentWord->prox;
  }
  
  dict *newWord = malloc(sizeof(dict));
  strcpy(newWord->s, s);
  newWord->prox = NULL;

  if(currentWord != NULL) currentWord->prox = newWord;
  return false;
}

bool hashInsert(node *h, int k, int v, char *s) {
  node *currentNo = &h[k];

  while (currentNo->prox != NULL) {
    currentNo = currentNo->prox;
    if (currentNo->value == v) {
      if(findWord(currentNo->next, s)) return false;
      else return true;
    }

    if (currentNo->prox == NULL) break;
  }

  node *no = malloc(sizeof(node));
  dict *word = malloc(sizeof(dict));
  strcpy(word->s, s);
  word->prox = NULL;
  
  no->value = v;
  no->prox = NULL;
  no->next = word;
  
  currentNo->prox = no;

  return true;
}

int main() {
  int c;
  char s[11];

  hashInit();

  while (scanf("%d %s", &c, s) != EOF) {
    if (!hashInsert(h, Key(c, M), c, s)) printf("%d\n", c);
  }

  return 0;
}
