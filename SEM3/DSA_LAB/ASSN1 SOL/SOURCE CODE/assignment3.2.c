#include<stdio.h>
int linear_search_float(float a[],float element,int n)
{
  int i;
  for(i=0;i<n;i++)
  if(a[i]==element)return i;
  return -1;
}
int binary_search_float(float a[],float element,int n)
{
  int low=0,high=n-1,mid;
  while(low<=high)
  {
    mid=low+(high-low)/2;
    if(a[mid]==element) return mid;
    else if(a[mid]>element) high=mid-1;
    else low=mid+1;
  }
  return -1;
  
}
int main()
{
  int n,i;
  float a[100],element;
  printf("Enter the size of the array \n");
  scanf("%d",&n);
  printf("Please enter the array elements in sorted order to perform binary search \n");
  for(i=0;i<n;i++)
  {
    printf("a[%d]:",i);
    scanf("%f",&a[i]);
  }
  printf("Enter the element to be searched\n");
  scanf("%f",&element);
  if(linear_search_float(a,element,n)!=-1)
  {
    printf("The result obtained from linear search is :%d\n",linear_search_float(a,element,n));
    printf("The result obtained from binary search is :%d\n",binary_search_float(a,element,n));
  }
  else
  printf("Element not found!\n");
  return 0;
}

