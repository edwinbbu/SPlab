#include<stdio.h>
#include<string.h>
struct optab
{
        char opcode[100];
        char mcode[100];
};
struct symtab
{
        char addr[100];
        char symbol[100];
};

void main()
{
        struct optab opt[100];
        struct symtab sym[100];
        FILE *fp,*fp2,*fp3,*fp4,*fp5;
        char add[100],label[100],opcode[100],operand[100],optab[100],optab2[100],start[100],text[100];
        int length,i,k=0,m=0,l=0;
        fp=fopen("intermediate.txt","r");
        fp2=fopen("optab.txt","r");
        fp3=fopen("symtab.txt","r");
        fp4=fopen("output.txt","w+");
        fp5=fopen("length.txt","r");
        fscanf(fp5,"%d",&length);
        fscanf(fp,"%s %s %s %s",add,label,opcode,operand);
        if(strcmp(opcode,"START")==0)
        {
                fprintf(fp4,"H^%s^%s^%d\n",label,operand,length);
                strcpy(start,operand);
        }
        fprintf(fp4,"T^00%s",operand);
        fprintf(fp4,"^00");
        i=0;
        while(fscanf(fp2,"%s %s",optab,optab2)!=EOF)
        {
                strcpy(opt[i].opcode,optab);
                strcpy(opt[i].mcode,optab2);
                i++;
                k=i;
        }
        i=0;
        while(fscanf(fp3,"%s %s",add,label)!=EOF)
        {
                strcpy(sym[i].addr,add);
                strcpy(sym[i].symbol,label);
                i++;
                m=i;
        }
        while(fscanf(fp,"%s %s %s %s",add,label,opcode,operand)!=EOF)
        {
                if(strcmp(opcode,"END")==0)
                {
                        fprintf(fp4,"\nE^00%s",start);
                        break;
                }
                if((strcmp(opcode,"BYTE")==0)||(strcmp(opcode,"WORD")==0))
                {
                        if(strcmp(opcode,"WORD")==0)
                        {
                                fprintf(fp4,"^00000%s",operand);
                                l+=6;
                        }
                        else
                        {
                                fprintf(fp4,"^");
                                int len=strlen(operand);
                        //      printf("%d",len);
                                for(i=2;i<(len-1);i++)
                                {
                                        fprintf(fp4,"%d",operand[i]);
                                }
                                l+=6;
                        }
                }
                for(i=0;i<k;i++)
                {
                        if(strcmp(opcode,opt[i].opcode)==0)
                        {
                                fprintf(fp4,"^%s",opt[i].mcode);

                        }
                }
                for(i=0;i<m;i++)
                {
                        if(strcmp(operand,sym[i].symbol)==0)
                        {
                                fprintf(fp4,"%s",sym[i].addr);
                                l+=6;
                        }
                }
        }
//printf("length=%x\n",l);
rewind(fp4);
fscanf(fp4,"%[^\n]s",text);
fseek(fp4,10,SEEK_CUR);
fprintf(fp4,"%x",l);
int fcloseall();
}

