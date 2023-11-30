#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  int nota;
  int quant;
} item;

int max(int y, item z) {
  return (y > z.nota ? y : z.nota);
}

static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].quant > v[j].quant) aux[k++] = v[i++];
		if(v[i].quant == v[j].quant && v[i].nota > v[j].nota) aux[k++] = v[i++];
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

int main() {
  int n, ans = 0; 
  while(scanf("%d", &n) != EOF) {
    item ht[1001];
    memset(ht, 0, sizeof(item)*1001);
    while(n--){
      int x; scanf("%d", &x);
      ht[x].nota = x;
      ht[x].quant++;
    }
    merge_sort(ht, 0, 1001);
    ans = max(ans, ht[0]);
  }
  printf("%d\n", ans);
}
