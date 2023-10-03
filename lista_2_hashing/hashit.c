#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char *key) {
  int h, sum = 0;
  for(int i = 0; key[i] != '\0'; i++) {
    sum += (key[i]*(i+1))%101;
  }
  h = 19*sum;
  return h%101;
}

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, quant = 0; scanf("%d", &n);
    
    char *ht[101];
    for (int i = 0; i < 101; i++) {
      ht[i] = NULL;
    }
   
    while(n--) {
      char s[30]; scanf("%s", s);
      char key[16]; int i;
      
      for(i = 0; s[i] != '\0'; i++) {
        key[i] = s[4+i];
      }
      int len = i;
      key[i] = '\0';
      
      int h = hash(key);
      int c = h;
      int flag = 0, in = -1;

      if(s[0] == 'A') {
        for (int j = 1; j <= 20; j++) { 
          if(ht[h] != NULL && !strcmp(ht[h], key)) {
            flag = 1; 
            break;
          }
          else if(ht[h] == NULL && in == -1) {in = h;}
          h = (c + j*j + 23*j)%101;
        }

        if(!flag) quant++, ht[in] = malloc(sizeof(char)*len+1), strcpy(ht[in], key);
      } else { 
        for (int j = 1; j <= 20; j++) {
          if(ht[h] != NULL && !strcmp(ht[h], key)) {
            free(ht[h]);
            ht[h] = NULL; 
            quant--;
            break;
          }
          h = (c + j*j + 23*j)%101;
        }          
      }
    }

    printf("%d\n", quant);
    for(int j = 0; j < 101; j++) {
      if(ht[j] != NULL) {
        printf("%d:%s\n", j, ht[j]);
      }
    }
    printf("\n");
  }
  return 0;
}
