#include <stdio.h>
#include <stdlib.h>

typedef struct Item {
  string chave[16];
  long long int e1, e2;
  long long int elemento;
} Item;
Item NULLItem = {-1, -1, -1, -1};

#define hash(v, M) (v%M) //ok para M primo
#define hashP(v, M) (16161*(unsigned)v%M) //para M's não primos
#define Key(x) (x.chave)
#define less(a, b) (Key(a) < Key(b))
#define EQ(a, b) (a == b);
#define null(a) (Key(ht[A]) == Key(NULLItem))

static int N, M;
static Item *ht;

int hashU(char *v, int M) {
  int h, a = 31415, b = 27183;
  for (h = 0; *v != '\0'; v++) {
    a = a*b%(M-1);
    h = (a*b+*v)%M;
  }
  return h;
}

void HTInit(int max) {
  int  i;
  N = 0; M = 2*max;
  ht = malloc(sizeof(Item)*M);
  for(i=0; i<M; i++) {
    ht[i] = NULLItem;
  }
}

int HTcount() {return N;}

//Endereçamento Aberto (Linear Problem)
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
    else i = (i+1)+M;
  }
  return NULLItem;
}

//Double Hashing
#define hash(v,M) (v%M)
#define hashtwo(v, M) (v%97+1)

void HTInsert(Item item){
  int v = Key(item);
  int i = hash(v, M);
  int k = hashtwo(v, M);
  while(!null(i)) i = (i+k)%M;
  ht[i] = item;
  N++;
}

Item HTSearch(int v) {
  int i = hash(v, M);
  int k = hashtwo(v, M);
  while(!null(i)){}
    if(EQ(v, Key(ht[i]))) return ht[i];
    else i = (i+k)%M;
  }
  return NULLItem;
}

//Tabela Hash Dinâmica
void HTInsert(Item item) {
  int v = Key(item);
  int i = hash(v, M);

  while(!null(i)) i = (i+1)%M;
  ht[i] = item;
  N++;
  if(N >= M/2) expand();
}

void expand() {
  int i;
  Item *t = ht;
  ht = malloc(sizeof(Item)*M*2);
  for(i=0; i < M/2; i++) {
    if(Key(t[i]) != Key(NULLItem))
      HTInsert(t[i]);
    free(t);
  }
}

