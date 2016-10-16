#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
FILE *fp1, *fp2, *fp3, *autom;
int ttable[12][9],state=0;
int i,j,keyflag=0;
int status;
char c,tok[30],keyw[30],sentence[100],header[50],t,num[10];

void init_auto();
int is_iden();
int is_keyword();
int is_string();
int is_header();
int is_relop();
int is_symbols();
int is_operator();
int is_number();

int main()
{
	init_auto();
	fp1=fopen("sample.c","r");
        c=fgetc(fp1);   
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
                  printf("\t%d",ttable[i][j]);
            }
        } 
        printf("\n");
        fclose(autom); 
}

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
       /* if(c=='"')
        {
            printf("\n %c is a symbol!",c);  
            state=ttable[state][0];
        }
       */  
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
