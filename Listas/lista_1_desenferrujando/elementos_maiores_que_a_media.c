#include <stdbool.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int v[n], sum = 0, avg;

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    sum += v[i];
  }

  avg = sum / n;
  bool flag = false;

  for (int i = 0; i < n; i++) {
    if (v[i] > avg) {
      if (!flag) {
        printf("%d", v[i]);
        flag = true;
      } else {
        printf(" %d", v[i]);
      }
    }
  }

  if (!flag)
    printf("0\n");
  else
    printf("\n");
}
