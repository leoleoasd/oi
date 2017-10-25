#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 40
int w[MAXN]={0};
int r[MAXN]={0};
int n,m;
int dp[30020]={0};
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>w[i]>>r[i];
    }
    for(int i=0;i<=n;++i){
        dp[i] = i > w[0] ? w[0]*r[0] : 0;
    }
    for(int i=1;i<m;++i){
        for(int j=n;j>=w[i];--j){
            if(j-w[i]>=0){
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]*r[i]);
            }
            else{
                dp[j]=dp[j-1];
            }
        }
    }
    cout<<dp[n];
    return 0;
}