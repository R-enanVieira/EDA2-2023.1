#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxV 2001

typedef struct {
  int v;
  int w;
  int c;
} Edge;

Edge EDGE(int V, int W, int C) {
  Edge e;
  e.v = V;
  e.w = W;
  e.c = C;
  return e;
}

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

static int cnt, pre[maxV];

int queue[maxV], f = 0, l = 0;

void queuePut(int x) { queue[l++] = x; }

int queueGet() { return queue[f++]; }

bool queueEmpty() { return (f == l ? true : false); }

Graph graphInit(int V) {
  int v;
  Graph G = malloc(sizeof(*G));
  G->V = V;
  G->E = 0;
  G->adj = malloc(V * sizeof(node));
  for (v = 0; v < V; v++) {
    G->adj[v].v = 0;
    G->adj[v].next = NULL;
  }
  return G;
}

void graphInsert(Graph G, Edge e) {
  int v = e.v, w = e.w, c = e.c;

  node *newElement = malloc(sizeof(node));
  newElement->v = w;
  newElement->c = c;
  newElement->next = G->adj[v].next;
  G->adj[v].next = newElement;

  G->E++;
}

// Cheap Path Tree BelmanFord
bool graphCPTBF(Graph G, int s, int *pa, int *dist) {
  bool onqueue[G->V];
  for (int v = 0; v < G->V; v++)
    pa[v] = -1, dist[v] = INT_MAX, onqueue[v] = false;

  pa[s] = s;
  dist[s] = 0;

  queuePut(s);
  onqueue[s] = true;
  queuePut(G->V);
  int k = 0;

  while (1) {
    int v = queueGet();

    if (v < G->V) {
      for (node *a = G->adj[v].next; a != NULL; a = a->next) {
        if (dist[v] + a->c < dist[a->v]) {
          dist[a->v] = dist[v] + a->c;
          pa[a->v] = v;

          if (onqueue[a->v] == false) {
            queuePut(a->v);
            onqueue[a->v] = true;
          }
        }
      }
    } else {
      if (queueEmpty()) return true;
      if (++k >= G->V) return false;
      queuePut(G->V);
      for (int t = 0; t < G->V; t++) onqueue[t] = false;
    }
  }
}
