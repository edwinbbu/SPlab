#include<stdio.h>
#include<string.h>

void main()
{
	FILE *fp;
	fp=fopen("rules.txt","r");
	if(fp==NULL)
	{
		printf("Error opening file\n");
	}
	char ch;
	char matrix[50][50];
	int i=0,j=0;
	while((ch=fgetc(fp))!=EOF)
	{
	//	printf("%c",ch);
		matrix[i][j]=ch;
	//	printf("%c",matrix[i][j]);
		j++;
		if(ch=='\n')
		{
			i++;
			j=0;
		}
	}
	int ti;
	ti=i;
	for(i=0;i<ti;i++)
	{
		for(j=0;j<=6;j++)
		{
			printf("%c",matrix[i][j]);
		}
	//	printf("\n");
	}
	
	
}
