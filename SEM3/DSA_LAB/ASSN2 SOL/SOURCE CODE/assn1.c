#include<stdio.h>
#include "saurabh_poly.h"
#include<stdlib.h>
#define MAX 100
int main()
{
   poly p[MAX];//creating a polynomial array
   int choice,a,b,i;
   //providing choices to the user
   printf("1.Add two polynomials\n");
   printf("2.Subtract two polynomial\n");
   printf("3.Multiply two polynomials\n");
   printf("4.Exit the program\n");
   printf("Enter your choice\n");
   scanf("%d",&choice);
   printf("Entering the first polynomial( must enter in increasing order of exponent) ,enter the number of terms\n ");
   scanf("%d",&a);
   for(i=0;i<a;i++)//storing it as the first a terms of the polynomial
   {
       printf("Coeff[%d]:",i+1);
       scanf("%d",&p[i].coeff);
       printf("Exponent[%d]:",i+1);
       scanf("%d",&p[i].exp);
   }

   printf("Entering the second polynomial( must enter in increasing order of exponent),enter the number of terms\n ");
   scanf("%d",&b);
   for(i=a;i<a+b;i++)//storing it as the next b terms of the polynomial
   {
       printf("Coeff[%d]:",i+1-a);
       scanf("%d",&p[i].coeff);
       printf("Exponent[%d]:",i+1-a);
       scanf("%d",&p[i].exp);
   }
 

   switch(choice)
   {
       case 1:
             add_poly(p,a,b);
             printf("The new polynomial is:\n");
             for(i=a+b;p[i].exp!=-1;i++)
             {
                 printf("Coeff[%d]:%d Exp[%d]:%d\n",i-(a+b),p[i].coeff,i-(a+b),p[i].exp);
             }
             break;
       case 2:
             sub_poly(p,a,b);
             printf("The new polynomial is:\n");
             for(i=a+b;p[i].exp!=-1;i++)
             {
                 printf("Coeff[%d]:%d Exp[%d]:%d\n",i-(a+b),p[i].coeff,i-(a+b),p[i].exp);
             }
             break;
       case 3:
             multiply_poly(p,a,b);
             printf("The new polynomial is:\n");
             for(i=a+b;p[i].exp!=-1;i++)
             {
                 printf("Coeff[%d]:%d Exp[%d]:%d\n",i-(a+b),p[i].coeff,i-(a+b),p[i].exp);
             }
             break;
             
      
       case 4:exit(0);

       default:
              printf("Invalid choice\n");
   }

   return 0;
}
