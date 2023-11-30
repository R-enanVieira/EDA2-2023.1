#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char stack[SHRT_MAX][101];
int t = -1;

void push(char *x) {
  strcpy(stack[++t], x);
}

int pop() {
  if(t == -1) 
    return t;
  else 
    return t--;
}

int main() {
  char s[111];
  while(scanf(" %[^\n]", s) != EOF) {
    if(s[0] == 'i') {
      char text[101];
      int i;
      for (i = 0; s[8+i] != '\0'; i++) {
        text[i] = s[8+i];
      }
      text[i] = '\0';
      push(text);
    } else {
      int ans = pop();
      if(ans == -1) printf("NULL\n");
      else printf("%s\n", stack[ans]);
    }
  }
  return 0;
}

