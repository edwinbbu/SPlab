#include<stdio.h>
#include<string.h>

char stack[10],stack2[10];
int top=-1,i,top2=-1,j;

void push(char k[])
{
	for(i=0;k[i]!='\0';i++)
	{
		if(top<9)
		{
			top++;
			stack[top]=k[i];
		}
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
//printf("\n");
}

void display2()
{
	for(i=top2;i>=0;i--)
	{
		printf("%c",stack2[i]);
	}
}

char tstack()
{
	return stack[top];
}

char tstack2()
{
	return stack2[top2];
}

pop2()
{
	top2--;
}
pop()
{
	top--;
}

void main()
{
	int i=0,j=0;
	char str[20],input[20];
	char matrix[6][7][10]={
			"Non-Ter","i","+","*","(",")","$",
			"E","TR","-","-","TR","-","-",
			"R","-","+TR","-","-","e","e",
			"T","FY","-","-","FY","-","-",
			"Y","-","e","*FY","-","e","e",
			"F","i","-","-","(E)","-","-"
			};
	printf("Parsing Table\n");
	for(i=0;i<6;i++)
	{
		for(j=0;j<7;j++)
		{
			printf("%s\t",matrix[i][j]);
		}
		printf("\n");
	}
printf("Enter any string(Append with $):");
scanf("%s",input);
int len=strlen(input);
for(i=(len-1);i>=0;i--)
{
	push2(input[i]);
}
printf("Stack\tInput\tRemark\n");
push("$E");
display();
printf("\t");
display2();
//printf("\n%c",tstack());
//printf("\n%c",tstack2());
char ch,ip,ip2[2];
X:
ch=tstack();
ip=tstack2();
ip2[0]=tstack2();
ip2[1]='\0';
char rev[20];
if(ch=='$' && ip=='$')
{
	printf("\nString Accepted\n");
	return;
}

if(ch=='e')
{
	pop();
	goto X;
}
if(ch==ip)
{
	pop();
	pop2();
	printf("\tReduce\n");
	display();
	printf("\t");
	display2();
	goto X;
}
int t=0;
int m;
switch(ch)
	{
		case 'E':
			t=1;
			break;
		case 'R':
			t=2;
			break;
		case 'T':
			t=3;
			break;
		case 'Y':
			t=4;
			break;
		case 'F':
			t=5;
			break;	
	}
		for(m=1;m<7;m++)
			{
				if(strcmp(matrix[0][m],ip2)==0)
				{
					printf("\t%c->%s\n",ch,matrix[t][m]);
					pop();
					strcpy(str,matrix[t][m]);
					if(strcmp(str,"-")==0)
					{
						printf("\nString Rejected\n");
						return;
					}
					len=strlen(str);	
					int j=0;
					for(i=(len-1);i>=0;i--)
					{
						rev[j]=str[i];
						j++;
					}
					rev[j]='\0';
					push(rev);
					display();
					printf("\t");
					display2();
					
				}
			}	

goto X;
}			

















