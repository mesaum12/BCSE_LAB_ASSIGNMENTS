typedef struct 
{
   int coeff;
   int exp;
}poly;
void add_poly(poly p[],int a,int b);
void sub_poly(poly p[],int a,int b);
void multiply_poly(poly p[],int a,int b);
void add_poly(poly p[],int a,int b)//function to add the two polynomials
{
    int i=0,j=a,t=a+b;
    while(i<a && j<a+b)
    {
        if(p[i].exp==p[j].exp)
        {
            p[t].exp=p[i].exp;
            p[t].coeff=p[i].coeff+p[j].coeff;
            i++;
            j++;
            t++;
        }
        else if(p[i].exp<p[j].exp)
        {
            p[t]=p[i];
            t++;
            i++;
        }
        else
        {
            p[t]=p[j];
            t++;
            j++;
        }
        
    }
    while(i<a)
    {
         p[t]=p[i];
         t++;
         i++;
    }
     while(j<a+b)
    {
         p[t]=p[j];
         t++;
         j++;
    }
   p[t].exp=-1;//putting  a sentinel
   p[t].coeff=-1;//putting a sentinel at the end to detect the end of the sum polynomial terms
}
void sub_poly(poly p[],int a,int b)
{
    int i=0,j=a,t=a+b;
    while(i<a && j<a+b)
    {
        if(p[i].exp==p[j].exp)
        {
            p[t].exp=p[i].exp;
            p[t].coeff=p[i].coeff-p[j].coeff;
            i++;
            j++;
            t++;
        }
        else if(p[i].exp<p[j].exp)
        {
            p[t]=p[i];
            t++;
            i++;
        }
        else
        {
            p[t]=p[j];
            t++;
            j++;
        }
        
    }
    while(i<a)
    {
         p[t]=p[i];
         t++;
         i++;
    }
     while(j<a+b)
    {
         p[t]=p[j];
         t++;
         j++;
    }
   p[t].exp=-1;//putting  a sentinel
   p[t].coeff=-1;//putting a sentinel at the end to detect the end of the sum polynomial terms
}
void multiply_poly(poly p[],int a,int b)
{
    int t=a+b,i=0,j=a,flag=0,k;
    for(i=0;i<a;i++)
    {
        for(j=a;j<a+b;j++)
        {
           //each time we check the whether the prev power is generated or not 
           //if generated we add the current coefficient to that 
           flag=0;
           for(k=a+b;k<t;k++)
           {
              if((p[k].exp)==(p[i].exp+p[j].exp))
              {
                  flag=1;
                  p[k].coeff=p[k].coeff+(p[i].coeff*p[j].coeff);
                  break;
              }
           }
           if(flag==0)
           {
             p[t].coeff=(p[i].coeff*p[j].coeff);
             p[t].exp=p[i].exp+p[j].exp;
             t++;
           }
           
        }
    }
    p[t].exp=-1;
    p[t].coeff=-1;
}
