#include<stdio.h>
#include<string.h>

char stack[10],stack2[10],item;
int top=-1,i,top2=-1,j;

int precedence(char ch)
{
	switch(ch)
	{
		case '+':
			return 1;
			break;
		case '-':
			return 1;
			break;
		case '*':
			return 2;
			break;
		case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
	}
}
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
	for(i=0;i<=top;i++)
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
	char temp[10]={'A','B','C','D','E','F'};
	int index,m=0;
	char var1,var2,op;
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
			if(precedence(input[i])<precedence(tstack2()))
			{
				var1=pop();
				op=pop2();
				var2=pop();
				printf("%c=%c%c%c\n",temp[m],var2,op,var1);
				push(temp[m]);
				m++;
			}
			push2(input[i]);	
				
		}
	}
	printf("\t\tStack alphabet:");
	display();
	printf("\t\tStack operator:");
	display2();
	while(top2>=0)
	{
		var1=pop();
		op=pop2();
		var2=pop();
		printf("%c=%c%c%c\n",temp[m],var2,op,var1);
		push(temp[m]);
		m++;
		printf("\t\tStack alphabet:");
		display();
		printf("\t\tStack operator:");
		display2();
	}

}

