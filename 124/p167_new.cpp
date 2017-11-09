#include <bits/stdc++.h>
using namespace std;
int main(){
    #define MAXN 100020
    int n;
    int data[MAXN]={0};
    int dp[MAXN]={0};
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }
    int len = 0;
    for(int i=0;i<n;++i){
        if(data[i]>=dp[len]){
            dp[++len]=data[i];
        }else{
            dp[upper_bound(dp,dp+len,data[i])-dp]=data[i];
        }

    }
    cout<<len;
    return 0;
}
