#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int v;
  int w;
} edge;

edge Edge(int, int);

typedef struct graph *Graph;

Graph GRAPHinit(int);
void GRAPHInsertE(Graph, Edge);
void GRAPHRemoveE(Graph, Edge);
int GRAPHEdges(Edge[], GraphG);
Graph GRAPHCopy(Graph);
void GRAPHDestroy(Graph);
  
void dfsR(Graph G, Edge e) {
  int t, w = e.w;
  pre[w] = cnt++; //variaveis globais
  for(t = 0; t < G->V; t++) {
    if(G->adj[w][t] != 0)
      if(pre[t] == -1) 
        dfsR(G, EDGE(w, t));
  }
}

int main() {

  return 0;
}
