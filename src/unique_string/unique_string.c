#include <stdio.h>
#include <stdlib.h>

int main()
{
  // Read string in from file
  FILE* file_ptr = fopen("test.txt", "r");

  if (file_ptr == NULL)
    return 1;

  char* string = (char*) malloc(256);

  fscanf(file_ptr, "%s", string);

  // Solution

  int ascii_table[256];
  int length = sprintf(string, "%s", string);

  size_t i;
  for (i = 0; i < length; ++i)
  {
    int value = (int) string[i];
    
    if (ascii_table[value] == 1)
    {
      printf("String %s doesn't have unique characters\n", string);
      return 1;
    }
    else
    {
      ascii_table[value] = 1;
    }
  }

  printf("String %s has unique characters\n", string);
  return 0;
}
