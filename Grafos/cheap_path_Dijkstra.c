#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct graph *Graph;
typedef struct node *link;

typedef struct node {
  int v;
  int c;
  link next;
} node;

struct graph {
  int V, E;
  node *adj;
};

// Dijkstra (ingênuo)
// Caminhos mínimos
// Somente pesos positivos!

void graphcpTDJ(Graph G, int s, int *pa, int *dist) {
  bool mature[1000];

  for (int v = 0; v < G->V; v++)
    pa[v] = -1, mature[v] = false, dist[v] = INT_MAX;

  pa[s] = 1;
  dist[s] = 0;

  while (true) {
    int min = INT_MAX;
    int y;
    for (int z = 0; z < G->V; z++) {
      if (mature[z]) continue;
      if (dist[z] < min) min = dist[z], y = z;
    }
    if (min == INT_MAX) break;

    for (node *a = G->adj[y].next; a != NULL; a = a->next) {
      if (mature[a->v]) continue;
      if (dist[y] + a->c < dist[a->v]) {
        dist[a->v] = dist[y] + a->c;
        pa[a->v] = y;
      }
    }
    mature[y] = true;
  }
}
