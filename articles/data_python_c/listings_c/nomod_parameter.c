# include <string.h>
# include <stdio.h>


void func(int a, char string1[], char string2[])
{

  char string3[15];

  /* Create a copy of string2 in string3*/
  strcpy(string3, string2);

  printf("Before modification in func()\n");
  printf("Address of a: %p \n", &a);
  printf("Address of string1: %p \n", &string1[0]);
  printf("Address of string2: %p \n", &string2[0]);
  printf("Address of string3: %p \n", &string3[0]);

  printf("a = %d \nstring1 = %s \nstring2 = %s\n",a, string1, string3);
  printf("\n");

  /* Make modifications */
  a = a+1;
  string1[0] = string1[0] + 5;
  string3[0] = string3[0] + 5;

  printf("After modification in func()\n");

  printf("Address of a: %p \n", &a);
  printf("Address of string1: %p \n", &string1[0]);
  printf("Address of string2: %p \n", &string2[0]);
  printf("Address of string3: %p \n", &string3[0]);

  printf("a = %d \nstring1 = %s \nstring2 = %s\n",a, string1, string3);
  printf("\n");

  return;
}

int main(int argc, char **argv)
{

  int a = 5;
  char string1[] = "A String";
  char string2[] = "B String";

  printf("Before call to func()\n");

  printf("Address of a: %p \n", &a);
  printf("Address of string1: %p \n", &string1[0]);
  printf("Address of string2: %p \n", &string2[0]);

  printf("a = %d \nstring1 = %s \nstring2 = %s\n",a, string1, string2);
  printf("\n");

  func(a, string1, string2);

  printf("After call to func()\n");

  printf("Address of a: %p \n", &a);
  printf("Address of string1: %p \n", &string1[0]);
  printf("Address of string2: %p \n", &string2[0]);

  printf("a = %d \nstring1 = %s \nstring2 = %s\n",a, string1, string2);
  printf("\n");
  
  return 0;
}
