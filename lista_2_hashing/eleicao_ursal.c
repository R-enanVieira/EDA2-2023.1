#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX = 100000;
typedef struct item {
  int num;
  int quant;
} item;

static void merge(item *v, int l, int m, int r) {
	item *aux;
	aux = malloc((r-l) * sizeof(item));
	int i = l, j = m;
	int k = 0;

	while(i < m && j < r) {
		if(v[i].quant > v[j].quant) aux[k++] = v[i++];
    else if(v[i].quant == v[j].quant && v[i].num > v[j].num) aux[k++] = v[i++];
		else aux[k++] = v[j++];
	}
	while(i < m) aux[k++] = v[i++];	
	while(j < r) aux[k++] = v[j++];

	for(i = l; i < r; ++i) v[i] = aux[i-l];
	free(aux);
}

void merge_sort(item *v, int l, int r) {
	if(l < r-1) {
	  int middle = (l+r)/2;
	  merge_sort(v, l, middle);
	  merge_sort(v, middle, r);
	  merge(v, l, middle, r);
  }
}

int main()
{
  int s, f, e; scanf("%d %d %d", &s, &f, &e);
  
  item p[100], sen[1000], df[10000], de[100000];
  memset(p, 0, sizeof(item)*100);
  memset(sen, 0, sizeof(item)*1000);
  memset(df, 0, sizeof(item)*10000);
  memset(de, 0, sizeof(item)*100000);
  
  int contV = 0, contT = 0, contP = 0;

  int x;
  while(scanf("%d", &x) != EOF) {
    if(x >= 0) {
      contV++;
      if(x < 100) {
        p[x].num = x;
        p[x].quant++;
        contP++;
      } else if(x < 1000) {
        sen[x].num = x;
        sen[x].quant++;
      } else if (x < 10000) {
        df[x].num = x;
        df[x].quant++;
      } else {
        de[x].num = x;
        de[x].quant++;
      }
    }
    contT++;
  }

  merge_sort(p, 0, 100);
  merge_sort(sen, 0, 1000);
  merge_sort(df, 0, 10000);
  merge_sort(de, 0, 100000);

  printf("%d %d\n", contV, contT-contV);
  if(p[0].quant > contP/2) printf("%d\n", p[0].num);
  else printf("Segundo Turno\n");
  for (int i = 0; i < s; i++) {
    if(i != s-1) printf("%d ", sen[i].num);
    else printf("%d\n", sen[i].num);
  }

  for (int i = 0; i < f; i++) {
    if(i != f-1) printf("%d ", df[i].num);
    else printf("%d\n", df[i].num);
  }

  for (int i = 0; i < e; i++) {
    if(i != e-1) printf("%d ", de[i].num);
    else printf("%d\n", de[i].num);
  }

  return 0;
}
