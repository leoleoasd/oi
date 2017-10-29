#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 5050
int a[MAXN]={0};
int b[MAXN]={0};
int c[MAXN]={0};
int d[MAXN]={0};
int w;
int n;
int D;
int dp[MAXN]={0};
// 转移方程 f[k][v]=max{f[k-1][v],f[k-1][v-c[i]]+w[i]|物品i属于组k}
#define max(A,B) ((A)>(B)?(A):(B))
int main(){
    ios::sync_with_stdio(false);
    cin>>w>>n>>D;
    for(int i=1;i<=D;++i){
        cin>>d[i];
    }
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int k=1;k<=D;++k){
        for(int v = 0;v<w;++v){
            for(int i=1;i<=n;++i){
                if(c[i]==k and v > a[i]){
                    dp[v]=max(dp[v],dp[v-a[i]]+b[i]*d[k]);
                }
            }
        }
    }
    cout<<dp[w]<<endl;
    return 0;
}
