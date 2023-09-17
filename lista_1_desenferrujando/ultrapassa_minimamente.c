#include <stdio.h>
#include <limits.h>

int stack[SHRT_MAX];
int t = 0;

void push(int x) {
  stack[t++] = x;
}

int main() {
  int input, sequencia[SHRT_MAX], i = 0;
  while(scanf("%d", &input) && input != 0) {
    sequencia[i++] = input; 
  }
  sequencia[i] = input;
  int soma; scanf("%d", &soma);
  int ans = 0; 
  for (int j = 0; sequencia[j] != 0; j++) {
    ans += sequencia[j];
    if(ans > soma) {
      push(sequencia[j]);
      ans = 0;
    }
  }
  for (int j = t-1; j >= 0; j--) {
    int output = stack[j];
    printf("%d\n", output);
  }
}
