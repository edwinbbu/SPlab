%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
%}
%token DIGIT
%%
I:E '\n' {printf("Result:%d\n",$1);
          exit(0);}
 ;
E:E'+'T {$$=$1+$3;}
 |E'-'T {$$=$1-$3;}
 |T
 ;
T:T'*'F {$$=$1*$3;}
 |T'/'F {$$=$1/$3;}
 |F
 ;
F:'('E')'
 |DIGIT 
 ;

%%
yylex()
{
 char c;
 c=getchar();
 if(isdigit(c))
 {

  yylval=c-'0';
  return DIGIT;
 }
return c;
}
int main()
{
printf("\nEnter the input:");

yyparse();
}

yyerror()
{
 printf("Syntax error");
}
