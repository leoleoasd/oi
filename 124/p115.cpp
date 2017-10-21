#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int t=0,n,m,f,vi,vj,u=1,r=0,x,z,k=0;	
int chu[9999]={0},ru[9999]={0},E[9999]={0},L[9999]={0},chu2[9999]={0},ru2[9999]={0};
int vij[110][110]={0};
void Ei(int p)
{
	int i,j;
	for(j=1;j<=n;j++)
	{
		if(chu[p]!=0&&vij[p][j]!=0)
		{
		    chu[p]--;
		    ru[j]--;
    		if(vij[p][j]+E[p]>E[j])
	    	{
	    	    E[j]=E[p]+vij[p][j];
    	    }
    	}
	}
	for(j=1;j<=n;j++)
	{
		if(ru[j]==0&&chu[j]!=0)
		{
			Ei(j);
		}
	}
}
void Li(int p)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(ru2[p]!=0&&vij[i][p]!=0)
		{
			ru2[p]--;
			chu2[i]--;
			if(E[p]-vij[i][p]>=L[i])
			{
			    L[i]=E[p]-vij[i][p];
		    }
		}
	}
	for(i=1;i<=n;i++)
	{
		if(chu2[i]==0&&ru2[i]!=0)
		{
			Li(j);
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&k);
			vij[i][j]=k;
			if(k!=0)
			{
				ru[j]++;
				chu[i]++;
				ru2[j]++;
				chu2[i]++;
			}
		}
	}
    Ei(1);
    for(i=1;i<=n;i++)
    {
	    printf("%d ",E[i]);

	}	    printf("\n");
    for(i=1;i<=n;i++)
    {
    	L[i]=E[i];
	}
	Li(n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",L[i]);

	}		printf("\n");
	for(i=1;i<=n;i++)
	{
		if(E[i]==L[i])
		{
			printf("%d ",i);
		}
	}
	return 0;
}