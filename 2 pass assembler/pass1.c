#include<stdio.h>
#include<string.h>
void main()
{
        FILE *fp,*fp2,*fp3,*fp4,*fp5;
        int num,locctr,mcode,op,pl,i=0,k;
        char label[100],opcode[100],operand[100],opt[100],comment[100],optab1[100],optab2[100],aopcode[100][100];
        fp=fopen("input.txt","r");
        fp2=fopen("symtab.txt","w");
        fp3=fopen("intermediate.txt","w");
        fp4=fopen("optab.txt","r");
        fp5=fopen("length.txt","w");
        while(fscanf(fp4,"%s %s",optab1,optab2)!=EOF)
        {
                strcpy(aopcode[i],optab1);
                i++;
                k=i;
        }
        fscanf(fp,"%s%s%x",label,opcode,&num);
        if(strcmp(opcode,"START")==0)
        {
                locctr=num;
                fprintf(fp3,"-\t%s\t%s\t%x\n",label,opcode,locctr);
        }
        else
        {
                locctr=0;
                fprintf(fp3,"%s\t%s\t%x\n",label,opcode,locctr);
        }
        while(fscanf(fp,"%s %s %s",label,opcode,operand)!=EOF)
        {
                if(label[0]==';')
                {
                        fscanf(fp,"%[^\n]s",comment);
                        continue;
                }
                fprintf(fp3,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
                if(strcmp(label,"-")!=0)
                {
                        fprintf(fp2,"%x\t%s\n",locctr,label);
                }
                if(strcmp(opcode,"END")==0)
                {
                        break;
                }
                if(strcmp(opcode,"WORD")==0)
                {
                        locctr=locctr+3;
                }
                else if(strcmp(opcode,"RESW")==0)
                {
                        op=atoi(operand);
                        locctr=locctr+(3*op);
                }
                else if(strcmp(opcode,"BYTE")==0)
                {
                        if(operand[0]=='X')
                        {
                                locctr=locctr+1;
                        }
                        else
                        {
                                op=strlen(operand)-2;
                                locctr=locctr+op;
                        }

                }
                else if(strcmp(opcode,"RESB")==0)
                {
                        op=atoi(operand);
                        locctr=locctr+op;
                }
                else
                {
                        int flag=0;
                        for(i=0;i<k;i++)
                        {
                                if(strcmp(opcode,aopcode[i])==0)
                                {
                                        flag=1;
                                }
                        }
                        if(flag==1)
                        {
                                locctr+=3;
                        }
                        else
                        {
                                printf("Error flag");
                        }

                }

        }
        pl=locctr-num;
//      printf("program length=%d",pl);
        fprintf(fp5,"%x",pl);
        int fcloseall();
}

