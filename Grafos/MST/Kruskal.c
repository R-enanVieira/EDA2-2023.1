#include <stdbool.h>
#include <stdlib.h>

typedef struct {
  int *parent;
  int *size;
} UFDS;

UFDS *UFDS_New(int n) {
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

void UFDS_Desstroy(UFDS *ufds) {
  free(ufds->parent);
  free(ufds->size);
  free(ufds);
}

//-----------------------------------------------------------------------------------

// Complexity: O(E*LogE + E)

typedef struct {
  int u, v;
  long long w;
} Edge;

int compare(const void *a, const void *b) {
  return ((Edge *)a)->w - ((Edge *)b)->w;
}

Edge *Kruskal(int graphSize, Edge *edges, int edgesLen) {
  qsort(edges, edgesLen, sizeof(Edge), compare);

  Edge *choosenEdges = malloc(sizeof(Edge) * (graphSize - 1));
  int choosenEdgesLen = 0;

  UFDS *ufds = UFDS_New(graphSize);

  for (int i = 0; i < edgesLen && choosenEdgesLen < graphSize - 1; i++) {
    int u = edges[i].u;
    int v = edges[i].v;
    if (!UFDS_SameSet(ufds, u, v)) {
      choosenEdges[choosenEdgesLen++] = edges[i];
      UFDS_JoinSets(ufds, u, v);
    }
  }

  UFDS_Desstroy(ufds);

  return choosenEdges;
}

int main() { return 0; }
