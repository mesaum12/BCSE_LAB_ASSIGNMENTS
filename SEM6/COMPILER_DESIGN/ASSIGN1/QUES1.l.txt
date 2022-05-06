/*

Problem Statement :
Write a lex file to count the number of lines,words and characters in the input 

*/
%option noyywrap
%{
#include<stdio.h>
int character_count=0,line_count=0,word_count=0;
%}
/*regular expression for identifying letter */
letter [^ \t\n\r ]
%%
\$        {return 0;} /*on pressing '$' symbol it exits */
{letter}+ {word_count++; character_count+=yyleng;} /*increments word on one or more */
\n        {line_count++;character_count++;} /*encounters a new line , increments */
.         character_count++;   /*consider dot as a character */
%%
/*the functions are written here*/
int main()
{
  printf("Enter the statements which is to be analysed: \n");
  yylex();
  printf("Number of words:%d \nNumber of lines:%d \nNumber of characters:%d\n",word_count,line_count,character_count);
  return 0;
}