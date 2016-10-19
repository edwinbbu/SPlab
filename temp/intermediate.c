#include<stdio.h>
#include<string.h>

char stack[10],stack2[10],item;
int top=-1,i,top2=-1,j;

void push(char item)
{
	if(top<9)
	{
		top++;
		stack[top]=item;
	}
}	

void push2(char item)
{
	if(top2<9)
	{
		top2++;
		stack2[top2]=item;
	}
}

void display()
{
	for(i=0;i<=top;i++)
	{
		printf("%c",stack[i]);
	}
	printf("\n");
}

void display2()
{
	for(i=top2;i>=0;i--)
	{
		printf("%c",stack2[i]);
	}
	printf("\n");
}

char tstack()
{
	return stack[top];
}

char tstack2()
{
	return stack2[top2];
}

char pop2()
{
	item=stack2[top2];
	top2--;
	return item;
}
char pop()
{
	item=stack[top];
	top--;
	return item;
}

void main()
{
	char table[10]="*/+-";
	char input[20];
	int index;
	printf("Enter the string to input:");
	scanf("%s",&input);
	for(i=0;i<(strlen(input));i++)
	{
		if(isalpha(input[i]))
		{
			push(input[i]);
		}
		else
		{
			push2(input[i]);
			if(input[i][j]>alpha[j])
			{
				
			}
		}
	}
	display();
	display2();
	char alpha,symbol;
	alpha=tstack();
	symbol=tstack2();
	printf("Alphabet top:%c\n",alpha);
	printf("Symbol top:%c\n",symbol);
}

