#include<stdio.h>
int main()
{
      

	int a[100],i,j,n,count=0,flag,size=-1,mp,k,z,sum;
	scanf("%d",&n);
       
	for(i=2;i<=n;i++)
	{	
		flag=0;
		for(j=2;j<=i/2;j++)
		{
			if(i%j==0)
				flag=1;
		}
		if(flag==0)
                {
			a[++size]=i;
                        sum=0;
                        if(size>=2)
                        {
                           for(z=0;z<size;z++)
                           {
                              sum=sum+a[z];
                              if(sum==a[size])
                             {
                               count++;
                               break;  
                             }
     
                           }                           
                        } 
                }
	}
        printf("%d",count);
              return 0;
}
