#include<stdio.h>
#include<math.h>

int jump(int a[], int n, int item) {
   int i = 0;
   int m = sqrt(n); //m=2
   while(a[m] <= item && m < n) 
   { 
      
      i = m;  
      m += sqrt(n); //m+=m
      if(m > n - 1)  
         return -1; 
   }

   for(int x = i; x<m; x++) 
   { 
      if(a[x] == item)
         return x;
   }
   return -1;
}
int main()
{   
    int n,location,x;
    int a[20];
    printf("input the size of array");
    scanf("%d",&n);
    printf("\nenter the elements");
    
    for(int i=0l;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nenter the element to be searched");
    scanf("%d",&x);
    location= (a,n,x);
    if(location==-1)
        printf("\nelement not found");
    else
        printf("\nelement found at location %d",location);
    return 0;
}

