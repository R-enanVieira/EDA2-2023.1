#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
typedef struct rank {
  int f;
  char c;
  int pos;
} rank;

static void merge(rank *v, int l, int m, int r) {
	rank *aux;
	aux = malloc((r-l) * sizeof(rank));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].f < v[j].f) aux[k++] = v[i++];
    else if(v[i].f == v[j].f && v[i].pos > v[j].pos) aux[k++] = v[i++]; 
    else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(rank *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int main() {
  char s[MAX+1];
  scanf("%s", s);
  
  rank dados[strlen(s)];
  int k=0, cont=1;
  for (int i = 1; s[i] != '\0'; i++) {
    if(s[i-1] == s[i]) {
      cont++;
    }else {
      dados[k].f = cont;
      dados[k].c = s[i-1];
      dados[k].pos = i-cont;

      cont = 1;
      k++;
    }
  }
  dados[k].f = cont;
  dados[k].c = s[strlen(s)-1];
  dados[k].pos = strlen(s)-cont;

  cont = 1;
  k++;
  merge_sort(dados, 0, k);

  for(int i = k-1; i >= 0; i--) {
    printf("%d %c %d\n", dados[i].f, dados[i].c, dados[i].pos);
  }
}
