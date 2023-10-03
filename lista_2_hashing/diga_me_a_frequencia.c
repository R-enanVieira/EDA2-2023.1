#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
  char c;
  int cont;
} item;


static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].cont < v[j].cont) aux[k++] = v[i++];
		else if(v[i].cont == v[j].cont && v[i].c < v[j].c) aux[k++] = v[i++];
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
  char s[1001];

  while(scanf("%s", s) != EOF) {
    item ht[128];
    memset(ht, 0, sizeof(item)*128);
    for (int i = 0; s[i] != '\0'; i++) {
      ht[s[i]].c = s[i];
      ht[s[i]].cont++;
    }
    merge_sort(ht, 0, 128);

    for(int i = 0; i < 128; i++) {
      if(ht[i].cont) {
        printf("%d %d\n", ht[i].c, ht[i].cont);
      }
    }
    printf("\n");

  }

  return 0;
}
