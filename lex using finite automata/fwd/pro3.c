#include<stdio.h>
#include<string.h>

int e=0,i,j,flag;			//Declaration Global
char input[200],word[20],key[20];
char state='0',ch;	
FILE *fp,*fp1,*fp2,*fp3,*fp4,*fp5,*fp6,*fp7,*fp8;
char ch1;

int findstate()
{
	int k;
	rewind(fp2);	//Seting Automated File Pointer to start 
	input[0]='\0';
/*	k=0;
	ch1=fgetc(fp2);
	while(input[0]!=state&&!feof(fp2))	//For getting the relevant state
	{
		k=0;
		while(ch1!=eof()&&ch1!='\n')
		{
			input[k++]=ch1;
			ch1=fgetc(fp2);
		}
		
		//fseek(fp2,2,SEEK_CUR);
		ch1=fgetc(fp2);
	}
*/
	while(input[0]!=state&&!feof(fp2))	//For getting the relevant state
	{
		fscanf(fp2,"%[^\n]s",input);	//Reading entire automata Line
		//k=ftell(fp2);
		ch1=fgetc(fp2);
		//fseek(fp2,3,SEEK_CUR);
	}
			
	for(i=1;input[i]!='\0';i=i+2)	//To Find Next State
	{
			
		if(input[i]==ch)
		{
			state=input[i+1];
			word[j++]=ch;
			return 1;
			
		
		}
	}
	return 0;
}

int checkkeyword()
{
	rewind(fp1);
	while(!feof(fp1))
	{
		fscanf(fp1,"%[^\n]s",key);
		ch1=fgetc(fp1);
		if(strcmp(key,word)==0)
		{
			fprintf(fp4,"%s\n",word);		//Adding Keyword
			return;
		}
	}
	fprintf(fp3,"%s\n",word); 	//Adding identifier
}
void main()
{	
	char file[20];
	printf("\nEnter File Name : ");
	scanf("%s",file);
	fp=fopen(file,"r");		//Opening Input C Program
	if(fp==NULL)
	{
		e=1;
		printf("\nInput File Not present\n");
	}
	fp1=fopen("keywords.txt","r");		//Opening Keyword File to check
	if(fp1==NULL)
	{
		e=1;
		printf("\nKeyword File Not present\n");
	}
	fp2=fopen("automation.txt","r+");	//Opening Automation File
	if(fp2==NULL)
	{
		e=1;
		printf("\nAutomation File Not Present\n");
	}
	fp3=fopen("identifier.txt","w");	//For adding identifiers
	fp4=fopen("key.txt","w");		//For adding Keywords
	fp5=fopen("operators.txt","w");		//For adding Operators
	fp6=fopen("symbols.txt","w");		//For adding Symbols
	fp7=fopen("other.txt","w");		//For adding String Literals
	fp8=fopen("constants.txt","w");		//For adding constants

	if(e==0)
	{
		ch=fgetc(fp);			//Reading First Charachter
		state='0';
		j=0;
		while(ch!=EOF)
		{
			switch(state)
			{
				case '0':	flag=findstate();					
						if(flag==0) //Symbol 
						{
							state='9';
							continue;
						}
						break;

				case '1':	flag=findstate();
						if(flag==0)
						{
							word[j]='\0';
							checkkeyword();		//Check whether identifier or keyword
							j=0;
							state='0';
							continue;	
						}
						break;

				case '2': 	flag=findstate();
						if(flag==0)
						{
							word[j]='\0';
							fprintf(fp8,"%s\n",word);	//Added Constant
							j=0;
							state='0';
							continue;
						}
						
						break;

				case '3':	flag=findstate();
						if(flag==0)
						{
							word[j]='\0';
							fprintf(fp5,"%s\n",word);	//Added Operator
							j=0;
							state='0';
						}

						continue;

				case '4': 	
						word[j]='\0';
						fprintf(fp6,"%s\n",word);	//Added Symbol
						j=0;
						state='0';
						
						break;
						
				case '5':	
						word[j]='\0';
						fprintf(fp6,"%s\n",word);		//Added "
						j=0;
						ch=fgetc(fp);
						flag=findstate();
						if(flag==0)
						{
							printf("\nError Inverted commas not ended\n");	//character not recognised
						}
						break;
				case '6':
						flag=findstate();
						break;
						
				case '7':
						word[j-1]='\0';
						fprintf(fp7,"%s\n",word);		//Added the string literal
						fprintf(fp6,"\"\n",word);		//Added "
						word[0]='\0';
						j=0;
						state='0';
						continue;		
						
			//	case '8':
			//			word[j-1]='\0';
			//			j=0;
			//			state='0';
			//			checkkeyword();		//check whether identifier or keyword
			//			break;
						
				case '9':
						
						flag=findstate();
						if(flag==0)
						{
							ch=fgetc(fp);
							state='0';
							continue;
						}
						continue;
						
				
				default :
						printf("\nState does not exist\n");
						
			}
			ch=fgetc(fp);
		}

		//fcloseall();
		//To print rest
			
	}
	else
		printf("\nError\n");		//Error One of the File not opened
	fcloseall();
}
