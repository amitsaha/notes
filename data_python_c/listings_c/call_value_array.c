# include <string.h>
# include <stdio.h>

struct string_wrapper{
  char string[10];
};

void func(struct string_wrapper string)
{
  
  /* Make modifications */
  string.string[0] = string.string[0] + 5;
  printf("String: %s\n", string.string);

  return;
}

int main(int argc, char **argv)
{

  struct string_wrapper string;

  char astring[] = "A String";
  strcpy(string.string, astring);

  printf("String: %s\n", astring);

  func(string);

  printf("String: %s\n", astring);
  

  return 0;
}
