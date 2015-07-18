#include <stdio.h>

int main () {
  int c,f;f = 0;

  printf("Input :\n");
  while( (c = getchar()) != EOF)
    { if ( c != ' '){f = 0;putchar(c);}
      if ( c == ' ' && f == 0 ){ f = 1;putchar(c);}
    }
 
}
