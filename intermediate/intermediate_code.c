#include<stdio.h>
#include<stdlib.h>

struct operators
{
	char op;
	int precedence;
}op_pre[20];

int top=-1,t=-1,indx=0;
char op_stck[20],oper_stck[20];
char temp[10]={'A','B','C','D','E'};

int check(char operator);
void push_oper(char operand);
char pop_op();
char pop_oper();

void push_op(char operator)
{
	int f,i,j,k;
	char c,s,a,b,r;
	f=check(operator);
	if(top==100)
	{
		printf("Operator stack overloaded!");
		exit(0);
	}
	if(f==1)
	{
		//stack top contains higher precedence element
		c=pop_op();
		b=pop_oper();
		a=pop_oper();
		printf("%c=%c%c%c\n",temp[indx],a,c,b);
		push_oper(temp[indx]);
		top++;
		indx++;
	}
	else
		top++;
	op_stck[top]=operator;
	//printf("\n\nPushed operator is: %c     %c\n",op_stck[top],operator);
}
char pop_op()
{
	if(top==-1)
	{
		printf("\nOperator stack underflow!\n");
		exit(0);
	}
	char o=op_stck[top];
	top--;
	return o;
}
void push_oper(char operand)
{
	if(t==100)
	{
		printf("Operand stack overflow!\n");
		exit(0);
	}
	t++;
	oper_stck[t]=operand;
}
char pop_oper()
{
	if(t==-1)
	{
	//	printf("Operand stack underflow!\n");
		exit(0);
	}
	char op=oper_stck[t];
	t--;
	return op;
}
int find(char test)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(op_pre[i].op==test)
			return op_pre[i].precedence;
	}
}
int check(char operator)
{
	if(top==-1)
		return 0;
	int p1,p2;
	//p1 is the operator
	//p2 is the stack top

	p1=find(operator);
	p2=find(op_stck[top]);
	
	if(p1<=p2)
		return 1;
	else
		return 0;
}
main()
{
char expr[30];
int in=0,j;

op_pre[0].op='*';
op_pre[0].precedence=0;

op_pre[1].op='/';
op_pre[1].precedence=0;

op_pre[2].op='+';
op_pre[2].precedence=1;

op_pre[3].op='-';
op_pre[3].precedence=1;

printf("\nEnter the expression: \n");
scanf("%s",expr);

printf("\nThe intermediate code is: \n____________________________________________\n\n");

while(expr[in]!='\0')
{

	if(isalpha(expr[in]))
	{
	//	printf("%c",expr[in]);
		push_oper(expr[in]);
	}
	else
	{
	//	printf("%c",expr[in]);
		push_op(expr[in]);
	}
	in++;
}
int a,b,c;
if(expr[in]=='\0'&&top!=-1)
{
	while(top!=-1)
	{
		c=pop_op();
		b=pop_oper();
		a=pop_oper();
		printf("%c=%c%c%c\n",temp[indx],a,c,b);
		push_oper(temp[indx]);
		indx++;
	}
	
}
printf("\n________________________________________________________________\n");
}




	

	
	


	
			
		




