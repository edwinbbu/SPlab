#include<stdio.h>
char st[100];
char sr[100];
int ttop=-1;
int rtop=-1;

char* op(char ch)
{
	char a[2];
	switch(ch)
	{
		case '+' : return "ADD";
		case '-' : return "SUB";
		case '*' : return "MUL";
		case '/' : return "DIV";
	}
	a[0]=ch;
	a[1]='\0';
	return a;
}

void rpush(char a)
{
	sr[++rtop]=a;
}
char rpop()
{
	return sr[rtop--];
}

void tpush(char a)
{
	st[++ttop]=a;
}
char tpop()
{
	return st[ttop--];
}
char peep()
{
	return sr[rtop];
}
void swap()
{
	char a=sr[rtop];
	sr[rtop]=sr[rtop-1];
	sr[rtop-1]=a;
}

struct tree{
	int label;
	char op;
	char name;
}t[100];
int n,r;
int left(int root)
{
	return (2*root)+1;
}

int right(int root)
{
	return (2*root)+2;
}


void gencode(int index)
{
	char temp;
	if(t[index].op==t[index].name)
	{
		//printf("CASE 0\n");
		printf("MOV %c ,R%c \n",t[index].name,peep());
	}
	else if(t[right(index)].label==0)
	{
		//printf("CASE 1\n");
		gencode(left(index));
		printf("%s %c ,R%c \n",op(t[index].op),t[right(index)].name,peep());
	}
	else if(t[left(index)].label<t[right(index)].label)
	{
		//printf("CASE 2\n");
		swap();
		gencode(right(index));
		temp=rpop();
		gencode(left(index));
		printf("%s R%c ,R%c \n",op(t[index].op),temp,peep());
		rpush(temp);
		swap();
	}
	else if(t[left(index)].label>=t[right(index)].label)
	{
		//printf("CASE 3\n");
		gencode(left(index)); 
		temp=rpop();
		gencode(right(index));
		printf("%s R%c ,R%c \n",op(t[index].op),peep(),temp);
		rpush(temp);
	}
	else
	{
		printf("hello\n");
		//printf("CASE 4\n");
		gencode(right(index));
		temp=tpop();
		printf("MOV R%c ,%c \n",peep(),temp);
		gencode(left(index));
		tpush(temp);
		printf("%s %c ,R%c \n",op(t[index].op),temp,peep());
	}
}
void main(int argc, char* argv[])
{
	int i,j,k;
	char temp[4];
	FILE *fp;
	if(argc>1)
		fp=fopen(argv[1],"r");
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&n);
	//printf("%d",n);
	r=0;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",temp);
		if(temp[0]=='_')
			t[i].op=temp[0];
		else if(temp[0]>='a'&&temp[0]<='z')
		{
			t[i].op=t[i].name=temp[0];
			t[i].label=temp[1]-0x30;
			if(r<t[i].label)
				r=t[i].label;
		}
		else 
		{
			t[i].op=temp[0];
			t[i].name=temp[1];
			t[i].label=temp[2]-0x30;
			if(r<t[i].label)
				r=t[i].label;
		}
		//fscanf(fp,"[\n\r]",&temp);
	}
	/*for(i=0;i<n;i++)
	{
		printf("%c %d %c\n",t[i].op,t[i].label,t[i].name);
	}
	printf("\n");*/
	for(i=0;i<r;i++)
		rpush(i+'0');
	for(i=0;i<4;i++)
		tpush(i+'A');
	gencode(0);
	
}	
	
	
