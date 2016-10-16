#include<stdio.h>
#include<string.h>

FILE *fp1;
char c[10],c1[10];
char symbol[][5]={{"#"},{"("},{")"},{"{"},{";"},{","},{"\""},{"&"},{"}"},{" "}};
char oper[][5]={{"+"},{"="},{"/"},{"-"},{"*"},{"<"},{">"}};
char letter[][5]={{"."},{"a"},{"b"},{"c"},{"d"},{"e"},{"f"},{"g"},{"h"},{"i"},{"j"},{"k"},{"l"},{"m"},{"n"},{"o"},{"p"},{"q"},{"r"},{"s"},{"t"},{"u"},{"v"},{"w"},{"x"},{"y"},{"z"}};
char constant[][5]={{"0"},{"1"},{"2"},{"3"},{"4"},{"5"},{"6"},{"7"},{"8"},{"9"}};
char keyword[][15]={{"include"},{"stdio.h"},{"main"},{"int"},{"float"},{"char"},{"printf"},{"scanf"}};
char other[5]="%";
char skeyword[100][15],ssymbol[100][15],soperator[100][15],sconstant[100][15],sother[100][15],sidentifier[100][15];
int i,j,f,k,ke=0,op=0,sy=0,co=0,ot=0,id=0,state=0;
int m[6][6]={{0,1,2,3,5,6},{1,1,0,0,0,0},{2,0,2,0,0,0},{3,0,0,3,3,0},{5,0,0,0,5,0},{6,0,0,6,0,0}};

int remove_duplicate(char str[100][15],int size)
{
	for(i=0;i<size-1;i++)
    {
		for(j=i+1;j<size;j++)
	    {
			if(strcmp(str[i],str[j])==0)
	        {
				for(k=j+1;k<size;k++)
	            {
					strcpy(str[k-1],str[k]);
	            }
	            size--;
	            j--;
	        }
		}
	}

	return size;
}



int matrix(int s)
{
	for(i=0;i<6;i++)
    {
		if(s==m[i][0])
		{
			for(j=0;j<10;j++)
			{
				if(strcmp(symbol[j],c)==0)
				{
					return(m[i][1]);
				}
			}

			for(j=0;j<7;j++)
			{
				if(strcmp(oper[j],c)==0)
				{
					return(m[i][2]);
				}
			}
			if(s==6)
			{
				if(strcmp("d",c)==0)
				{
					return(m[i][3]);
				}
			else
			{
				return 0;
			}
	    }
	    else
	    for(j=0;j<27;j++)
	    {
				if(strcmp(letter[j],c)==0)
				{
					return(m[i][3]);

				}
			}
			for(j=0;j<10;j++)
			{
				if(strcmp(constant[j],c)==0)
				{
					return(m[i][4]);
				}
			}
			if(strcmp(other,c)==0)
			{
				return(m[i][5]);
			}

		}
    }
}




void main()
{
	fp1=fopen("input.txt","r");
	c[0]=fgetc(fp1);
	if(c[0]=='\n')
	    c[0]=fgetc(fp1);
	c[1]='\0';
    //fscanf(fp1,"%1s",c);
    while(c[0]!=EOF)
    {
		state=matrix(state);
	    if(state==0)
		state=matrix(state);
	    if(state==1)
	    {
			strcpy(ssymbol[sy],c);

			sy++;
			c[0]=fgetc(fp1);
			if(c[0]=='\n')
		    c[0]=fgetc(fp1);
			c[1]='\0';

	    }
	    else if(state==2)
	    {
			strcpy(soperator[op],c);
			op++;
			c[0]=fgetc(fp1);
			if(c[0]=='\n')
				c[0]=fgetc(fp1);
			c[1]='\0';
	    }
	    else if(state==3)
	    {
			do
			{
				strcat(c1,c);
			    //fscanf(fp1,"%1s",c);
				c[0]=fgetc(fp1);
				if(c[0]=='\n')
					c[0]=fgetc(fp1);
				c[1]='\0';

				if(c[0]==EOF)
					break;
				state=matrix(state);

			}while(state==3);
			f=0;
			for(i=0;i<8;i++)
			{
				if(strcmp(c1,keyword[i])==0)
				{
					f=1;
					strcpy(skeyword[ke],c1);
					ke++;
					break;
				}
			}
			if(f==0)
			{
				f=1;
				strcpy(sidentifier[id],c1);
				id++;
			}
			if(f==1)
				strcpy(c1,"");
	    }
	    else if(state==5)
	    {
			strcpy(sconstant[co],c);
			co++;
			c[0]=fgetc(fp1);
			if(c[0]=='\n')
		    c[0]=fgetc(fp1);
			c[1]='\0';
		}
		else if(state==6)
		{
			do
			{
				strcat(c1,c);
				c[0]=fgetc(fp1);
			    if(c[0]=='\n')
					c[0]=fgetc(fp1);
				c[1]='\0';
				state=matrix(state);
			}while(state==6);
			strcpy(sother[ot],c1);
			strcpy(c1,"");
			ot++;
		}
    }

    fclose(fp1);
	
    printf("\n");
    printf("**IDENTIFIERS**\n\n");
    id=remove_duplicate(sidentifier,id);
	for(i=0;i<id;i++)
		printf("%s \n",sidentifier[i]);
	
	printf("\n") ;

    printf("**OPERATORS**\n\n");
	op=remove_duplicate(soperator,op);
    for(i=0;i<op;i++)
		printf("%s\n ",soperator[i]);
	
	printf("\n");

	printf("**KEYWORDS**\n\n");
	ke=remove_duplicate(skeyword,ke);
	for(i=0;i<ke;i++)
		printf("%s \n",skeyword[i]);
	
	printf("\n") ;

	printf("**CONSTANTS**\n\n");
	co=remove_duplicate(sconstant,co);
	for(i=0;i<co;i++)
		printf("%s\n ",sconstant[i]);
	
	printf("\n") ;


        printf("\n**SYMBOLS**\n\n");
	sy=remove_duplicate(ssymbol,sy);
	for(i=0;i<sy;i++)
		printf("%s \n",ssymbol[i]);

        printf("\n") ;

	//printf("**OTHERS**\n");
	//for(i=0;i<ot;i++)
       // {
              // if((sother[i]!=" ")||(sother[i]!="\n"))
		//printf("%s\n",sother[i]);
       // }
	//printf("\n") ;
	
}




   
   
  
    
  
  	
 

