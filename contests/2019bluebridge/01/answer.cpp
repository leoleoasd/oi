//
// Created by Lu Leo on 2019/11/14.
//
#include <iostream>
#include <cstring>
using namespace std;


/*
#include <iostream>
using namespace std;
int main(){
    #define MAXN 1020
    int t,m;
    int f[MAXN]={0};
    int w[MAXN]={0};
    int v[MAXN]={0};
    cin>>t>>m;
    for(int i=1;i<=m;++i){
        cin>>w[i];
        cin>>v[i];
    }
    f[0]=0;
    for(int i=1;i<=m;++i){
        for(int j=t;j>=0;--j){
            if(j>=w[i]){
                f[j] = max(f[j],f[j-w[i]]+v[i]);
            }
        }
    }
    cout<<f[t];
    return 0;
}
 */

#define MAXN 10000010
int t[MAXN] = {0};
int j[MAXN] = {0};
int dp[MAXN] = {0};
// t * m * n <= 1e7
// 娱乐度可以小于0
// t 10
// n 10000
// m 10000
// mem 10k
// m: 1000010 t: 10 1s

int main(){
    int T;
    int n,m,w;
    int sum;
    cin>>T;
    while(T--){
        cin>>n>>m>>w;
        sum = 0;
        for(int i = 0; i < n; ++ i){
            cin>>t[i]>>j[i];
            sum += t[i];
        }
        memset(dp,0,(m+1)*sizeof(int));
        /*
        if(sum <= m){
            // AK
            sum = 0;
            int maxx = -1e7;
            for(int i = 0; i < n; ++ i){
                sum += j[i];
                maxx = (maxx > j[i] ? maxx : j[i]);
            }
            sum -= maxx;
            cout<<"AK "<<sum<<endl;
            continue;
        }
         */
        int flag = 0;
        for(int i = 0; i < n; ++ i){
            if(t[i] < m){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            // Looser
            cout<<"Looser!"<<endl;
            continue;
        }
        for(int i=0;i<n;++i){
            for(int l=m;l>=0;--l){
                if(l>=t[i]){
                    dp[l] = max(dp[l],dp[l-t[i]]+j[i]);
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
