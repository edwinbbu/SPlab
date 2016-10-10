%{
#include<stdio.h>
%}
reg 0(10|01)*
%%
{reg} {printf("%s is accepted",yytext);}
.* {printf("%s is not accepted",yytext);}
%%
int main()
{
printf("Enter the input string:\n");
yylex();
return 1;
} 

int yywrap()
{
printf("Error\n");
return 1;
}
