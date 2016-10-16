%{
#include<stdio.h>
%}
reg 0(10|01)*.
%%
{reg} {printf("\n%s accepted",yytext);}
.* {printf("\nInvalid");}
%%
int main()
{
  yylex();
}
