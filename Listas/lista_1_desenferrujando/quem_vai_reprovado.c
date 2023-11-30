#include <stdio.h>
#include <string.h>

typedef struct ALUNO {
  int nota;
  char nome[21];
} aluno;

void solve(aluno *v, int x) {
  int menor = 0;
  for(int i = 1; i < x; i++) {
    if(v[i].nota < v[menor].nota)
      menor = i;
    else if(v[i].nota == v[menor].nota && strcmp(v[menor].nome, v[i].nome) < 0)
      menor = i;
  }
  printf("%s\n\n", v[menor].nome);
}

int main() {
  int n, cont = 0;
  while(scanf("%d", &n) != EOF) {
    aluno alunos[n];
    for(int i = 0; i < n; i++) {
      scanf("%s %d", alunos[i].nome, &alunos[i].nota);
    }
    printf("Instancia %d\n", ++cont);
    solve(alunos, n);
  }
  return 0;
} 
