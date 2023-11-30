#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 1048577

typedef struct item {
  int s;
  char c;
} item;

static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].s > v[j].s) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(item *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int hash(int s) {
  return s%M;
}

int main() {
  int s, quant=0; char c;
  
  //item ht[M];
  item *ht = malloc(sizeof(item)*M);
  
  for(int i = 0; i < M; i++) {
    ht[i].s = -1;
  }
  
  while(scanf("%d %c", &s, &c) != EOF) {
    int h = hash(s), flag = 1, in = -1;
    for(int i = 0; i < 20 && h+i < M; i++) {
      if(ht[h+i].s != -1 && ht[h+i].s == s){
        flag = 0;
        break;
      } else if(ht[h+i].s == -1 && in == -1) {
        in = h+i;
      }
    }
    if(flag) {
      quant++;
      ht[in].s = s; ht[in].c = c;
    }
  }

  merge_sort(ht, 0 , M);
  
  printf("%d\n",quant); 
  while(quant--) printf("%c",ht[quant].c);
  printf("\n");

  return 0;
}
