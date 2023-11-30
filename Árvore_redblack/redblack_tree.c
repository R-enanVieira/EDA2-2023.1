#include <stdio.h>
#include <stdbool.h>

typedef struct no {
  Item item;
  struct no *esq, *dir;
  bool red;
} no;

bool isRed(no *x) {
  if(x == null) return false;
  if(x->red) return true;
  return false;
}

void flip_colors(no *r) {
  r->esq->red = false;
  r->esq->red = false;
  r->red = false;
}

no *rotate_left(no *r) {
  no *nr = r->dir;
  r->dir = nr->esq;
  nr->esq = r;
  nr->red = r->red;
  r->red = true;
  return nr;
}

no *novo_no_RB(bool red, no *esq, no *dir, Item item) {
  no *novo_no = malloc(sizeof(no));
  novo_no->red = red;
  novo_no->esq = esq;
  novo_no->dir = dir;
  novo_no->item = item;
}

no *RB_insert(no * r, Item item) {
  if(r == NULL) 
    return novo_no_RB(true, NULL, NULL, item);

  if(less(Key(item), Key(r->item))) 
    r->esq = RB_insert(r->esq, item);
  else if(less(Key(r->item), Key(item)))
    r->dir = RB_insert(r->dir, item);
  else 
    r->item = item;

  if(!isRed(r->esq) && isRed(r->dir)) r = rotate_left(r);
  if(isRed(r->esq) && isRed(r->esq->esq)) r = rotate_right(r);
  if(isRed(r->esq) && isRed(r->dir)) flip_colors(r);
  
  return r;
}

