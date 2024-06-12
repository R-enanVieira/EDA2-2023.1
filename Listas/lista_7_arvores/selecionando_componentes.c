#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define PRIOR(A) (notas[A])
#define less(A, B) (A < B)
#define great(A, B) (A > B)
#define exch(A, B) \
  {                \
    int t = A;     \
    A = B;         \
    B = t;         \
  }
#define MAX 1000001

int PQmin[MAX];
int PQmax[MAX];
int leaf_min = 1;
int leaf_max = 1;

void fixup(int v, bool heapType) {
  if (heapType) {
    while (v > 1 && less(PQmin[v], PQmin[v / 2])) {
      exch(PQmin[v], PQmin[v / 2]);
      v = v / 2;
    }
  } else {
    while (v > 1 && great(PQmax[v], PQmax[v / 2])) {
      exch(PQmax[v], PQmax[v / 2]);
      v = v / 2;
    }
  }
}

void fixdown(int v, int p, bool heapType) {
  int j;

  if (heapType) {
    while (v * 2 <= p) {
      j = v * 2;
      if (j <= p && j + 1 <= p && less(PQmin[j + 1], PQmin[j])) j++;

      if (less(PQmin[v], PQmin[j])) break;

      exch(PQmin[v], PQmin[j]);

      v = j;
    }
  } else {
    while (v * 2 <= p) {
      j = v * 2;
      if (j <= p && j + 1 <= p && great(PQmax[j + 1], PQmax[j])) j++;

      if (great(PQmax[v], PQmax[j])) break;

      exch(PQmax[v], PQmax[j]);

      v = j;
    }
  }
}

void PQinsert(int y, bool heapType) {
  if (heapType) {
    PQmin[leaf_min] = y;
    fixup(leaf_min, heapType);
    leaf_min++;
  } else {
    PQmax[leaf_max] = y;
    fixup(leaf_max, heapType);
    leaf_max++;
  }
}

int PQpop(bool heapType) {
  if (heapType) {
    exch(PQmin[1], PQmin[leaf_min - 1]);
    leaf_min--;
    fixdown(1, leaf_min - 1, heapType);
    return PQmin[leaf_min];
  }
  exch(PQmax[1], PQmax[leaf_max - 1]);
  leaf_max--;
  fixdown(1, leaf_max - 1, heapType);
  return PQmax[leaf_max];
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);

  bool min = true;
  bool max = false;

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    PQinsert(x, min);
  }

  int j = 0;
  long long int ans[1000001];
  PQinsert(PQpop(min), max);  // adiciono o menor elemento do tuboA no tuboB

  while (leaf_min > 1) {
    long long int diff = abs(PQmin[1] - PQmax[1]);
    if (diff <= x && diff > 0) {
      ans[j++] = PQmin[1] + PQmax[1];  // faço a junção do elemento no tuboA com
                                       // o elemento no tuboB
      PQpop(min);  // retiro o elemento do tuboA
      PQpop(max);  // retiro o elemento do tuboB
    }
    if (leaf_max > 1) {
      diff = abs(PQmin[1] - PQmax[1]);
      if (diff && diff <= x) continue;
    }
    PQinsert(PQpop(min), max);  // adiciono o menor elemento do tuboA no tuboB
  }

  printf("%d\n", j);
  for (int i = 0; i < j; i++)
    (i == j - 1 ? printf("%lld\n", ans[i]) : printf("%lld ", ans[i]));

  return 0;
}
