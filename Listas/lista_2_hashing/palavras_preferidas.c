#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct item {
  char word[17];
  int q;
  struct item *prox;
} Item;

int M; 
Item *ht;

int hashU(char *s) {
  int h = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    h += s[i] * i;
  }
  return h%M;
}

void hashInit(int max) {
  int  i;
  M = max;
  ht = malloc(sizeof(Item)*M);
  for(i=0; i<M; i++) {
    ht[i].prox = NULL;
    ht[i].q = 0;
  }
}

bool stringComp(char *v, char *w) {
  for(int i = 0, j = 0; v[i] != '\0' || w[j] != '\0'; i++, j++) 
    if(v[i] != w[j]) 
      return false;
  
  return true;
}

void solve(int c, char *p) {
  int i = hashU(p);
  Item *newNode = malloc(sizeof(Item)); 
  
  //Colocando palavra na tabela sem colisão.
  if(ht[i].prox == NULL) {
    strcpy(newNode->word, p);
    newNode->q = 0;
    if(c == 1) newNode->q++;
    else if(c == 2) printf("%d\n", newNode->q);
    newNode->prox = ht[i].prox;
    ht[i].prox = newNode;
    return;
  }

  Item *currentNode = malloc(sizeof(Item));
  currentNode = ht[i].prox;

  while(1) {
    if(stringComp(currentNode->word, p)) {
      if(c == 1) currentNode->q++; 
      else if(c == 2) printf("%d\n", currentNode->q);
      else currentNode->q = 0;

      return;
    }
    if(currentNode->prox == NULL) break;
    currentNode = currentNode->prox;
  }

  strcpy(newNode->word, p);
  newNode->q = 0;
  if(c == 1) newNode->q++;
  else if(c == 2) printf("%d\n", newNode->q);
  newNode->prox = currentNode->prox;
  currentNode->prox = newNode;
}

int main() {
  int c; char s[17];
 
  hashInit(65537);
  
  while(scanf("%d %s", &c, s) != EOF) {
    solve(c, s);
  }
}
