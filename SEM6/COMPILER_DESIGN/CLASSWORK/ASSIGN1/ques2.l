/*

Problem Statement :
Write a lex file to count the number of lines,words and characters in the input 

*/
%option noyywrap
%{
#include<stdio.h>
int integer_count=0,floating_point_count=0;
%}
/*regular expression for identifying the integers and floating points */
digit [0-9]
sign [+-]
integer {sign}?{digit}+
float_value {sign}?(({digit}+[.]?{digit}*)|[.]?{digit}+)
%%
\$        {return 0;} /*on pressing '$' symbol it exits */
{integer} {++integer_count;} /*increments if integer */
{float_value}        {floating_point_count++;} /*encounters a float , increments */
.|\n ;   /*consider dot as a character */
%%
/*the functions are written here*/
int main()
{
  printf("Enter the statements which is to be analysed: \n");
  yylex();
  printf("Number of integers:%d \nNumber of floating point:%d \n",integer_count,floating_point_count);
  return 0;
}
