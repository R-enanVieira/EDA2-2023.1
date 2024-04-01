#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int n;
  char s[16];
} item;

int binary_search(item *v, int l, int r, int key) {
  if (l > r) return -1;
  int m = (l + r) / 2;
  if (key == v[m].n) return m;
  if (key > v[m].n) return binary_search(v, m + 1, r, key);
  return binary_search(v, l, m - 1, key);
}

static void merge(item *v, int l, int m, int r) {
  item *aux;
  aux = malloc((r - l) * sizeof(item));
  int i = l, j = m;
  int k = 0;

  while (i < m && j < r) {
    if (v[i].n <= v[j].n)
      aux[k++] = v[i++];
    else
      aux[k++] = v[j++];
  }
  while (i < m) aux[k++] = v[i++];
  while (j < r) aux[k++] = v[j++];

  for (i = l; i < r; ++i) v[i] = aux[i - l];
  free(aux);
}

void merge_sort(item *v, int l, int r) {
  if (l < r - 1) {
    int middle = (l + r) / 2;
    merge_sort(v, l, middle);
    merge_sort(v, middle, r);
    merge(v, l, middle, r);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  item *v = malloc(n * sizeof(item));

  for (int i = 0; i < n; i++) {
    scanf(" %d %s", &v[i].n, v[i].s);
  }

  merge_sort(v, 0, n);

  int query;
  while (scanf("%d", &query) != EOF) {
    int ans = binary_search(v, 0, n, query);
    (ans == -1 ? printf("undefined\n") : printf("%s\n", v[ans].s));
  }

  return 0;
}
