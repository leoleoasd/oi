#include<iostream>
#include<cmath>
using namespace std;
long long a[1000010];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(;t>0;t--)
    {
        long long n,m,k;
        long long mm=0x7ffffffffffffff,mt=0;
        cin>>n>>m>>k;
        long long ans=(k-1)*2;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            if(a[i]<mm)
            {
                mm=a[i];
                mt=i;
            }
        }
        for(int i=0;i<m;i++)if(i!=mt)ans+=2*abs(k-a[i]);
        if(mm>k)ans+=2*abs(k-a[mt]);
        cout<<ans<<'\n';
    }
}