#include <iostream>
#include <fstream>
#include <stdint.h>
using namespace std;
#define MAXN 5050
long long a[MAXN]={0};
long long b[MAXN]={0};
long long c[MAXN]={0};
long long d[MAXN]={0};
long long w;
long long n;
long long D;
long long dp[MAXN]={0};
// 转移方程 f[k][v]=max{f[k-1][v],f[k-1][v-c[i]]+w[i]|物品i属于组k}
ifstream fin("mai.in");
ofstream fout("mai.out");
#define cin fin
//#define cout fout
#define max(A,B) ((A)>(B)?(A):(B))
int main(){
    ios::sync_with_stdio(false);
    cin>>w>>n>>D;
    for(long long i=1;i<=D;++i){
        cin>>d[i];
    }
    for(long long i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(long long i=1;i<=D;i++)
        for(long long j=w;j>=0;j--)
            for(long long k=1;k<=n;k++)
                if(a[k]<=j and c[k]==i)
                    dp[j]=max(dp[j],dp[j-a[k]]+d[i]*b[k]);
    cout<<dp[w]<<endl;
    return 0;
}
