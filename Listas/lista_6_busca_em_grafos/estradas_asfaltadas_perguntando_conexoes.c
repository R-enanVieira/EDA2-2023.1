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
  int n, v, w, p;

  scanf("%d", &n);
  Graph G = GRAPHinit(n);

  while (1) {
    scanf("%d %d %d", &v, &w, &p);
    if ((v + w + p) == 0) break;

    GRAPHInsertE(G, EDGE(v, w));
    if (p == 2) GRAPHInsertE(G, EDGE(w, v));
  }

  FloydWarshall(G);
  int r, s;
  scanf("%d %d", &r, &s);

  do {
    if (G->tc[r][s] == 1 && G->tc[s][r] == 1)
      printf("Ida e Volta\n");
    else if (G->tc[r][s] == 1)
      printf("Apenas Ida\n");
    else if (G->tc[s][r] == 1)
      printf("Apenas Volta\n");
    else
      printf("Impossibru\n");
  } while (scanf("%d %d", &r, &s) != EOF);

  return 0;
}
