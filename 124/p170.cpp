#include <iostream>
#include <vector>
#include <cstdio>
#include <stdint.h>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;

#define MAXN 42
#define int long long

int n,k;
int dp[MAXN][MAXN][10]={0};
int get[MAXN][MAXN]={0};
int tmp = 0;
int32_t main(){
    cin>>n>>k;
    cin>>tmp;
    for(int i=n-1;i>=0;--i){
        get[i][i]=tmp%10;
        tmp /= 10;
    }
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){
            get[i][j]=get[i][j-1]*10+get[j][j];
        }
    }
    for(int i=0;i<n-1;++i){
        for(int j=i;j<n;++j){
            dp[i][j][0]=get[i][j];
        }
    }
    for(int d=1;d<=k;++d){
        for(int i=0;i<n-d-1;++i){
            for(int j=i+d;j<n;++j){
                for(int l = i;l<=j;++l){
                    dp[i][j][d] = max(dp[i][j][d],dp[i][l][d-1]*dp[l+1][j][d-1]);
                }
            }
        }
    }
    cout<<dp[0][n-1][k];
    return 0;
}
