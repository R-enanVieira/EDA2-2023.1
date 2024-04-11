#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double v;
  int i;
  int j;
} item;

static void merge(item *v, int l, int m, int r) {
  item *aux;
  aux = malloc((r - l) * sizeof(item));
  int i = l, j = m;
  int k = 0;

  while (i < m && j < r) {
    if (v[i].v > v[j].v)
      aux[k++] = v[i++];
    else if (v[i].v == v[j].v && v[i].i < v[j].i)
      aux[k++] = v[i++];
    else if (v[i].v == v[j].v && v[i].i == v[j].i && v[i].j < v[j].j)
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
  int t;
  scanf("%d", &t);

  while (t--) {
    int m, n, cont = 0;
    scanf("%d %d", &m, &n);

    item vect[n * m];

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        scanf("%lf", &vect[cont].v), vect[cont].i = i, vect[cont].j = j, cont++;

    merge_sort(vect, 0, n * m);

    for (int i = 0; i < n * m; i++)
      (i < ((n * m) - 1) ? printf("%d,%d ", vect[i].i + 1, vect[i].j + 1)
                         : printf("%d,%d\n", vect[i].i + 1, vect[i].j + 1));
  }
}
