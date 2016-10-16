#include<stdio.h>
#include<string.h>
/*
state 0 input
state 1 intermediate state
state 2 final state keywords
state 3 final state identifiers
state 4 final state symbols
state 5 final state operators 
*/
void main()
{
char symbol[20]=",;(){}[]<>&\"",operator[20]="!%+*-/?.=";
char keywords[30][20];
char ch,str[120],temp[120];
int state;
char table[10][10][20];

FILE *fp,*fp2,*fp3;
int i=0,j=0,m,n;
int flag,oflag,sflag;
fp3=fopen("states.txt","r");
if(fp3==NULL)
	{	
		printf("Error opening file\n");
	}
int k=0;
for(i=0;i<7;i++)
{
	for(j=0;j<7;j++)
	{
		fscanf(fp3,"%s",str);
		strcpy(table[i][j],str);
		printf("%s\t",table[i][j]);
	}
	printf("\n");
}
fp2=fopen("keywords.txt","r");
if(fp2==NULL)
	{	
		printf("Error opening file\n");
	}	
n=0;
while(fscanf(fp2,"%s",str)!=EOF)
	{
		strcpy(keywords[i],str);
		n++;
		i++;
	}
fp=fopen("inp.c","r");
if(fp==NULL)
	{
	printf("Error opening file\n");
	}
str[0]='\0';
i=0;
strcpy(state,table[1][0]);
while((ch=fgetc(fp))!=EOF)
{
	if(ch=='#')
	{
		fscanf(fp,"%[^\n]s",temp);
		printf("#%s is a header line\n",temp);
	}
	else if(isalpha(ch))				//state 1
	{
		str[i]=ch;
		i++;
		state=1;
	}
	else if(isdigit(ch))
	{
		printf("%c is a constant\n",ch);
	}
	else if(ch==' ')
	{
		str[i]='\0';
		for(j=0;j<n;j++)
		{
			if(strcmp(str,keywords[j])==0)		//state 2 final state keyword
			{
				printf("%s is a keyword\n",str);
				str[0]='\0';
				i=0;
			}
		}
	}
	else
	{
		
		str[i]='\0';
		//		printf("%s ",str);
		if(str[0]!='\0')
			{
			//	printf("Hello");
				flag=0;
				for(m=0;m<n;m++)
				{	
					if(strcmp(str,keywords[m])==0)		//state 2 final state keyword
					{
						printf("%s is a keyword\n",str);
						flag=1;		
					}
				}
				if(flag==0)
				{
					printf("%s is an identifier\n",str);						
				}		
			}		
		for(j=0;j<20;j++)			//final state symbol state 4
		{
			if(ch==symbol[j])
			{
				printf("%c is a symbol\n",ch);
			}
		}
		
		for(i=0;i<20;i++)			//final state operator state 5
		{
			if(ch==operator[i])
			{
				printf("%c is a operator\n",ch);
				state=0;	
			}
		}	
		str[0]='\0';
		i=0;
	}	
}	
}
