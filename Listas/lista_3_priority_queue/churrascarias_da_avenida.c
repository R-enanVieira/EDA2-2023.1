#include <stdio.h>

int notas[100001];
const int vm = 2000000000;

#define PRIOR(A) (notas[A])
#define less(A, B) (A < B)
#define exch(A, B) \
  {                \
    int t = A;     \
    A = B;         \
    B = t;         \
  }
#define MAX 100001

int PQ[MAX];
int leaf = 1;
int posicoesPQ[MAX];

void fixup(int v) {
  posicoesPQ[PQ[v]] = v;
  while (v > 1 && less(PRIOR(PQ[v]), PRIOR(PQ[v / 2]))) {
    exch(PQ[v], PQ[v / 2]);

    posicoesPQ[PQ[v / 2]] = v / 2;
    posicoesPQ[PQ[v]] = v;

    v = v / 2;
  }
}

void fixdown(int v, int p) {
  int j;
  posicoesPQ[PQ[v]] = v;

  while (v * 2 <= p) {
    j = v * 2;
    if (j <= p && j + 1 <= p && less(PRIOR(PQ[j + 1]), PRIOR(PQ[j]))) j++;

    if (less(PRIOR(PQ[v]), PRIOR(PQ[j]))) break;

    exch(PQ[v], PQ[j]);
    posicoesPQ[PQ[v]] = v;

    v = j;

    posicoesPQ[PQ[j]] = j;
  }
}

void PQinsert(int y) {
  PQ[leaf] = y;
  fixup(leaf);
  leaf++;
}

void PQreplace(int id_old, int id_new, int profundidade) {
  PQ[posicoesPQ[id_old]] = id_new;
  fixup(posicoesPQ[id_old]);
  fixdown(posicoesPQ[id_old], profundidade);
  posicoesPQ[id_old] = 0;
}

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k), n && k) {
    leaf = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d", &notas[i]);
      if (i < k) PQinsert(i);
    }

    int oldest = 0;
    int prox = k;

    while (prox < n) {
      printf("%d ", notas[PQ[1]]);
      PQreplace(oldest, prox, k);
      oldest++;
      prox++;
    }

    printf("%d\n", notas[PQ[1]]);
  }
}
