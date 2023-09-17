#include <stdio.h>

int main() {
  int n; scanf("%d", &n);

  int ans=0;
  while(n--) {
    int a; 

    scanf("%d", &a);

    ans += a;
  }

  printf("%d\n", ans);

  return 0;
}

