#include<cstdio>
int n,m,a[2000000],q[2000000],l=1,r=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(m==0){
        for(int i=1;i<=n;i++)
            printf("0\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",a[q[l]]);
        if(i-q[l]+1>m && l<=r) l++;
        while(a[i]<a[q[r]] && l<=r) r--;
        q[++r]=i;
    }
}