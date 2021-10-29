#include<stdio.h>
#include<string.h>
int linear_search_word(char a[][100],char element[30],int n)
{
  int i;
  for(i=0;i<n;i++)
  if(strcmp(a[i],element)==0)return i;//using the strcmp function to compare the equality of the two strings
  return -1;
}
int binary_search_word(char a[][100],char element[30],int n)
{
  int low=0,high=n-1,mid;
  while(low<=high)
  {
    mid=low+(high-low)/2;
    if(strcmp(a[mid],element)==0) return mid;//using the strcmp() function to compare the strings for equality
    else if(strcmp(a[mid],element)>1) high=mid-1;
    else low=mid+1;
  }
  return -1;
  
}
int main()
{
  int n,i;
  char a[30][100],element[30];
  printf("Enter the size of the array \n");
  scanf("%d",&n);
  printf("Please enter the array elements in sorted order to perform binary search \n");
  for(i=0;i<n;i++)
  {
    printf("a[%d]:",i);
    scanf("%s",a[i]);
  }
  printf("Enter the element to be searched\n");
  scanf("%s",element);
  if(linear_search_word(a,element,n)!=-1)
  {
    printf("The result obtained from linear search is :%d\n",linear_search_word(a,element,n));
    printf("The result obtained from binary search is :%d\n",binary_search_word(a,element,n));
  }
  else
  printf("Element not found!\n");
  return 0;
}

