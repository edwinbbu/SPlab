#include<stdio.h>
#include<string.h>

void main()
{
char symbol[20]=",;(){}[]<>&\"",operator[20]="!%+*-/?.=";
char keywords[30][20];
char ch,str[120],str2[100],temp[120];
int state=0;
FILE *fp,*fp2;
int i=0,j=0,m,n;
int flag,oflag,sflag;
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
fp=fopen("input.c","r");
if(fp==NULL)
	{
	printf("Error opening file\n");
	}
str[0]='\0';
i=0;
while((ch=fgetc(fp))!=EOF)
{
	if(ch=='#')
	{
		fscanf(fp,"%[^\n]s",temp);
		printf("#%s is a header line\n",temp);
	}
	else if(isalpha(ch))		//alphabet intermediate state		
	{
		str[i]=ch;
		i++;
		state=1;
	}
	else if(isdigit(ch))
	{
		if(state==1)
		{
			str[i]=ch;
			i++;
			state=1;	
		}
		else	//constant intermediate state
		{
			state=8;
			str2[i]=ch;
			i++;
		}
		
	}
	else if(ch==' ')
	{
		if(state==1)
		{
		str[i]='\0';
			for(j=0;j<n;j++)
			{
				if(strcmp(str,keywords[j])==0)		//final state keyword
				{
					printf("%s is a keyword\n",str);
					str[0]='\0';
					i=0;
					state=2;
				}
			}
		}
		
	}
	else
	{
		if(state==8)
		{
			str2[i]='\0';
			state=3;
			printf("%s is a constant\n",str2);
		}
		str[i]='\0';
		if(str[0]!='\0')
			{
				flag=0;
				for(m=0;m<n;m++)
				{	
					if(strcmp(str,keywords[m])==0)		//final state keyword
					{
						printf("%s is a keyword\n",str);
						flag=1;	
						state=2;	
					}
				}
				if(flag==0)
				{
					printf("%s is an identifier\n",str);	
					state=4;					
				}		
			}		
		for(j=0;j<20;j++)			//final state symbol
		{
			if(ch==symbol[j])
			{
				printf("%c is a symbol\n",ch);
				state=5;
			}
		}
		
		for(i=0;i<20;i++)			//final state operator
		{
			if(ch==operator[i])
			{
				printf("%c is a operator\n",ch);
				state=6;	
			}
		}	
		str[0]='\0';
		i=0;
	}	
}	
}
