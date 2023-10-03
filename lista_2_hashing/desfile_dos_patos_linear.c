#include <stdio.h>

int main()
{
  int n, current, counter = 0;
  while(scanf("%d", &n) == 1, n != 0) 
  {
    counter = 0; current = 0;
    for(int i = 0; i < n; i++) { 
      int x; scanf("%d", &x);
      if(!counter) {current = x; counter++;}
      else if(x == current) {counter++;}
      else {counter--;}
    }
    printf("%d\n", current);
  }
  return 0;
}
