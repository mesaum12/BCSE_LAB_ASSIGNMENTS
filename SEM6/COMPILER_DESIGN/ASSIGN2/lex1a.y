%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B NL
%%
stmt: S NL { printf("Valid String \n"); exit(0); }
;
S: a b|
;
a: A a | A;
b: b B | B;
%%
int yyerror(char *msg)
{
    printf("It is an invalid string\n");
    exit(0);
}
int main()
{
    yyparse();
    return 0;
}
