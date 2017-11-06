#include <iostream>
#include <vector>
#include <cstdio>
#include <stdint.h>

//using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

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
    int a,b;
    while(1){
        cin>>a>>b;
        cout<<get[a][b]<<endl;
    }
    return 0;
}
