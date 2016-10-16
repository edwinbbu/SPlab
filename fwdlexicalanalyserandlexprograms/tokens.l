%{
#include<stdio.h>
%}
header #include"<".*">"
keyword int|float|char|double|switch|if|then|else|void
digit [0-9]
operator "*"|"-"|"+"|"/"|"="
slcomm "//".*
mlcomm "/*"(.|\n)*"*/"
seperators ","|";"
letter [a-zA-Z]
relop ">"|"<"|"<="|">="|"=="|"!="
identifiers {letter}({letter}|{digit})*|_+({letter}|{digit})*
brackets "{"|"}"|"("|")"|"["|"]"
%%
{header} {printf("\n%s is a header file",yytext);}
{keyword} {printf("\n%s is a keyword",yytext);}
{operator} {printf("\n%s is an arithmetic operator",yytext);}
{slcomm} {printf("\n%s is a single line comment",yytext);}
{mlcomm} {printf("\n%s is a multi line comment",yytext);}
{seperators} {printf("\n%s is a separator",yytext);} 
{identifiers} {printf("\n%s is a an identifier",yytext);}
{brackets} {printf("\n%s is a bracket",yytext);}
{relop} {printf("\n %s is a relational operator",yytext);}
{digit}* {printf("\n%s is a number",yytext);}
%%
int main()
{
     FILE *fp = fopen("ques2.c","r");
     yyin=fp;
     yylex();
}
