typedef struct no {
  int chave;
  struct no *esq, *dir;
} no;

no *minimo (no *r) {
  if(r->esq) return minimo(r->esq);
  return r;
}
