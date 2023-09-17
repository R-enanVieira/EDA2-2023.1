#include <stdio.h>
#include <string.h>

#define MAX 21

int main() {
  int cont = 0, n; 
  while(scanf("%d", &n) != EOF) {
    char nomes[n][MAX];
    int notas[n];

    int menor;
    for (int i = 0; i < n; i++) {
      if(i) {
        scanf("%s %d", nomes[i], &notas[i]);
        if(notas[i] < notas[menor]) {
          menor = i;
        } else if(notas[i] == notas[menor]) {
          int tam = strlen(nomes[menor]);
          if(strncmp(nomes[i], nomes[menor], tam) > 0) menor = i;
          /*for (int j = 0; nomes[i][j] != '\0' && nomes[menor][j] != '\0'; j++) {
            if(nomes[i][j] > nomes[menor][j]) {
              menor = i;
              break;
            } else if(nomes[i][j] < nomes[menor][j]) {break;}
          } */
        } 
      } else {
        scanf("%s %d", nomes[i], &notas[i]);
        menor = i;
      }
    }
    printf("Instancia %d\n", ++cont);
    printf("%s\n", nomes[menor]);
    printf("\n");
 
  }
  return 0;
}
