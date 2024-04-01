#include <stdbool.h>
#include <stdio.h>

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  int cp[m][n];

  int p;
  scanf("%d", &p);

  int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  int pa[2] = {1, 1};
  int pb[2] = {m, n};
  int meet[3] = {0, 0, 0}, pa_left[3] = {0, 0, 0}, pb_left[3] = {0, 0, 0};

  for (int i = 0; i < p; i++) {
    int a, b;
    scanf("%d %d", &a, &b);

    pa[0] += dir[a - 1][0];
    pa[1] += dir[a - 1][1];

    pb[0] += dir[b - 1][0];
    pb[1] += dir[b - 1][1];

    if (pa[0] < 1 && !pa_left[2])
      pa_left[0] = pa[0], pa_left[1] = pa[1], pa_left[2] = i + 1;
    else if (pa[1] < 1 && !pa_left[2])
      pa_left[0] = pa[0], pa_left[1] = pa[1], pa_left[2] = i + 1;
    else if (pa[0] > m && !pa_left[2])
      pa_left[0] = pa[0], pa_left[1] = pa[1], pa_left[2] = i + 1;
    else if (pa[1] > n && !pa_left[2])
      pa_left[0] = pa[0], pa_left[1] = pa[1], pa_left[2] = i + 1;

    if (pb[0] < 1 && !pb_left[2])
      pb_left[0] = pb[0], pb_left[1] = pb[1], pb_left[2] = i + 1;
    else if (pb[1] < 1 && !pb_left[2])
      pb_left[0] = pb[0], pb_left[1] = pb[1], pb_left[2] = i + 1;
    else if (pb[0] > m && !pb_left[2])
      pb_left[0] = pb[0], pb_left[1] = pb[1], pb_left[2] = i + 1;
    else if (pb[1] > n && !pb_left[2])
      pb_left[0] = pb[0], pb_left[1] = pb[1], pb_left[2] = i + 1;

    if (pa[0] == pb[0] && pa[1] == pb[1] && !meet[2])
      meet[0] = pa[0], meet[1] = pa[1], meet[2] = i + 1;
  }

  if (meet[2]) {
    printf("Encontraram-se na posicao (%d,%d) no passo %d\n", meet[1], meet[0],
           meet[2]);
  } else if (pa_left[2]) {
    if (pa_left[2] && !pb_left[2])
      printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_left[1], pa_left[0],
             pa_left[2]);
    else if (pb_left[2] && pa_left[2] <= pb_left[2])
      printf("PA saiu na posicao (%d,%d) no passo %d\n", pa_left[1], pa_left[0],
             pa_left[2]);
    else if (pb_left[2])
      printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_left[1], pb_left[0],
             pb_left[2]);
  } else if (pb_left[2]) {
    printf("PB saiu na posicao (%d,%d) no passo %d\n", pb_left[1], pb_left[0],
           pb_left[2]);
  } else {
    printf("Nao se encontraram\n");
  }

  return 0;
}
