#include <iostream>
#include <queue>
using namespace std;
#define MAXN 55
int main(){
    int n,begin,maxl;
    int data[MAXN] = {0};
    int dp[MAXN][1050] = {0};
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>begin>>maxl;
    for(int i = 1; i <= n; ++ i){
        cin>>data[i];
    }
    /*
    for(int i = 0; i <= begin; ++ i){
        dp[0][i] = 1;
    }
     */
    dp[0][begin] = 1;
    for(int i = 1; i <= n; ++ i){
        for(int j = 0; j <= maxl; ++ j){
            if(j-data[i] >= 0 and dp[i-1][j-data[i]]){
                dp[i][j] = 1;
            }
            if(j+data[i] <= maxl and dp[i-1][j+data[i]]){
                dp[i][j] = 1;
            }
        }
    }
    for(int j = maxl; j >= 0; -- j){
        if(dp[n][j]){
            cout<<j<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}