#include <stdio.h>

int a = 0;
int b = 0;
int c = 0;
int d = 0;

int x = 2;
int y = 4;

int main ()
  {
    a = x < y;
    printf("%d", a);

    b = x > y;
    printf("%d", b);

    c = x >= y;
    printf("%d", c);

    d = x <= y;
    printf("%d", d);
  }