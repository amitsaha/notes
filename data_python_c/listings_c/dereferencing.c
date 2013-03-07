#include <stdio.h>

int main(int argc, char **argv)
{
  int a=1;
  int *ptr;
	
  printf("Address of a:: %p, Value of a:: %d\n", &a, a);

  ptr = &a;
  *ptr = 2;

  printf("Address of a:: %p, Value of a:: %d\n", ptr, *ptr);
  
  return 0;
}
