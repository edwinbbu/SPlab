%{
	#include"y.tab.h"
	#include<stdio.h> 
        #include<stdlib.h>
%}
%token LETTER NUM OPA AOP CPA OB CB SC SWITCH STMNT NL CASE BREAK COL SP
%%
E: SWITCH OPA LETTER CPA NL OB NL STMNT A 
 ;
A: NL STMNT A
 | NL CB { printf("Valid Statement\n");
  	   exit(0);
	}
 ;

%%
int yyerror()
{
   printf("\nSyntax error\n");	
}

main()
{
  yyparse();
}
