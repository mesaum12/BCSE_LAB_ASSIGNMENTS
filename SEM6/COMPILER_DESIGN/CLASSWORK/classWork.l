
%option noyywrap
%{
  #include<stdio.h>
  int col_number=0;
  int id_count=0,num=0,operator_cnt=0,sep_cnt=0,keyword_cnt=0,rel_op_cnt=0;
%}
%%
\$ {return 0;}
for {id_count++;col_number++;printf("%s is identifier in column %d\n",yytext,col_number);}
"++"|"--"|"=" {operator_cnt++;col_number++;printf("%s is operator in column %d\n",yytext,col_number);}
[() ;] {sep_cnt++;col_number++;printf("%s is separator in column %d\n",yytext,col_number);}
int {keyword_cnt++;col_number++;printf("%s is keyword in column %d\n",yytext,col_number);}
[a-z][a-zA-Z0-9]* {id_count++;col_number++;printf("%s is identifier in column %d\n",yytext,col_number);}
"<"|">"|">="|"<="|"=="|"!=" {rel_op_cnt++;col_number++;printf("%s is relational operator in column %d\n",yytext,col_number);}
[0-9]+ {num++;col_number++;printf("%s is number in column %d\n",yytext,col_number);}
%%

int main()
{
 printf("Enter the for loop structure:");
 yylex(); 
 printf("\n\n");
 printf("Keywords: %d\nIdentifiers: %d\nNumbers: %d\nOperators: %d\nSeparator: %d\nRelational Operator: %d\n",keyword_cnt,id_count,num,operator_cnt,sep_cnt,rel_op_cnt);
 return 0;
}
