#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000010
#define ColLimit 50
#define less(A, B) (A.value < B.value)
#define exch(A, B) { item t=A; A=B; B=t; }

typedef struct item {
  char name[11];
  int value;
  int positionPQ;
} item;

item PQ[MAX];
int leaf = 1;
item HT[MAX];

int hashU(char *v, int M) {
  int h, a = 31415, b = 27183;
  for (h = 0; *v != '\0'; v++) {
    a = a*b%(M-1);
    h = (a*b+*v)%M;
  }
  return h;
}

void fixup(int v, int h) {
  for(int i = 0; i <= ColLimit && !strcmp(HT[h+i].name, PQ[v].name); i++) 
    if(!HT[h+i].positionPQ) HT[h+i].positionPQ = v;

  while(v>1 && less(PQ[v], PQ[v/2])) {
    exch(PQ[v], PQ[v/2]);

    int h2 = hashU(PQ[v].name, MAX); 

    for(int i = 0; i <= ColLimit; i++) 
      if(HT[h+i].positionPQ && !strcmp(HT[h+i].name, PQ[v/2].name)) HT[h+i].positionPQ = v/2;
    
    for(int i = 0; i <= ColLimit; i++) 
      if(HT[h2+i].positionPQ && !strcmp(HT[h2+i].name, PQ[v].name)) HT[h2+i].positionPQ = v;

    v = v/2;
  } 
}

void fixdown(int v, int p, int h) {
  int j;

  for(int i = 0; i <= ColLimit && !strcmp(HT[h+i].name, PQ[v].name); i++) 
    if(!HT[h+i].positionPQ) HT[h+i].positionPQ = v;

  while(v*2 <= 100) {
    j = v*2; 

    if(j<=p && j+1<=p && less(PQ[j+1], PQ[j])) j++;
    
    if(less(PQ[v], PQ[j])) break;
    
    exch(PQ[v], PQ[j]);
    
    int h2 = hashU(PQ[v].name, MAX);

    for(int i = 0; i <= ColLimit; i++) 
      if(HT[h+i].positionPQ && !strcmp(HT[h+i].name, PQ[j].name)) HT[h+i].positionPQ = j;
    
    for(int i = 0; i <= ColLimit; i++) 
      if(HT[h2+i].positionPQ && !strcmp(HT[h2+i].name, PQ[v].name)) HT[h2+i].positionPQ = v;

    v = j;
  }
}

void PQinsert(item s) {
  PQ[leaf] = s;
  int hash = hashU(s.name, MAX);

  for (int i = 0; i <= ColLimit; i++) {
    if(!HT[hash+i].positionPQ){
      strcpy(HT[hash+i].name, s.name);
      HT[hash+i].value = s.value;
      HT[hash+i].positionPQ = leaf;
      break;
    }
  }

  fixup(leaf, hash);
  leaf++;
}

void PQchange(item s) {
  int hash = hashU(s.name, MAX);

  for (int i = 0; i <= ColLimit; i++) {
    if(HT[hash+i].positionPQ && !strcmp(HT[hash+i].name, s.name)){
      PQ[HT[hash+i].positionPQ].value = s.value;

      fixup(HT[hash+i].positionPQ, hash+i);
      fixdown(HT[hash+i].positionPQ, leaf, hash+i);

    }
  }
}

item PQdelMax() {
  exch(PQ[1], PQ[leaf-1]);
  int hash = hashU(PQ[1].name, MAX);
  for (int i = 0; i <= ColLimit; i++) {
    if(HT[hash+i].positionPQ && !strcmp(HT[hash+i].name, PQ[leaf-1].name)) {
      HT[hash+i].positionPQ = 0;
      strcpy(HT[hash+i].name, "vaziovazio");
    }
  }
  fixdown(1, leaf-2, hash);
  leaf--;
  return PQ[leaf];
}

int main() { 
  int n, cont = 0; scanf("%d", &n);
  for (int i = 0; i < MAX; i++) {
    HT[i].positionPQ = 0;
    strcpy(HT[i].name, "vaziovazio");
  } 
  
  while(n--) {
    int instr; scanf("%d", &instr);
    cont++;

    if(instr != 3) {
      item stock;
      scanf("%s", stock.name);
      scanf("%d", &stock.value);


      if(instr == 1)
        PQinsert(stock);
      else  
        PQchange(stock);

    } else {
      printf("%s %d\n", PQdelMax().name, cont);
    } 
  }
}
