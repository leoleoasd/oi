//
// Created by Lu Leo on 2019/11/14.
//
#include <iostream>
#include <queue>
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
double xingjiabi[MAXN] = {0};

struct cmp{
    bool operator()(const pair<double, int> a, const pair<double, int> b){
        return a.first > b.first;
    }
};

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
            xingjiabi[i] = 1.0 * t[i] / j[i];
            sum += t[i];
        }
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
        priority_queue<pair<double, int>, vector<pair<double, int> >, cmp > que;
        for(int i = 0; i < n; ++ i) {
            que.push(make_pair(xingjiabi[i], i));
        }
        int rst = 0;
        while(!que.empty()){
            auto top = que.top();
            que.pop();
            if(t[top.second] > m){
                continue;
            }
            rst += j[top.second];
            m -= t[top.second];
        }
        cout<<rst<<endl;
        /*
        memset(dp,0,sizeof(dp));
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
         */
    }
    return 0;
}
