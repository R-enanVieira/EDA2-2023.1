#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n, cont = 0; 
  while(scanf("%d", &n) && n != 0){
    int i = 0, ans[n], carry = 0, tj = 0, tz = 0;
    while(n--) {
      int j, z; scanf("%d %d", &j, &z);
      tj += j;
      tz += z;
      ans[i++] = tj-tz;
    }

    printf("Teste %d\n", ++cont);
    for (int j = 0; j < i; j++) {
      printf("%d\n", ans[j]); 
    }
    printf("\n");
  }
}
