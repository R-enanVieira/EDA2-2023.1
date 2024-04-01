#include <stdio.h>
#include <string.h>

int main() {
  char dict[5][8] = {
      {"pedra\0"}, {"papel\0"}, {"tesoura\0"}, {"lagarto\0"}, {"Spock\0"}};

  char s[8], r[8];
  scanf("%s %s", s, r);

  if (!strcmp(s, r))
    printf("De novo!\n");
  else if ((!strcmp(s, dict[2]) && !strcmp(r, dict[1])) ||
           (!strcmp(s, dict[1]) && !strcmp(r, dict[0])) ||
           (!strcmp(s, dict[0]) && !strcmp(r, dict[3])) ||
           (!strcmp(s, dict[3]) && !strcmp(r, dict[4])) ||
           (!strcmp(s, dict[4]) && !strcmp(r, dict[2])) ||
           (!strcmp(s, dict[2]) && !strcmp(r, dict[3])) ||
           (!strcmp(s, dict[3]) && !strcmp(r, dict[1])) ||
           (!strcmp(s, dict[1]) && !strcmp(r, dict[4])) ||
           (!strcmp(s, dict[4]) && !strcmp(r, dict[0])) ||
           (!strcmp(s, dict[0]) && !strcmp(r, dict[2])))
    printf("Bazinga!\n");
  else
    printf("Raj trapaceou!\n");
}
