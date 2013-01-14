#include <stdio.h>
#include <stdlib.h>

void reverse(char* string)
{
  char* back = string;
  char tmp;

  while(*back)
    ++back;

  // Move from the null terminator
  --back;

  while (string < back)
  {
    char tmp = *string;
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

  char* string = malloc(256);

  fscanf(file_ptr, "%s", string);

  // Solution
  reverse(string);
  printf("%s\n", string);

  return 0;
}
