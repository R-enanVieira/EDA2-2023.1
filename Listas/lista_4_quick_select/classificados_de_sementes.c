#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
  int c;
  int q;
} Item;

#define less(A,B) ((A.q) < (B.q))
#define exch(A, B) { Item tmp = A; A = B; B = tmp; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define MAX 1000000010

int partition(Item *v, int begin, int end) {
  int i = begin - 1;
  int j = end;

  for(;;) {
    while(less(v[++i], v[end]) || (v[i].q == v[end].q && v[i].c < v [end].c)) {}
    
    while(less(v[end], v[--j]) || (v[end].q == v[j].q && v[end].c < v [j].c)) {
      if(j == begin) {
        break;
      }
    }

    if(i >= j) {
      break;
    }
    
    exch(v[i], v[j]);
  }

  exch(v[i], v[end]);
  return i;
}

void quickSelect(Item *v, int l, int r, int k) {
  int i;

  if(r<=l) return;

  cmpexch(v[(l+r)/2], v[r]);
  cmpexch(v[l], v[r]);
  cmpexch(v[(l+r)/2], v[l]);
  
  i = partition(v, l, r);
  if(i > k) quickSelect(v, l, i-1, k);
  if(i < k) quickSelect(v, i+1, r, k);
}


static void merge(Item *v, int l, int m, int r) {
	Item *aux;
	aux = malloc((r-l) * sizeof(Item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].c < v[j].c) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(Item *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int main() {
  int k, i = 0; scanf("%d", &k);
  
  Item *v;
  v = malloc(sizeof(Item)*MAX);

  while(scanf("%d %d", &v[i].c, &v[i].q) != EOF) i++;
  
  quickSelect(v, 0, i-1, k-1);
  
  merge_sort(v, 0, k);

  for(int j = 0; j < k; j++) {
    printf("%d %d\n", v[j].c, v[j].q);
  }
}

