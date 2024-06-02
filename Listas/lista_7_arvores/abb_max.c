typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

no *maximo (no *r) {
  if(r->dir) return maximo(r->dir);
  return r;
}
