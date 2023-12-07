#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int *parent;
  int *size;
} UFDS;

UFDS *UFDS_new(int n) {
  UFDS *ufds = malloc(sizeof(UFDS));
  ufds->parent = malloc(sizeof(int) * n);
  ufds->size = malloc(sizeof(int) * n);

  for (int i = 0; i < n; i++) {
    ufds->parent[i] = i;
    ufds->size[i] = 1;
  }
  return ufds;
}

int UFDS_Component(UFDS *ufds, int a) {
  return (ufds->parent[a] == a
              ? a
              : (ufds->parent[a] = UFDS_Component(ufds, ufds->parent[a])));

  /*if(ufds->parent[a] == a) {
    return a;
  }

  int pai = UFDS_Component(ufds, ufds->parent[a]);
  ufsd->parent[a] = pai;
  return pai;
  */
}

int UFDS_SameSet(UFDS *ufds, int a, int b) {
  return UFDS_Component(ufds, a) == UFDS_Component(ufds, b);
}

int UFDS_JoinSets(UFDS *ufds, int a, int b) {
  a = UFDS_Component(ufds, a);
  b = UFDS_Component(ufds, b);

  if (a == b) return 0;

  if (ufds->size[b] > ufds->size[a]) {
    ufds->parent[a] = b;
    ufds->size[b] += ufds->size[a];
  } else {
    ufds->parent[b] = a;
    ufds->size[a] += ufds->size[b];
  }

  return 1;
}
