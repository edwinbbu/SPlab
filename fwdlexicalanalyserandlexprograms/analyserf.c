#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
FILE *fp1, *fp2, *fp3, *autom;
int ttable[12][9],state=0;
int i,j,keyflag=0,k,l,z;
int status;
char c,tok[30],keyw[30],sentence[100],header[50],t,num[20],reloper[3];
char pretok;
void init_auto();
/*
int is_iden();
int is_keyword();
int is_string();
int is_header();
int is_relop();
int is_symbols();
int is_operator();
int is_number();
*/
int is_keyword();
int check_iden();
int check_letter();
int check_string();
int check_header();
int check_relop();
int check_symbols();
int check_operator();
int check_number();

int main()
{
	init_auto();
	fp1=fopen("sample.c","r");
        

        state=0;
        i=0;
        j=0;
        k=0;

        c=fgetc(fp1); 
        while(!feof(fp1))
        {
            	if(state==0)
            	{
               
               		if((check_symbols())==1)
               		{
                  		 state=ttable[state][4];
               		}
               		else if((check_operator())==1)
               		{
                   		state=ttable[state][3];
               		}
               		else if((check_letter())==1)
              		 {
                   		i=0;
                   		state=ttable[state][1];
                   		tok[i++]=c; 
               		}
               		else if(c=='"')
               		{
                   		j=0;
                   		state=ttable[state][0];
                   		printf("\n %c is a symbol",c);
               		}
               		else if(isdigit(c))
               		{ 
                   		k=0;
                   		state=ttable[state][2];
                   		num[k++]=c;
               		}
               		else if(c=='>'||c=='<')
               		{
                   		l=0;
                   		state=ttable[state][5];
                   		reloper[l++]=c;                   
              		}
                        else if(c=='!')
                        {
				l=0;
                                state=ttable[state][7];
                                reloper[l++]=c;  
                        }
                        else if(c=='#')
                        {
                             z=0;
                             state=ttable[state][8];
                             header[z++]=c;
                        }                   
    
            }  
            else if(state==1)
	    {
 		    state=0;
		    fseek(fp1,-1,SEEK_CUR);
                    printf("\n%c is a symbol",pretok);

            }
            else if(state==2)
            { 
                   state=0;
                   fseek(fp1,-1,SEEK_CUR);
                   printf("\n%c is an operator",pretok);   
                
            }
            else if(state==3)
            {
                 if(isalnum(c))
                 {
                    tok[i++]=c;  
                 }
                 else
                 {
                      fseek(fp1,-1,SEEK_CUR);
                      tok[i++]='\0';
                      state=0;
                      if((is_keyword())==1)
                        printf("\n %s is a keyword!",tok);
                      else
                        printf("\n %s is a identifier!",tok);
                        i=0;     
                 }  

            }
            else if(state==4)
            {
                 if(c=='"')
                 {
                    state=ttable[state][0];
                    sentence[j++]='\0';
                    pretok=c;
                    j=0;
                 }
                 else
                 {
                     sentence[j++]=c;                     
                 }  

            }
            else if(state==5)
            {
                fseek(fp1,-1,SEEK_CUR);
                printf("\n %s is a string",sentence);
                printf("\n%c is a symbol",pretok);
                state=0;
                 
            }
            else if(state==6)
            {
                if(isdigit(c))
                {
                    num[k++]=c;              
                }
                else
                {
                  fseek(fp1,-1,SEEK_CUR); 
                  num[k++]='\0';
                  printf("\n%s is a number",num);
                  k=0;
                  state=0;
                }  

            }
            else if(state==7)
            {
                if(c=='=')
                {
                   state=ttable[state][6]; 
                   reloper[l++]='='; 
                }
                else
                {
                   reloper[l++]='\0';
                   l=0;
                   printf("\n%s is a relational operator",reloper);
                   state=0;                   
                }   

            }
            else if(state==8)
            {
                fseek(fp1,-1,SEEK_CUR);
                reloper[l++]='\0';
                l=0;
                printf("\n%s is a relational operator",reloper);
                state=0;      

            }
            else if(state==9)
            {
                if(c=='=')
                {
                   state=ttable[state][6];
                   reloper[l++]=c;                                      
                }
                else
                {
                   fseek(fp1,-1,SEEK_CUR);
                   reloper[l++]='\0';
                   l=0;
                   state=0;
                   printf("\n%s is a symbol",reloper);  
                       
                }
            }
            else if(state==10)
            {
                fseek(fp1,-1,SEEK_CUR);
                reloper[l++]='\0';
                l=0;
                state=0;
                printf("\n%s is a relational operator",reloper); 

            }
            else if(state==11)
            {
                  if(c=='>')
                  {
                     header[z++]=c;
                     header[z++]='\0';
                     printf("\n%s is a header file",header);
                     state=0;
                     z=0;                              
                  }
                  else
                  {
                      header[z++]=c;
                  }   

            }
              	    
            c=fgetc(fp1);
        }     

        /*  
        while(!feof(fp1))
        {
            if(state==0)
            {
               if((is_iden())==1)
                    ;
               else if((is_string())==1)
                    ; 
               else if((is_header())==1)
                    ;
               else if((is_relop())==1)
                    ;  
               else if((is_symbols())==1)
                    ;  
               else if((is_operator())==1)
                    ;
               else if((is_number())==1)
                    ;   
            }                	    
            c=fgetc(fp1);
        }     
       */	

printf("\n");

fcloseall();
return 0;
}

void init_auto()
{
	autom=fopen("automata.txt","r");
        for(i=0;i<12;i++)
        { 
             printf("\n");
            for(j=0;j<9;j++)
            {
               fscanf(autom,"%d",&ttable[i][j]);
                  //printf("\t%d",ttable[i][j]);
            }
        } 
        printf("\n");
        fclose(autom); 
}
/*
int is_iden()
{
     i=0;
     strcpy(tok,"");
    if(isalpha(c)||c=='_')
    {
        state=ttable[state][1];
        tok[i++]=c;
        c=fgetc(fp1);
        while(isalnum(c)&&!feof(fp1))
        {
           tok[i++]=c;
           c=fgetc(fp1);   
        }
        fseek(fp1,-1,SEEK_CUR);
        tok[i++]='\0'; 
         if((is_keyword())==1)
         printf("\n%s is a keyword!",tok);
        else
         printf("\n%s is an identifier!",tok);      
       state=0;//reset the automata
       return 1;
    }
    else
      return 0;

}
*/
int check_symbols()
{
	 if(c=='{'||c=='}'||c=='%'||c==';'||c==','||c=='('||c==')'||c=='['||c==']'||c=='\''||c=='.'||c=='?'||c==':'||c=='&'||c=='|')
     {
         pretok=c;
         return 1;
     }
     else
      return 0; 
}
int check_operator()
{
     if(c=='='||c=='+'||c=='-'||c=='*'||c=='/')
     {
        
           pretok=c;
          // printf("\n %c is an operator!",c);
         // state=0;
          return 1;
     }
     else 
      return 0;
}
int is_keyword()
{
   keyflag=0; 
   fp2=fopen("keywords.txt","r");   
   fscanf(fp2,"%s",keyw);
   while(!feof(fp2))
   {
      if(strcmp(tok,keyw)==0)
      {
          keyflag=1;  
          break;
      }
     
    fscanf(fp2,"%s",keyw);
   } 
   fclose(fp2);
   if(keyflag==1)
     return 1;
   else
     return 0;

}
int check_letter()
{
   if(isalpha(c))
   {
      return 1;
   }
   else 
    return 0; 

}
/*
int is_string()
{
    i=0;
    if(c=='"')
    {
       printf("\n %c is a symbol",c);
       state=ttable[state][0];
       c=fgetc(fp1);
       while(c!='"'&&!feof(fp1))
       {
           sentence[i++]=c;
           c=fgetc(fp1);   
       }
      
       sentence[i++]='\0';
       printf("\n%s  is a string",sentence);
        if(c=='"')
        {
            printf("\n %c is a symbol!",c);  
            state=ttable[state][0];
        }     
        state=0;//reset the automata
        return 1;  
    }
    else
     return 0;
}

int is_header()
{
   if(c=='#')
   {
      state=ttable[state][8];
      //printf("\n%c",c);
      fseek(fp1,-1,SEEK_CUR);
      fscanf(fp1,"%s",header);
      printf("\n%s  is a header file!",header);
      state=0;//reset the automata
      return 1;
   }
   else
    return 0;
}

int is_relop()
{
   if(c=='>'||c=='<')
   {
       t=c;
       state=ttable[state][5];
        c=fgetc(fp1);
       if(c=='=')
       {
          state=ttable[state][6];
          printf("\n %c%c is a relational operator!",t,c);
          state=0;//reset the automata
         // return 1;
       }
       else
       {
           fseek(fp1,-1,SEEK_CUR);
           printf("\n %c is a relational operator!",t);
           state=0;//reset the automata               
       }               
        
      return 1;
   }
   else if(c=='!')
   {
       t=c; 
       state=ttable[state][7];
       c=fgetc(fp1);
       if(c=='=')
       {
           state=ttable[state][6];
           printf("\n %c%c is a relatonal operator!",t,c); 
           state=0;
           return 1;  
       }
       else
       {
           fseek(fp1,-1,SEEK_CUR);
           printf("\nerror.... resetting the automata!");
           state=0;
           return 0;

       }
   }
   else 
    return 0;    

}

int is_symbols()
{
    if(c=='{'||c=='}'||c=='%'||c==';'||c==','||c=='('||c==')'||c=='['||c==']'||c=='\''||c=='.'||c=='?'||c==':'||c=='&'||c=='|')
     {
         state=ttable[state][4];
         printf("\n %c is a symbol!",c);
         state=0;
         return 1;
     }
     else
      return 0; 


}

int is_operator()
{
     if(c=='='||c=='+'||c=='-'||c=='*'||c=='/')
     {
          state=ttable[state][3];
          printf("\n %c is an operator!",c);
          state=0;
          return 0;
     }
     else 
      return 0;
}
int is_number()
{
    i=0;
    if(isalnum(c))
    {
       num[i++]=c;
       state=ttable[state][6];
       c=fgetc(fp1);
       while(isalnum(c))
       {
          num[i++]=c;
          c=fgetc(fp1);
       } 
       if(isalpha(c))
       {
            printf("\nInvalid identifier!!!!...exiting..."); 
            exit(0);
       }
       fseek(fp1,-1,SEEK_CUR);  
       num[i++]='\0'; 
       printf("\n%s is a number!",num);
       state=0;
       return 1;            
    }
    else
      return 0; 
}
*/
