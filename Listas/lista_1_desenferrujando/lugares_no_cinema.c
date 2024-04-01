#include <stdio.h>
#include <string.h>

int main() {
  int f, l;
  scanf("%d %d", &f, &l);

  char letras[20] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                     'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

  int s[f + 1][l + 1];

  for (int i = 0; i <= f; i++) {
    for (int j = 0; j <= l; j++) {
      s[i][j] = 0;
    }
  }
  char se[4];

  // 64
  while (scanf("%s", se) != EOF) {
    int num = 0;
    if (strlen(se) == 3)
      num += (se[1] - '0') * 10 + se[2] - '0';
    else
      num += se[1] - '0';

    s[(int)(se[0] - 64)][num] = 1;
  }

  printf("  ");

  for (int i = 0; i < l; i++) {
    if (i + 1 < 10) {
      if (i < l - 1)
        printf("0%d ", i + 1);
      else
        printf("0%d\n", i + 1);
    } else {
      if (i < l - 1)
        printf("%d ", i + 1);
      else
        printf("%d\n", i + 1);
    }
  }

  for (int i = f; i >= 1; i--) {
    printf("%c ", letras[i - 1]);
    for (int j = 1; j <= l; j++) {
      if (s[i][j]) {
        if (j < l)
          printf("XX ");
        else
          printf("XX");
      } else {
        if (j < l)
          printf("-- ");
        else
          printf("--");
      }
    }
    printf("\n");
  }

  return 0;
}
