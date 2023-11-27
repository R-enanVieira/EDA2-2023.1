#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxV 5000
#define mod 315931
#define colLimit 35

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

typedef struct node {
  int v;
  struct node *next;
} node;

struct graph {
  int V, E;
  node *adj;
};

typedef struct item {
  char *s;
  int key;
  struct item *prox;
} item;

static int cnt, pre[maxV];
int conexos;

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
  cnt++;
  node *l;
  pre[w] = 1;  // variaveis globais
  for (l = G->adj[w].next; l != NULL; l = l->next) {
    t = l->v;
    if (!pre[t]) dfsR(G, EDGE(w, t));
  }
}

int graphSearch(Graph G) {
  int v, ans = 0;
  for (v = 0; v < G->V; v++) pre[v] = 0;

  for (v = 0; v < G->V; v++) {
    if (!pre[v]) {
      cnt = 0;
      dfsR(G, EDGE(v, v));
      ans = (cnt > ans ? cnt : ans);
    }
  }
  return ans;
}

int hashU(char *v, int M) {
  int h, a = 31415, b = 27183;
  for (h = 0; *v != '\0'; v++) {
    a = a * b % (M - 1);
    h = (a * b + *v) % M;
  }
  return (h < 0 ? h + M : h);
}

bool is_equal(char *str1, char *str2) {
  int i;
  for (i = 0; str1[i] != 0 && str2[i] != 0; i++) {
    if (str1[i] != str2[i]) return false;
  }

  return str1[i] == str2[i];
}

item *hash_search(item *ht, char *value) {
  int h = hashU(value, mod);
  item *aux;
  aux = ht[h].prox;
  while (aux != NULL) {
    if (is_equal(aux->s, value)) return aux;
    aux = aux->prox;
  }
  return NULL;
}

void hash_insert(item *ht, int key, char *value) {
  int h = hashU(value, mod);
  item *new;
  new = malloc(sizeof(item));

  new->s = value;
  new->key = key;
  new->prox = ht[h].prox;
  ht[h].prox = new;
}

int main() {
  int C, R;
  while (scanf("%d %d", &C, &R), C != 0 && R != 0) {
    Graph G = graphInit(C);

    item *HT;
    HT = malloc(sizeof(item) * mod);
    for (int i = 0; i < mod; i++) HT[i].prox = NULL;

    for (int i = 0; i < C; i++) {
      char s[35];
      scanf(" %s", s);

      char *temp = malloc(sizeof(char) * 35);
      strcpy(temp, s);

      hash_insert(HT, i, temp);
    }

    char v[35];
    char w[35];
    for (int i = 0; i < R; i++) {
      scanf(" %s %s", v, w);

      int key_v = hash_search(HT, v)->key;
      int key_w = hash_search(HT, w)->key;

      graphInsert(G, EDGE(key_v, key_w));
      graphInsert(G, EDGE(key_w, key_v));
    }
    printf("%d\n", graphSearch(G));
  }
}
