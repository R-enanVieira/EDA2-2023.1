#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxV 2001

typedef struct edge {
  int v;
  int w;
} Edge;

Edge EDGE(int V, int W) {
  Edge e;
  e.v = V;
  e.w = W;
  return e;
}

struct graph {
  int V, E;
  int **adj, **tc;
};

typedef struct graph *Graph;

static int pre[maxV], cnt = 0;

int **MATRIXinit(int R, int C, int x) {
  int **m = (int **)malloc(sizeof(int *) * R);
  for (int i = 0; i < C; i++) m[i] = (int *)malloc(sizeof(int) * C);

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++) m[i][j] = x;

  return m;
}

Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof(Graph));
  G->V = V;
  G->E = 0;
  G->adj = MATRIXinit(V, V, 0);
  return G;
}

void GRAPHInsertE(Graph G, Edge E) {
  int v = E.v, w = E.w;
  if (G->adj[v][w] == 0) G->E++;
  G->adj[v][w] = 1;
}

void FloydWarshall(Graph G) {
  int i, s, t;

  G->tc = MATRIXinit(G->V, G->V, 0);

  for (s = 0; s < G->V; s++)
    for (t = 0; t < G->V; t++) G->tc[s][t] = G->adj[s][t];

  for (s = 0; s < G->V; s++) G->tc[s][s] = 1;

  for (i = 0; i < G->V; i++)
    for (s = 0; s < G->V; s++)
      if (G->tc[s][i] == 1)
        for (t = 0; t < G->V; t++)
          if (G->tc[i][t] == 1) G->tc[s][t] = 1;
}

int main() {
  int n, m;

  while (scanf("%d %d", &n, &m) == 2 && n != 0 && m != 0) {
    Graph G = GRAPHinit(n);

    for (int i = 0; i < m; i++) {
      int v, w, p;
      scanf("%d %d %d", &v, &w, &p);

      GRAPHInsertE(G, EDGE(v - 1, w - 1));
      if (p == 2) GRAPHInsertE(G, EDGE(w - 1, v - 1));
    }

    FloydWarshall(G);

    bool ans = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) ans &= G->tc[i][j];

    printf("%d\n", (ans == true ? 1 : 0));
  }

  return 0;
}
