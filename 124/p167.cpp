#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10020
int data[MAXN]={0};
int n;
int dp[MAXN]={0};
void solve(){
    int maxx = -1;
    for(int i=1;i<=n;++i){
        maxx = -1;
        for(int j=1;j<=i;++j){
            if(data[i]<=data[j])
            maxx = max(maxx,dp[j]);
        }
        dp[i] = maxx+1;
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>data[i];
    }
    solve();
    int xxx = -1;
    for(int i=1;i<=n;++i){
        xxx = max(xxx,dp[i]);
    }
    cout<<xxx;
    return 0;
}