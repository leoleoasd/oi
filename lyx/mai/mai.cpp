#include <iostream>
#include <fstream>
#include <vector>
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
ifstream fin("mai.in");
ofstream fout("mai.out");
#define cin fin
//#define cout fout
vector<int> SP[MAXN];
#define max(A,B) ((A)>(B)?(A):(B))
int main(){
    ios::sync_with_stdio(false);
    cin>>w>>n>>D;
    for(int i=1;i<=D;++i){
        cin>>d[i];
    }
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
        SP[c[i]].push_back(i);
    }
    cout<<1;
    for(int i=1;i<=D;i++)
        for(int j=w;j>=0;j--)
            for(int k=0;k<=SP[i].size();k++)
                if(a[SP[i][k]]<=j)
                    dp[j]=max(dp[j],dp[j-a[SP[i][k]]]+d[i]*b[SP[i][k]]);
    cout<<dp[w]<<endl;
    return 0;
}
