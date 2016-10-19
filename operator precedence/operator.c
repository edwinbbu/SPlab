#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char ter[100];
char table[100][100],step2[100],step3[100],step4[100];
int len,row,col,n1len;

int sindex(char a)
{
	int i;
	if(isalpha(a))
	 a='i';
	for(i=0;i<len;i++)
	{
		if(ter[i]==a)
		 return i;
	}	
	return -1;	
}
int isoper(char a)
{
	if(a=='-'||a=='+'||a=='*'||a=='/')
	{
		return 1;
	}
	return -1;
}

int main()
{
	
	FILE *fp;
	int i,j,slen,len3,z;
	int k,l;
	char c,input[100],empty[100],inter[100],inter2[100];
	
	strcpy(empty,"");
	
	strcpy(inter,empty);
	
	fp=fopen("precedence.txt","r");
	
    c=fgetc(fp);
	while(!feof(fp) && c!='\n')
	{
		if(c!='\t')
			ter[i++]=c;
		
		c=fgetc(fp);		
	} 	
	ter[i]='\0';
	len = strlen(ter);
	
	i=0;
	
	c=fgetc(fp);
	while(!feof(fp))
	{
		j=0;
		while(c!='\n')
		{
			if(c!='\t')
				table[i][j++]=c;
			c=fgetc(fp);
		}
		table[i][j]='\0';
		i++;
		c=fgetc(fp);				
	}
	
	printf("Enter the expression:");
	scanf("%s",&input[1]);
  
     printf("\n");
 
    input[0]='$';
    slen=strlen(input);
    input[slen]='$';
    input[slen+1]='\0';
    
    printf("\ninput:%s\n",input);
  
      i=0;
      row=sindex(input[i]);
      col=sindex(input[i+1]);
    	
	  sprintf(inter,"%s%c%c%c",inter,input[i],table[row][col],input[i+1]);    	
	      
    for(i=1;i<slen;i++)
    {
    	 row=sindex(input[i]);
         col=sindex(input[i+1]);         
            sprintf(inter,"%s%c%c",inter,table[row][col],input[i+1]);   	  	
	} 
    
  printf("\n%s",inter);
    
  strcpy(step2,inter);
    
  i=0;
  i++;
  while(step2[i]!='$')
  {
  	 if(step2[i]=='>')
  	 {
  	    	k=i;
  	    	while(step2[k]!='$')
  	    	{
  	    		if(step2[k]=='<')
  	    		{
  	    		   break;					  
				}
				else
				{
				   k--;	
				} 	    		 	    		
			}
			if(step2[k]=='<')
			{
	             step2[k]='E';
				 k++;
				 while(step2[k+2]!='$')
				 {
				 	step2[k]=step2[k+2];
				 	k++;
				 }
				 step2[k++]='$';
				 step2[k]='\0';
				 
				 printf("\n%s",step2);
				 			
			}
			else
			{
				printf("\nerror");
				exit(0);
			}
  	    	
  	    	
	 }	  
	  	i++;
  }  
   
    z=1;
    while(step2[z]!='$')
    {
    	if(step2[z]=='<'||step2[z]=='>')
    	{
    		printf("\nString rejected\n");
    		exit(0);
		}
		z++;    	    	
	}

   strcpy(step3,step2);
   
   z=1;
   while(step3[z]!='$')
   {
   	  if(step3[z]=='E')
   	  {
   	      k=z;
		  while(step3[k]!='$')
		  {
		  	  step3[k]=step3[k+1];
			  k++;	 		  	 
		  }	 		
		  step3[k]='\0';   	
	  }
   	 z++;
   }

   len3=strlen(step3);
   
   strcpy(inter2,"");
   
    i=0;
      row=sindex(step3[i]);
      col=sindex(step3[i+1]);
      
      
      if(row==0 && col==0)
      {
      	printf("\nString rejected\n ");
      	exit(0);
	  }
	  else if(row==-1||col==-1)
	  {
	  	 printf("\n1:Invalid symbol");
	  	 exit(0);
	  }
    	
	  sprintf(inter2,"%s%c%c%c",inter2,step3[i],table[row][col],step3[i+1]);    	
    
    for(i=1;i<len3-1;i++)
    {
    	 row=sindex(step3[i]);
         col=sindex(step3[i+1]);    
		 
		    if(row==0 && col==0)
      		{
      			printf("\nString rejected ");
      			exit(0);
	  		}
	  		else if(row==-1||col==-1)
	  		{
	  	 		
				   printf("\n%c : %c",step3[i],step3[i+1]); 
				   printf("\n2:Invalid symbol");
	  	 		   exit(0);
	  		}
	       
            sprintf(inter2,"%s%c%c",inter2,table[row][col],step3[i+1]);   	  	
	}
   

  printf("\n\n%s",inter2);
   	  	  	
  strcpy(step4,inter2); 	
  
  
  i=0;
  i++;
  while(step4[i]!='$')
  {
  	 if(step4[i]=='>')
  	 {
  	    	k=i;
  	    	while(step4[k]!='$')
  	    	{
  	    		if(step4[k]=='<')
  	    		{
  	    		   break;					  
				}
				else
				{
				   k--;	
				} 	    		 	    		
			}
			if(step4[k]=='<')
			{	             	             	             
	             row=sindex(step4[k-1]);
	             col=sindex(step4[i+1]);
	             
	             
	             		    if(row==0 && col==0)
      						{
      								printf("\nString rejected ");
      								exit(0);
	  						}
	  						else if(row==-1||col==-1)
	  						{
	  	 						printf("\n3:Invalid symbol");
	  	 						exit(0);
	  						}
	             
	             	             if(step4[k-1]=='$' && step4[i+1]== '$')
	            				 {
	                   					printf("\n$$");
					   					printf("\nString accepted\n");
					  					 exit(0); 	
	             	
				 				}
	             
	             
	             step4[k]=table[row][col];
	             
				 k++;
				 while(step4[k+2]!='$')
				 {
				 	step4[k]=step4[k+2];
				 	k++;
				 }
				 step4[k++]='$';
				 step4[k]='\0';
				 
				 printf("\n%s",step4);	
				 i=1;			 			
			}
			else
			{
				printf("\nerror");
				exit(0);
			} 	    	
	 }	  
	  	i++;
  }  
 	
	return 0;
}
