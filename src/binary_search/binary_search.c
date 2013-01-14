#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TARGET 12
#define avg(num1, num2) ((num1 + num2) / 2)

// Takes an array of integers, the length of the array and the target integer
// Returns the position of the target integer if found
// Returns -1 otherwise
int binary_search(int* data, int length, int target)
{
  int left_bound = 0;
  int right_bound = length - 1;
  int midpoint = avg(left_bound, right_bound);

  while (data[midpoint] != target)
  {
    midpoint = avg(left_bound, right_bound);

    if (left_bound > right_bound)
      return -1;
    
    if (data[midpoint] > target)
      right_bound = midpoint - 1;
    else if (data[midpoint] < target)
      left_bound = midpoint + 1;
  }

  return midpoint;
}

int main()
{
  // SETUP: Store data in array
  FILE* file_ptr = fopen("numbers.txt", "r");
  int length;

  if (file_ptr == NULL)
  {
    printf("Run make generate...\n");
    return 1;
  }

  fscanf(file_ptr, "%d", &length);

  int* data = malloc(sizeof(int) * length);

  size_t i;
  for(i = 0; i < length; ++i)
    fscanf(file_ptr, "%d", &data[i]);

  fclose(file_ptr);

  // SOLUTION
  int index = binary_search(data, length, TARGET);

  if (index == -1)
  {
    printf("Target %d not found", TARGET); 
    return 1;
  }

  // left bound
  int left_bound = index;
  int times = 1;
  
  while (data[left_bound] == TARGET)
  {
    int new_bound = left_bound - pow(2, times);
  
    if (new_bound < 0)
    {
      left_bound = 0;
      break;
    }

    left_bound = new_bound;
    ++times;
  }

  while (data[left_bound] != TARGET)
    ++left_bound;

  // right bound
  int right_bound = index;
  times = 1;

  while (data[right_bound] == TARGET)
  {
    int new_bound = right_bound + pow(2, times);

    if (new_bound > (length - 1))
    {
      right_bound = length - 1;
      break;
    }

    right_bound = new_bound;
    ++times;
  }

  while (data[right_bound] != TARGET)
    --right_bound;

  free(data);

  printf("%d was found %d times\n", TARGET, right_bound - left_bound + 1);


  return 0;
}
