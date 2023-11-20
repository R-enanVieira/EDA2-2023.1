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

typedef struct item {
  int vIncial;
  int tam;
} item;

static int cnt, pre[maxV];
int conexos;
item ans[maxV]; int z = 0, J;

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
     for(t = G->adj[v].next; t != NULL; t = t->next)
      if(v < t->v) a[E++] = EDGE(v, t->v);
}

void dfsR(Graph G, Edge e) {
  ans[z].tam++;
  int t, w = e.w;
  node *l;
  pre[w] = cnt++; //variaveis globais
  for(l = G->adj[w].next; l != NULL; l = l->next) {
    t = l->v;
    if(t == J) ans[z].vIncial = t;
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
      ans[z].vIncial = v;
      ans[z].tam = 0;
      dfsR(G, EDGE(v,v));
      conexos++; z++;

    }
  }
  return conexos;
}

static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].tam > v[j].tam) aux[k++] = v[i++];
    else if(v[i].tam == v[j].tam && v[i].vIncial == J) aux[k++] = v[i++];
    else if(v[i].tam == v[j].tam && v[j].vIncial == J) aux[k++] = v[j++];
    else if(v[i].tam == v[j].tam && v[i].vIncial < v[j].vIncial) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(item *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int main() {
  int V; scanf("%d %d", &V, &J);
  Graph G = graphInit(V);
  
  int v, w;
  while(scanf("%d %d", &v, &w) != EOF) {
    graphInsert(G, EDGE(v, w));
    graphInsert(G, EDGE(w, v));
  }

  graphSearch(G);
 
  merge_sort(ans, 0, z);
  
  if(ans[0].vIncial == J && ans[0].tam == 1) printf("Fique em casa\n");
  else if(ans[0].vIncial == J) printf("Bora pra estrada\n");
  else printf("Vamos para %d\n", ans[0].vIncial);
}

