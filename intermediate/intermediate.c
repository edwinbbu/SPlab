#include<stdio.h>
#include<string.h>
#include<ctype.h>
int precedence(char A);
void main()
{

char S[100];
char I[100],tI[100];
char P[100];
int top=-1;
int i;
int j=0;
int len=0;
int ptr,ptr2,ptrc,ptr2c;
char var='A',oper[50];
char a,b,tVar[10],op,t2Var[10];
int ti=0,i1,i2,i3;
printf("Enter the expression:");
//scanf("%[^\n]",I);
scanf("%s",I);
strcpy(tI,I);

len=strlen(I);

for(i=0;i<len;i++)
{

if(isalnum(I[i]))
{
P[j]=I[i];
j++;
}

else if(I[i]=='(')
{
top++;
S[top]=I[i];
}

else if(I[i]==')')
{

while(S[top]!='(')
{

P[j]=S[top];
top--;
j++;
}

top--;


}

else
{

while(precedence(I[i])<=precedence(S[top]))
{
P[j]=S[top];
top--;
j++;
}

top++;
S[top]=I[i];
}

}

while(top!=-1)
{
P[j]=S[top];
j++;
top--;
}

P[j]='\0';

//strcpy(CP,P);

puts(P);

ptr=0;
ptr2=0;


	while(P[ptr]!='\0')
	{	
		if(isalpha(P[ptr]))
		{

			oper[ptr2++]=P[ptr++];

		}
		else
		{
			
			ptr2--;
			

			a=oper[ptr2];
			b=oper[ptr2-1];
			ptr2--;
		    op=P[ptr];
		    ptr++;
		
			printf("\n%c = %c %c %c",var,b,op,a);
			
			ti=0;
			tVar[ti++]=b;
			tVar[ti++]=op;
			tVar[ti++]=a;
			tVar[ti]='\0';
			
			for(i1=0;i1<len-2;i1++)
			{
				
			    i2=0;
				t2Var[i2++]=tI[i1];
				t2Var[i2++]=tI[i1+1];
				t2Var[i2++]=tI[i1+2];
				t2Var[i2]='\0';
					
				if(strcmp(tVar,t2Var)==0)
				{
					i3=i1;
				   //printf("\nyes");
				    tI[i3]=var;
					i3=i3+1;
					while(tI[i3+2]!='\0')
					{
					    tI[i3++]=tI[i3+1];						
					} 	
					tI[i3]='\0';
					
					break;
					
	         	}
												
			}
			printf("\t%s",tI);						
			oper[ptr2++]=var;
			var=var+1;
		}	
	}
printf("\n");

}

int precedence(char A)
{

switch(A)
{

case '(':

return 0;
break;

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



