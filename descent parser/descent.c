#include<stdio.h>
#include<string.h>

/*
E -> TE'
E' -> +TE' | e
T -> FT'
T' -> *FT' | e
F -> (E) | id
*/

char input[20];
int i,error;

void E();
void T();
void Eprime();
void Tprime();
void F();

void main()
{
	i=0;
	error=0;
	printf("Enter the input:");
	scanf("%s",input);
	E();
	if(strlen(input)==i && error==0)
	{
		printf("String is accepted\n");
	}
	else
	{
		printf("String is rejected\n");
	}
}

void E()
{
	printf("E->TE'\n");
	T();
	Eprime();
}

void Eprime()
{
	
	if(input[i]=='+')
	{
		printf("E'->+TE'\n");
		i++;
		T();
		Eprime();
	}
}

void T()
{
	printf("T->FT'\n");
	F();
	Tprime();
}

void Tprime()
{
	
	if(input[i]=='*')
	{
		printf("T'->*FT'\n");
		i++;
		F();
		Tprime();
	}
}

void F()
{
	if(isalnum(input[
		printf("F->id\n");
		i++;
	}
	else if(input[i]=='(')
	{
		printf("F->(E)\n");
		i++;
		E();
		if(input[i]==')')
		{
			i++;
		}
		else
		{
			error=1;
		}
	}
	else
	{
		error=1;
	}
}
