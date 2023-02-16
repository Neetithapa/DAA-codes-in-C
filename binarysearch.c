#include <stdio.h>

int binarySearch(int array[], int x, int low, int high) 
{
  
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int array[10];
  int n;
  printf("enter size of array \n");
  scanf("%d",&n);
  printf("enter the elements\n");
  for(int i=0;i<n;i++)
  {
      scanf("%d",&array[i]);
  }
  int x;
  printf("enter the key \n");
  scanf("%d",&x);
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}

