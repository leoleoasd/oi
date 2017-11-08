#include <bits/stdc++.h>
using namespace std;
int main(){
    #define MAXN 1e5+20
    int n;
    int data[MAXN]={0};
    int dp[MAXN]={0};
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(dp[j]>data[i]){
                dp[j]=data[i];
            }
        }
    }
    int m = -1;
    for(int i=0;i<n;++i){
        if(dp[i]) m = max(m,i);
    }
    cout<<m;
    return 0;
}
