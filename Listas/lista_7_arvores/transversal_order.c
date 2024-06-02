#include <stdio.h>
#include <unistd.h>

int search(char *in, char x, int n) {
  for (int i = 0; i < n; i++) {
    if(in[i] == x) return i; 
  }
  return -1;
}

void print_post_order(char* pre, char* in, int n) {
  int root = search(in, pre[0], n);

  if(root != 0) print_post_order(pre+1, in, root);
  if(root != n-1) print_post_order(pre+root+1, in+root+1, n-root-1);

  printf("%c", pre[0]);
}

int main() {
  int t; scanf("%d", &t);

  while(t--) {
    int n; scanf("%d", &n);
    
    char pre[n+1], in[n+1];
    scanf(" %s %s", pre, in);

    print_post_order(pre, in, n);
    printf("\n");
  }
}
