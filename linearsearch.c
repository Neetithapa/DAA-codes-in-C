#include <stdio.h>

 //linear search function
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver's code
int main(void)
{
    int arr[10];
    int n,x;
    printf("enter size");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("enter element to search");
    scanf("%d",&x);
    
 
    // Function call
    int result = search(arr, n, x);
    if(result == -1)
         printf("Element is not present in array");
         printf("Element is present at index %d", result);
    return 0;
}