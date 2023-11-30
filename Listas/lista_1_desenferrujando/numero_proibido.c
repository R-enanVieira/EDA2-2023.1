#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  int chave;
} Item;
Item NULLItem = {-1};

#define HASHSIZE 140000
#define hash(v, M) (v%M) //ok para M primo
#define Key(x) (x.chave)
#define less(a, b) (Key(a) < Key(b))
#define EQ(a, b) (a == b)
#define null(a) (Key(ht[a]) == Key(NULLItem))

static int N, M;
static Item *ht;

void HTInit(int max) {
  int  i;
  N = 0; M = 2*max;
  ht = malloc(sizeof(Item)*M);
  for(i=0; i<M; i++) {
    ht[i] = NULLItem;
  }
}

void HTInsert(Item item) {
  int v = Key(item);
  int i = hash(v, M);

  while(!null(i)) i = (i+1)%M;
  ht[i] = item;
  N++;
}

Item HTSearch(int v) {
  int i = hash(v, M);
  while(!null(i)) {
    if(EQ(v, Key(ht[i]))) return ht[i];
    else i = (i+1)%M;
  }
  return NULLItem;
}

int main() {
  int n; scanf("%d", &n);
  HTInit(HASHSIZE);
  for (int i = 0; i < n; i++) {
    Item input; scanf("%d", &input.chave);
    HTInsert(input);
  }
  
  int q;
  while (scanf("%d", &q) != EOF) {
    Item key = HTSearch(q);
    if(Key(key) == -1) printf("nao\n");
    else printf("sim\n");
  }

  return 0;
}
