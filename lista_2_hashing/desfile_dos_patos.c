#include <stdio.h>

const int MAX = 1000001;

int main() {
  int n; 

  while(scanf("%d", &n), n != 0) {
    int cont[MAX];
  
    for(int i = 0; i < MAX+1; i++) {
      cont[i] = 0;
    }

    for(int i = 0; i < n; i++) {
      int input; scanf("%d", &input);
      cont[input]++;
    }

    int maior = 0;
    for (int i = 1; i < MAX+1; i++) {
      if(cont[i] > cont[maior]) maior = i;
    }
    printf("%d\n", maior);
  }

  return 0;
}
