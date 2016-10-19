%{
	#include"y.tab.h"
%}
tab	"\t"
nl	"\n"
num	[0-9]
letter	[a-z]
case	"case"
col	":"
sp	" "
break	"break"
opa	"("
cpa	")"
ob	"{"
cb	"}"
aop	"="
sc	";"
stmt	{case}{sp}{num}{col}{sp}{letter}{aop}({num}|{letter}){sc}{nl}({break}{sc})?
%%
switch		{return SWITCH;}
{case}		{return CASE;}
{break}		{return BREAK;}
{col}		{return COL;}
{nl}		{return NL;}
{sp}		{return SP;}
{letter}	{return LETTER;}
{num}		{return NUM;}
{opa}		{return OPA;}
{cpa}		{return CPA;}
{ob}		{return OB;}
{cb}		{return CB;}
{aop}		{return AOP;}
{stmt}		{return STMNT;}
{sc}		{return SC;}

%%
int yywrap()
{}
