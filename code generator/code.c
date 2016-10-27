#include<stdio.h>
#include<string.h>
int rstack[100],top=-1;
int t;
char operation[10];
void pushr(int item)
{
	top++;
	rstack[top]=item;
}
void operate(char ch)
{
	switch(ch)
	{
		case '+': strcpy(operation,"ADD");
			break;
		case '-': strcpy(operation,"SUB");
			break;
		case '*': strcpy(operation,"MUL");
			break;
		case '/': strcpy(operation,"DIV");
			break;
	}
}
int popr()
{
	int item=rstack[top];
	top--;
	return item;
}

int peep()
{
	return rstack[top];
}

void display()
{
	int i;
	printf("Stack:");
	for(i=0;i<=top;i++)
	{
		printf("%d",rstack[i]);
	}
	printf("\n");
}
void swap()
{
	int temp;
	temp=rstack[top];
	rstack[top]=rstack[top-1];
	rstack[top-1]=temp;
}

struct tree
{
	int label;
	char op;
	char name;
}tree[100];

int left(int node)
{
	return ((2*node)+1);
}

int right(int node)
{
	return ((2*node)+2);
}

void gencode(int i)
{
	if(tree[i].op==tree[i].name)	//case 0
	{
		printf("MOV %c,R%d\n",tree[i].name,peep());
	}
	else if(tree[right(i)].label==0)	//case 1
	{
		gencode(left(i));
		operate(tree[i].op);
		printf("%s %c,R%d\n",operation,tree[i].name,peep());
	}
	else if(tree[left(i)].label<tree[right(i)].label)	//case 2
	{
		swap();
		gencode(right(i));
		t=popr();
		gencode(left(i));
		operate(tree[i].op);
		printf("%s R%d,R%d\n",operation,t,peep());
		pushr(t);
		swap();
	}
	else if(tree[left(i)].label>=tree[right(i)].label)	//case 3
	{
		gencode(left(i));
		t=popr();
		gencode(right(i));
		operate(tree[i].op);
		printf("%s R%d,R%d\n",operation,peep(),t);
		pushr(t);
	}
	else
	{

	}
}

void main()
{
	int n;
	char temp[4];
	FILE *fp;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d",&n);
//	printf("%d",n);
	int i,j;
	int r=0;
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%s",temp);
		if(temp[0]=='_')
		{
			tree[i].op=temp[0];
		}
		else if(temp[0]>='a' && temp[0]<='z')
		{
			tree[i].op=temp[0];
			tree[i].name=temp[0];
			tree[i].label=temp[1]-0x30;
			if(r<tree[i].label)
				r=tree[i].label;
		}
		else
		{
			tree[i].op=temp[0];
			tree[i].name=temp[1];
			tree[i].label=temp[2]-0x30;
			if(r<tree[i].label)
				r=tree[i].label;
		}
	}	
//	for(i=0;i<n;i++)
//	{	
//		printf("Tree[%d]:%c %c %d\n",i,tree[i].op,tree[i].name,tree[i].label);
//	}
	for(i=0;i<r;i++)
	{
		pushr(i);
	}
	gencode(0);
}
