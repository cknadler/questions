#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STRING_SIZE 256

bool anagram(char* string1, char* string2)
{
  int length = strlen(string1);

  if (length != strlen(string2))
    return false;

  int ascii_table[256];
  memset(ascii_table, 0, sizeof(ascii_table));

  // Add values from the first string to the ascii table
  int i; 
  for (i = 0; i < length; ++i)
    ++ascii_table[string1[i]];

  // Subtract values from the second string
  for (i = 0; i < length; ++i)
  {
    --ascii_table[string2[i]];
    
    if (ascii_table[string2[i]] < 0)
      return false;
  }

  return true;
}

int main()
{
  // Setup, read strings from a file
  FILE* file_ptr = fopen("test.txt", "r");

  if (file_ptr == NULL)
    return 1;

  char* string1 = malloc(MAX_STRING_SIZE);
  char* string2 = malloc(MAX_STRING_SIZE);

  fscanf(file_ptr, "%s", string1);
  fscanf(file_ptr, "%s", string2);

  fclose(file_ptr);

  // Solution

  if (anagram(string1, string2))
    printf("%s is an anagram of %s\n", string1, string2);
  else
    printf("%s is not an anagram of %s\n", string1, string2);

  free(string1);
  free(string2);
  
  return 0;
}
