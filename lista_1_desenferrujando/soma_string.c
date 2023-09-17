#include <stdio.h>
#include <string.h>

#define MAX 101

int main() {
  int n; scanf("%d", &n);
  while(n--) {
    char s[MAX];
    int ans = 0;
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; i++) {
      if(s[i] < 58) {
        ans += s[i]-'0';
      }
    }
    printf("%d\n", ans);
  }
}

