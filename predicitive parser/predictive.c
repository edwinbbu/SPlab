#include<stdio.h>
#include<string.h>

char stack[10];
int top=-1,i;

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

void display()
{
	for(i=0;i<=top;i++)
	{
		printf("%c",stack[i]);
	}
//printf("\n");
}

char tstack()
{
	return stack[top];
}

pop()
{
	top--;
}

void main()
{
	int i=0,j=0;
	char str[20];
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
scanf("%s",str);

printf("Stack\tInput\tRemark\n");
push("$E");
display();
printf("\t%s",str);
char ch,ip[2];
ch=tstack();
ip[0]=str[0];
ip[1]='\0';

//printf("\n%c",ip);
if(ch=='z')
	{
		pop();
	}
else
	{
	char rev[20],rev2[20];
	switch(ch)
		{
		case 'E':
			for(i=1;i<7;i++)
			{
				if(strcmp(matrix[0][i],ip)==0)
				{
					pop();
					
					strcpy(rev,matrix[1][i]);
					int len=strlen(rev);	
					
					int j=0;
					for(i=(len-1);i>=0;i--)
					{
						rev2[j]=rev[i];
						j++;
					}
					rev2[j]='\0';
					push(rev2);
					printf("\tE->%s\n",matrix[i][i]);
				}
			}	
			display();
			printf("\t%s",str);
			break;
		
		case 'R':
		
		case 'T':
	
		case 'Y':
	
		case 'F':
			break;		
		}
	}
	
}			

