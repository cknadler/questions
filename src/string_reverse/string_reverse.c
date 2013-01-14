#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 256

void reverse(char* string)
{
  char back[STRING_SIZE];
  int i, length = strlen(string) - 1;

  for(i = length; i >= 0; i--)
    back[length - i] = string[i];
  
  strcpy(string, back);
}

int main()
{
  // Read string from a file
  FILE* file_ptr = fopen("test.txt", "r");

  if (file_ptr == NULL)
    return 1;

  char* string = malloc(STRING_SIZE);

  fscanf(file_ptr, "%s", string);

  // Solution
  reverse(string);
  printf("%s\n", string);

  return 0;
}
