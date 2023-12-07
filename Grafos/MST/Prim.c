Edge *Prim(Graph *G) {
  HeapIndex *h = HeapIndex_New(malloc(sizeof(HeapItem) * g->size), g->size);
  for (int i = 1; i < g->size; i++) {
    h->items[i] = (HeapItem){0, i, __LONG_LONG_MAX__};
    h->pq[i] = i;
    h->hash[i] = i;
  }

  h->hash[0] = g->size;
  h->size = g->size - 1;

  Edge *choosenEdges = malloc(sizeof(Edge) * (g->size - 1));
  int edgesLen = 0;

  Edge *actual = g->adj[0].next;
  while (!HeapIndex_Empty(h)) {
    while (actual) {
      if (h->hash[actual->v] <= h->size && actual->w < h->items[actual->v].w) {
        HeapIndex_Update(h, actual->v,
                         (HeapItem){actual->u, actual->v, actual->w});
      }

      actual = actual->next;
    }

    HeapItem edge = h->items[HeapIndex_Top(h)];
    choosenEdges[edgesLen++] = (Edge){edge.u, edge.v, edge.w, NULL};
    HeapIndex_Pop(h);
    actual = g->adj[edge.v].next;
  }
}
