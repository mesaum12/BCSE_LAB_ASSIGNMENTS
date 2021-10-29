#define MAX 1000
typedef struct 
{
  int row,col,value;
}element;

typedef struct
{
   element array[MAX];
}sparse_mat;
void add_sparse_mat(sparse_mat *m,int a,int b);
void multiply(sparse_mat *m,int a,int b,int rows1,int col1,int col2);
void transpose(sparse_mat *m,int a);
//void display_mat(sparse_mat m,int a,int b);
void add_sparse_mat(sparse_mat *m,int a,int b)
{
    int i=0,j=a,t=a+b;
    while(i<a && j<a+b)
    {
        if(((*m).array[i].row==(*m).array[j].row)&&((*m).array[i].col==(*m).array[j].col))
        {
            (*m).array[t]=(*m).array[i];
            (*m).array[t].value+=(*m).array[j].value;
            t++;j++;i++;
        }
        else if(((*m).array[i].row<(*m).array[j].row))
        {
            (*m).array[t]=(*m).array[i];
            i++;
            t++;
        }
        else if(((*m).array[i].row>(*m).array[j].row))
        {
             (*m).array[t]=(*m).array[j];
            j++;
            t++;
        }
        else if(((*m).array[i].col<(*m).array[j].col))
        {
            (*m).array[t]=(*m).array[i];
            i++;
            t++;
        }
        else
        {
             (*m).array[t]=(*m).array[j];
            j++;
            t++;
        }
        
    }
       while(i<a)
        {
            (*m).array[t]=(*m).array[i];
            i++;
            t++;
        }
         while(j<a+b)
        {
            (*m).array[t]=(*m).array[j];
            j++;
            t++;
        }
    (*m).array[t].row=(*m).array[t].col=-1;//SENTINEL placing at the end
    (*m).array[t].value=-1;
}
void multiply(sparse_mat *m,int a,int b,int rows1,int col1,int col2)
{
       int i=0,j=a,t=a+b,flag=0;
       int k;
       for(i=0;i<a;i++)
       {
           for(j=a;j<a+b;j++)
           {
               flag=0;
               if(((*m).array[i].col)==((*m).array[j].row))
               {
                    for(k=a+b;k<t;k++)
                    {
                       if(((*m).array[k].row==(*m).array[i].row )&& ((*m).array[k].col==(*m).array[j].col))
                       {
                         (*m).array[k].value+=((*m).array[i].value * (*m).array[j].value);
                         flag=1;
                         break;
                        }
                    }
                    if(flag==0)
                    {
                        (*m).array[t].row=(*m).array[i].row;
                       (*m).array[t].col=(*m).array[j].col;
                       (*m).array[t].value=((*m).array[i].value * (*m).array[j].value);
                       t++;
                    }
               }
               
             }
       }
       (*m).array[t].row=(*m).array[t].col=(*m).array[t].value=-1;//setting the sentinal to identify the end of the matrix
}
void transpose(sparse_mat *m,int a )
{
      int i=0;
      for(i=0;i<a;i++)//swapping the values of the matrix 
      {
          int temp=(*m).array[i].row;
          (*m).array[i].row=(*m).array[i].col;
          (*m).array[i].col=temp;
      }
}
