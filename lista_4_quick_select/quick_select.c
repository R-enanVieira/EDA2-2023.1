#include <stdlib.h>
#include <stdio.h>

void quickSelect(int *v, int l, int r, int k) {
  int i;
  if(r<=l) return;
  i = separa(v, l, r);
  if(i > k) quickSelect(v, l, i-1, k);
  if(i < k) quickSelect(v, i+1, r, k);
}
