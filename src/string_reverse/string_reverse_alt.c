#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 256

void reverse(char* string)
{
  char* back = string;
  char tmp;

  while (*back)
    ++back;

  while (back > string)
  {
    tmp = *string;
    *string = *back;
    *back = tmp;

    ++string;
    --back;
  }
}

int main()
{
  // Read string from a file
  FILE* file_ptr = fopen("test.txt", "r");

  if (file_ptr == NULL)
    return 1;

  char* string = malloc(STRING_SIZE);

  fscanf(file_ptr, "%s", string);

  fclose(file_ptr);

  // Solution
  reverse(string);
  printf("%s\n", string);

  free(string);

  return 0;
}
