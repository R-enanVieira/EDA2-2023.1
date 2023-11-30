#include <stdio.h>

typedef struct restaurante {
  int c;
  int n;
} rest;

int main() {
  int r, day = 0;
  while(scanf("%d", &r) != EOF){
    rest vect[r];
    rest *ans;
    for (int i  = 0; i < r; i++) {
      if(i) {
        scanf("%d %d", &vect[i].c, &vect[i].n);
        if(vect[i].n > ans->n) {ans = vect+i;}
        else if(vect[i].n == ans->n) {
          if(vect[i].c < ans->c) ans = vect+i;
        }
      } else {
        scanf("%d %d", &vect[i].c, &vect[i].n);
        ans = vect+i;
      }
    }
    printf("Dia %d\n", ++day);
    printf("%d\n\n", ans->c);
  }
  return 0;
}

