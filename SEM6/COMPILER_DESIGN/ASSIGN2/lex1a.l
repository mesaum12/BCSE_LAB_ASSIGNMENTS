%{
   #include "lex1a.tab.h"
%}
/* Rule Section */
%%
[aA] {return A;}
[bB] {return B;}
\n {return NL;}
. {return yytext[0];}
%%
int yywrap(void)
{
return 1;
}