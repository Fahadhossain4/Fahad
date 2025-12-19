#include <stdio.h>

int fac(int n) {
  if (n < 1)
    return 1;
    return n * fac(n - 1);
}
int main() {
  printf("The factorial of 5 is %d",fac(0));
  return 0;
}