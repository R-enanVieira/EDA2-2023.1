#include <stdio.h>

int placas[100000001];

#define PRIOR(A) (placas[A])
#define less(A, B) (A < B)
#define exch(A, B) \
  {                \
    int t = A;     \
    A = B;         \
    B = t;         \
  }
#define MAX 101

int PQ[MAX], PQimprime[MAX];
int leaf = 1;
int N = 0;

void fixup(int v) {
  while (v > 1 && less(PRIOR(PQ[v]), PRIOR(PQ[v / 2]))) {
    exch(PQ[v], PQ[v / 2]);

    v = v / 2;
  }
}

void fixdown(int v) {
  int j;

  while (v * 2 <= 100) {
    j = v * 2;
    if (j <= 100 && j + 1 <= 100 && less(PRIOR(PQ[j + 1]), PRIOR(PQ[j]))) j++;

    if (less(PRIOR(PQ[v]), PRIOR(PQ[j]))) break;

    exch(PQ[v], PQ[j]);

    v = j;
  }
}

void fixdown2(int v, int p) {
  int j;

  while (v * 2 <= p) {
    j = v * 2;
    if (j <= p && j + 1 <= p &&
        less(PRIOR(PQimprime[j + 1]), PRIOR(PQimprime[j])))
      j++;

    if (less(PRIOR(PQimprime[v]), PRIOR(PQimprime[j]))) break;

    exch(PQimprime[v], PQimprime[j]);

    v = j;
  }
}

void PQinsert(int y) {
  PQ[leaf] = y;
  fixup(leaf);
  leaf++;
}

void PQreplace(int id_maior, int id_new) {
  PQ[id_maior] = id_new;

  fixup(id_maior);

  fixdown(id_maior);
}

int PQdelmax() {
  exch(PQimprime[1], PQimprime[N]);

  fixdown2(1, N - 1);

  return PQimprime[N];
}

int main() {
  int o, p, i = 0, maior;

  while (scanf("%d %d", &o, &p) != EOF) {
    maior = 1;

    if (o == 1 && i < 100) {
      placas[i] = p;

      PQinsert(i);

      i++;
    } else if (o == 1) {
      placas[i] = p;
      for (int j = 2; j <= 100; j++) {
        if (placas[PQ[j]] > placas[PQ[maior]]) maior = j;
      }

      if (placas[PQ[maior]] > p) PQreplace(maior, i);

      i++;
    } else {
      N = leaf - 1;

      if (p == 1) {
        printf("%d\n", placas[PQ[1]]);
        continue;
      }

      for (int j = 1; j <= N; j++) {
        PQimprime[j] = PQ[j];
      }

      for (int j = 1; j < p; j++) {
        printf("%d ", placas[PQdelmax()]);
        N--;
      }

      printf("%d\n", placas[PQdelmax()]);
    }
  }
}
