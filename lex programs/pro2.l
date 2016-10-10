%{
#include<stdio.h>
#include<string.h>
%}
keywords void|main|return|if|else|for|while|int|char|float|double|printf|scanf|break|case|switch|do

identifiers [a-zA-Z0-9]

symbols ";"|"{"|"}"|"<"|">"|"#"|"("|")"|","

operators "!"|"%"|"+"|"*"|"-"|"/"|"="
space " "

%%
(#include<.*>) {printf("%s is a headerfile\n",yytext);}
{keywords}  {printf("%s is a keyword\n",yytext);}
{space} {}
(\"%.\") {printf("%s is an argument\n",yytext);}
(&.) {printf("%s is others\n",yytext);}
(\".*\") {printf("%s is a string\n",yytext);}

{identifiers}*  {printf("%s is an identifier\n",yytext);}
{symbols}  {printf("%s is a symbol\n",yytext);}
{operators}  {printf("%s is a operator\n",yytext);}
%%
int main()
{
FILE *fp;
fp=fopen("input.c","r");
yyin=fp;
yylex();
return 1;
}

int yywrap()
{
//printf("Error\n");
return 1;
}

