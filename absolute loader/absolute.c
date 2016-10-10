#include<stdio.h>
#include<string.h>
void main()
{
	char temp[200],ch;
	FILE *fp1;
	int start,length,address;
	char pg[10],len[20];
	fp1=fopen("input.txt","r");
	fscanf(fp1,"%s",&ch);
	fscanf(fp1,"Program Name:%s\nStarting Address:%x\nTotal Length:%x\n",pg,start,length);
	fscanf(fp1,"%1s",&ch);
	while(ch!='E')
	{
		fscanf(fp1,"%6x",&address);
		fscanf(fp1,"%2x",&length);
		while(length>0)
		{
			fscanf(fp1,"%2s",temp);
			printf("%6x\t%2s\n",address,temp);
			length--;
			address++;
		}
		fscanf(fp1,"%1s",&ch);
	}
	printf("COMPLETED\n");
	fclose(fp1);
}
