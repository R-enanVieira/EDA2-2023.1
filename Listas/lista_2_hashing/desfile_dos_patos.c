#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 1000001;

typedef struct item {
  int num;
  int cont;
} item;

static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].cont >= v[j].cont) aux[k++] = v[i++];
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
  int n; 

  while(scanf("%d", &n) == 1, n != 0) {
    item ht[MAX];
    memset(ht, 0, sizeof(item)*MAX);
    for(int i = 0; i < n; i++) {
      int x; scanf("%d", &x);
      ht[x].cont++;
      ht[x].num = x;
    }

    merge_sort(ht, 0, MAX);

    printf("%d\n", ht[0].num);
  }

  return 0;
}
