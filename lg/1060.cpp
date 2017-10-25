#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 40
int w[MAXN]={0};
int r[MAXN]={0};
int n,m;
int dp[MAXN][30020]={0};
void output(){
    cout<<"--------------------------"<<endl;
    for(int i=0;i<m;++i){
        for(int j=0;j<=n;j+=100){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>w[i]>>r[i];
    }
    for(int i=0;i<=n;++i){
        dp[0][i] = i > w[0] ? w[0]*r[0] : 0;
    }
    for(int i=1;i<m;++i){
        for(int j=0;j<=n;++j){
            if(j-w[i]>=0){
                dp[i][j]=max(dp[i][j-1],dp[i-1][j-w[i]]+w[i]*r[i]);
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
        output();
    }
    cout<<dp[m-1][n];
    return 0;
}