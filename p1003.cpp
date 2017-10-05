#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10001;
int a[maxn][4]={0};
int n;
int main()
{
    int x,y,z,w;
    int sx,sy;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&x,&y,&z,&w);
        a[i][0]=x;
        a[i][1]=y;
        a[i][2]=z;
        a[i][3]=w;
    }
    scanf("%d%d",&sx,&sy);
    int ans=-1;
    for(int i=n;i>=1;i--)
    {
        int stx=a[i][0]+a[i][2];
        int sty=a[i][1]+a[i][3];
        if(sx>=a[i][0] && sx<=stx && sy>=a[i][1] && sy<=sty){
        ans=i;
            break;}
    }
    printf("%d",ans);
    return 0;
}