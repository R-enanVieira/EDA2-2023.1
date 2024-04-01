#include <stdbool.h>
#include <stdio.h>

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void move(int *v, int c) {
  v[0] += dir[c - 1][0];
  v[1] += dir[c - 1][1];
}

bool check(int *men, int x, int y) {
  if (men[0] >= x - 1 && men[0] <= x + 1 && men[1] >= y - 1 && men[1] <= y + 1)
    return true;
  else
    return false;
}

int main() {
  int n, m, ans = 0;
  scanf("%d %d", &n, &m);

  int x, y;
  scanf("%d %d", &x, &y);

  int men[2] = {0, 0};

  int k;
  scanf("%d", &k);

  for (int i = 0; i < k; i++) {
    int c;
    scanf("%d", &c);

    move(men, c);

    if (check(men, x, y)) ans++;
  }

  printf("%d\n", ans);
}
