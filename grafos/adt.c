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
  


int main() {
  return 0;
}
