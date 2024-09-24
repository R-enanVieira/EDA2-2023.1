#include <stdbool.h>
#include <stdio.h>

int main() {
  int n, m, j;
  scanf("%d %d %d", &n, &m, &j);
  int matAdj[n + 1][n + 1];

  for (int i = 0; i <= n; i++)
    for (int k = 0; k <= n; k++) matAdj[i][k] = 0;

  for (int v = 0; v < n; v++) {
    int a;
    scanf("%d", &a);
    for (int k = 0; k < a; k++) {
      int w;
      scanf("%d", &w);
      matAdj[v][w] = 1;
    }
  }

  bool visited[2002] = {false};

  for (int i = 0; i < m; i++) {
    int x;
    scanf("%d", &x);
    visited[x] = true;
    for (int k = 0; k <= n; k++) {
      if (matAdj[x][k]) visited[k] = true;
    }
  }

  for (int i = 0; i < j; i++) {
    int query;
    scanf("%d", &query);

    if (visited[query])
      printf("Eu vou estar la\n");
    else
      printf("Nao vou estar la\n");
  }

  return 0;
}
