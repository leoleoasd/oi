#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    #define MAXN 40
    int w[MAXN]={0};
    int r[MAXN]={0};
    int n,m;
    int dp[MAXN][30020]={0};
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>w[i]>>r[i];
    }
    for(int i=0;i<=n;++i){
        dp[0][i] = i > w[0] ? w[0]*r[0] : 0;
    }
    for(int i=1;i<=m;++i){
        for(int j=0;j<=n;++j){
            if(j-w[i]>=0){
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-w[i]]+w[i]*r[i]);
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    cout<<dp[m][n];
    return 0;
}