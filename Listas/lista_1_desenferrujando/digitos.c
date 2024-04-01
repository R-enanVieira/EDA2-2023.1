#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *plus_one(char *c, int l, int r) {
  char *cpy = malloc(10000 * sizeof(char));
  bool flag = false;
  strncpy(cpy, c, r + 1);

  for (int i = r; i >= l; i--) {
    if (c[i] == '9') {
      if (i == l) {
        cpy[i] = '0';
        char *ans = malloc((r + 3) * sizeof(char));

        ans[0] = '1';

        for (int j = 0; j <= r; j++) {
          ans[j + 1] = cpy[j];
          if (j == r) ans[j + 2] = '\0';
        }

        return ans;
      }
      flag = true;
      cpy[i] = '0';
      continue;
    }
    cpy[i] = c[i] + 1;
    break;
  }
  return cpy;
}

int main() {
  int n;
  scanf("%d", &n);

  char s[10000];

  for (int i = 0; i < n; i++) {
    char x;
    scanf(" %c", &x);
    s[i] = x;
  }

  s[n] = '\0';

  for (int i = 0; i <= n / 2; i++) {
    bool flag = true;
    char a[10000];
    strncpy(a, s, i + 1);
    char *p = plus_one(s, 0, i);
    int tam = strlen(a);

    for (int j = i + 1; j < n; j += tam) {
      tam = strlen(p);
      char b[10000];
      strncpy(b, s + j, tam);
      b[tam] = '\0';

      if (strcmp(p, b)) {
        flag = false;
        break;
      } else {
        p = plus_one(b, 0, tam - 1);
      }
    }

    if (flag) {
      printf("%s\n", a);
      return 0;
    }
  }

  printf("%s\n", s);

  return 0;
}
