#include <stdio.h>
#include <stdlib.h>

#define lesseq(A, B) ((A) <= (B))
#define less(A, B) ((A) < (B))
#define exch(A, B) \
  {                \
    int t;         \
    t = A;         \
    A = B;         \
    B = t;         \
  }
#define cmpexch(A, B)           \
  {                             \
    if (less(B, A)) exch(A, B); \
  }

int partition(int *v, int l, int r) {
  int p = v[r];
  int i = l - 1;
  int j = r;
  while (1) {
    while (less(v[++i], p));
    while (less(p, v[--j]))
      if (j == l) break;

    if (i >= j) break;
    exch(v[i], v[j]);
  }
  exch(v[i], v[r]);
  return i;
}

void quick_sort(int *v, int l, int r) {
  if (r <= l) return;
  cmpexch(v[(l + r) / 2], v[r]);
  cmpexch(v[l], v[(l + r) / 2]);
  cmpexch(v[r], v[(l + r) / 2]);
  int pivo = partition(v, l, r);
  quick_sort(v, l, pivo - 1);
  quick_sort(v, pivo + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);
  int *vect;
  vect = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &vect[i]);
  }
  quick_sort(vect, 0, n - 1);
  for (int i = 0; i < n; i++) {
    if (i == n - 1)
      printf("%d\n", vect[i]);
    else
      printf("%d ", vect[i]);
  }

  return 0;
}
