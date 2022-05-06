%{
#include<stdio.h>
%}
%%

A+B+ { printf("Matched pattern : %s",yytext);}
[ \n\t] {;}
[.] {printf("Error");}
[$] {return 0;}

%%
int yywrap(void)
{
return 1;
}
int main(void)
{
yylex();
return 0;
}