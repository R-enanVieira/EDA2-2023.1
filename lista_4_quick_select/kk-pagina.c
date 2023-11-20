#include <stdio.h>
#include <stdlib.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define exch(A, B) { Item tmp = A; A = B; B = tmp; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define MAX 1000000010

int partition(Item *v, int begin, int end) {
  int i = begin - 1;
  int j = end;

  for(;;) {
    while(less(v[++i], v[end])) {}
    
    while(less(v[end], v[--j])) {
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
		if(v[i] < v[j]) aux[k++] = v[i++];
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
  int n, p, x; scanf("%d %d %d", &n, &p, &x);
  
  Item *produtos;
  produtos = malloc(sizeof(Item)*n);

  for (int i = 0; i < n; i++) 
    scanf("%d", &produtos[i]);

  if((x*p)+x-1 < n) {
    int y = (x*p)+x-1;
    quickSelect(produtos, 0, n-1, y);
    quickSelect(produtos, 0, y-1, (x*p));
    merge_sort(produtos, (x*p), y);
  } else {
    int y = ((x*p)+x-1) - n - 1;
    quickSelect(produtos, 0, n-1, y); 
    quickSelect(produtos, 0, y-1, (x*p));
    merge_sort(produtos, (x*p), y);
  }

  for (int i = x*p, j = 0; i < n && j < x ; i++, j++) {
    printf("%d\n", produtos[i]);    
  }

}
