#include <stdio.h>
#include <string.h>


int main() {
  int n; scanf("%d", &n);
  char mask[1000001]; 
  int ans = 0;
  for (int i = 0; i < 1000001; i++) {
    mask[i] = 'f';
  }
  while(n--) {
    int v; scanf("%d", &v);
    if(mask[v] == 'f') {
      mask[v] = 'v';
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}
