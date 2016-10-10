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
	T();
	Eprime();
}

void Eprime()
{
	if(input[i]=='+')
	{
		i++;
		T();
		Eprime();
	}
}

void T()
{
	F();
	Tprime();
}

void Tprime()
{
	if(input[i]=='*')
	{
		i++;
		F();
		Tprime();
	}
}

void F()
{
	if(isalnum(input[i]))
	{
		i++;
	}
	else if(input[i]=='(')
	{
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
