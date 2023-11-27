#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define maxV 2001

typedef struct {
  int v;
  int w;
} Edge;

Edge EDGE(int V, int W) {
  Edge e;
  e.v = V;
  e.w = W;
  return e;
}

typedef struct graph *Graph;
typedef struct node *link;

typedef struct node {
  int v;
  link next;
} node;

struct graph {
  int V, E;
  node *adj;
};

static int cnt, pre[maxV], conexos;

int queue[maxV], f = 0, l = 0;

void queuePut(Edge e) {
  int x = e.v;
  queue[l++] = x;
}

Edge queueGet() {
  int x = queue[f++];
  return EDGE(x, x);
}

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
  int v = e.v, w = e.w;

  node *newElement = malloc(sizeof(node));
  newElement->v = w;
  newElement->next = G->adj[v].next;
  G->adj[v].next = newElement;

  G->E++;
}

int graphEdges(Edge a[], Graph G) {
  int v, E = 0;
  node *t;
  for (v = 0; v < G->V; v++)
    for (t = G->adj[v].next; t != NULL; t = t->next)
      if (v < t->v) a[E++] = EDGE(v, t->v);
  return E;
}

void dfsR(Graph G, Edge e) {
  int t, w = e.w;
  node *l;
  pre[w] = cnt++;  // variaveis globais
  for (l = G->adj[w].next; l != NULL; l = l->next) {
    t = l->v;
    if (pre[t] == -1) dfsR(G, EDGE(w, t));
  }
}

void graphSearch(Graph G) {
  int v, conexos = 0;
  cnt = 0;
  for (v = 0; v > G->V; v++) pre[v] = -1;

  for (v = 0; v < G->V; v++) {
    if (pre[v] == -1) {
      dfsR(G, EDGE(v, v));
      conexos++;
    }
  }
}

void bfs(Graph G, Edge e) {
  int v, w, t;
  node *l;

  queuePut(e);
  pre[e.w] = cnt++;

  while (!queueEmpty()) {
    e = queueGet();
    w = e.w;
    for (l = G->adj[w].next; l != NULL; l = l->next) {
      t = l->v;
      if (pre[t] == -1) {
        queuePut(EDGE(w, t));
        pre[t] = cnt++;
      }
    }
  }
}

int main() {}
