//sliding window filter

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 1000
//function prototypes for the various functions
void generate_median_array(int a[],int n,int k,int output[]);
void generate_avg_array(int a[],int n,int k,int output[]);
void generate_maximum_array(int a[],int n,int k,int output[]);
void generate_minimum_array(int a[],int n,int ,int output[]);
int ret_med(int array[],int n);
int ret_avg(int array[],int n);
int ret_max(int array[],int n);
int ret_min(int array[],int n);
int main()
{
   int n,i,choice,k;
   int array[MAX];
   int output[MAX+2];
   printf("Enter the number of elements in the array\n");
   scanf("%d",&n);
   
   printf("Enter the array elements\n");
   for(i=0;i<n;i++)scanf("%d",&array[i+1]);
   array[0]=array[n+1]=0;//setting the leftmost and the rightmost of the array to be zero
   printf("Enter the window filter \n");
   scanf("%d",&k);
   if(n<k-2){printf("The window size is too large \n");exit(0);}//if the window size is 
   //to handle the situation we exit from the program
   //Else we have the follwing choices
   while(1)
   {
        printf("-----------You have the following options--------\n");
   printf("1.generate median array\n");
   printf("2.generate average array\n");
   printf("3.generate maximum array\n");
   printf("4.generate minimum array\n");
   printf("5.Exit\n");
   printf("Enter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
       case 1:
             generate_median_array(array,n,k,output);
             break;

       case 2:
             generate_avg_array(array,n,k,output);
             break;
             
       case 3:
              generate_maximum_array(array,n,k,output);
             break;
             
       case 4:
             generate_minimum_array(array,n,k,output);
             break;
       case 5:
             exit(0);
       default:
             printf("Invalid choice\n");

   }
    printf("Printing the output array\n");
    for(i=0;i<n-k+3;i++)
    printf("%d ",output[i]);
    printf("\n");
   }
  
    return 0;
}
void generate_median_array(int a[],int n,int k,int output[])
{
    int i=0,j,count=0;
    int temp[20];//let the maximum window size be below 20
     while(i<=n+k-2)
     {
        count=0;
        for(j=i;j<i+k;j++)
        {
            temp[count++]=a[j];
            
        }
       
        output[i]=ret_med(temp,k);
        i++;
     }

}
void generate_avg_array(int a[],int n,int k,int output[])
{
    int i,j;
    int temp[20];//let the maximum window size be below 20
    i=0;int count=0;
    while(i<=n+k-2)
    {
        count=0;
        for(j=i;j<i+k;j++)
        {
            temp[count]=a[j];
            count++;
        }
       
        output[i]=ret_avg(temp,k);
        i++;
    }

}
void generate_maximum_array(int a[],int n,int k,int output[])
{
     int i,j;
    int temp[20];//let the maximum window size be below 20
    i=0;int count=0;
    while(i<=n+k-2)
    {
        count=0;
        for(j=i;j<i+k;j++)
        {
            temp[count]=a[j];
            count++;
        }
       
        output[i]=ret_med(temp,k);
        i++;
    }

}
void generate_minimum_array(int a[],int n,int k,int output[])
{
     int i,j;
    int temp[20];//let the maximum window size be below 20
    i=0;int count=0;
    while(i<=n+k-2)
    {
        count=0;
        for(j=i;j<i+k;j++)
        {
            temp[count]=a[j];
            count++;
        }
       
        output[i]=ret_min(temp,k);i++;
    }

}
int ret_med(int array[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
    
        for(j=0;j<n-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    //array is sorted in this position
    //now return the middle element as the median of the array
    return array[n/2];
}
int ret_avg(int array[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
       sum+=array[i];
    }
    return sum/n;
}
int ret_max(int array[],int n)
{
    int i,max=INT_MIN;
    for(i=0;i<n;i++)
    {
       if(array[i]>max)max=array[i];
    }
    return max;
}
int ret_min(int array[],int n)
{
    int i,min=INT_MAX;
    for(i=0;i<n;i++)
    {
       if(array[i]<min)min=array[i];
    }
    return min;
}
