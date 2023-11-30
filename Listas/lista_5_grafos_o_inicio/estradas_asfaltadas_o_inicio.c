#include <stdio.h>
#include <stdlib.h>

#define maxV 5000

typedef struct {int v; int w;} Edge;
Edge EDGE(int V, int W) {
  Edge e;
  e.v = V;
  e.w = W;
  return e;
}
typedef struct graph* Graph;

typedef struct node {
  int v;
  struct node *next;
} node;

struct graph {
  int V, E;
  node *adj; 
};

static int cnt, pre[maxV];
int conexos;

Graph graphInit(int V) {
  int v;
  Graph G = malloc(sizeof(*G));
  G->V = V;
  G->E = 0;
  G->adj = malloc(V*sizeof(node));
  for (v = 0; v < V; v++) {
    G->adj[v].v = 0;
    G->adj[v].next = NULL;
  }
  return G;
}

void graphInsert(Graph G, Edge e) {
  int v = e.v, 
      w = e.w;

  node *newElement = malloc(sizeof(node));
  newElement->v = w;
  newElement->next = G->adj[v].next;
  G->adj[v].next = newElement;

  G->E++;
}

int graphEdges(Edge a[], Graph G) {
  int v, E = 0;
  node *t;
  for(v = 0; v < G->V; v++)
     for(t = &(G->adj[v]); t != NULL; t = t->next)
      if(v < t->v) a[E++] = EDGE(v, t->v);
}

void dfsR(Graph G, Edge e) {
  int t, w = e.w;
  node *l;
  pre[w] = cnt++; //variaveis globais
  for(l = &(G->adj[w]); l != NULL; l = l->next) {
    t = l->v;
    if(pre[t] == -1) 
       dfsR(G, EDGE(w, t));
  }
}

int graphSearch(Graph G) {
  int v, conexos = 0;
  cnt = 0;
  for (v = 0; v < G->V; v++)
    pre[v] = -1;

  for(v = 0; v < G->V; v++) {
    if(pre[v] == -1) {
      dfsR(G, EDGE(v,v));
      conexos++;
    }
  }
  return conexos;
}

int main() {
  int V; scanf("%d", &V);
  Graph G = graphInit(V);
  
  int v, w;
  while(scanf("%d %d", &v, &w) != EOF) {
    graphInsert(G, EDGE(v, w));
    graphInsert(G, EDGE(w, v));
  }
  
  printf("%d\n", graphSearch(G));
}
