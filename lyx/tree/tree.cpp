#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::bitset;

#define MAXN 15020
int data[MAXN][MAXN]={0};
int t,u,v,w,sum,m;
int n;
bitset<MAXN> vis;
void dfs(int from,int to,int & ret){
    v[from]=1;
    if(from==to)return;
    for(int i=1;i<=n;++i){
        if(!v[i] and data[from][i]!=0){
            dfs(i,to,ret);
            ret = max(ret,data[from][i]);
            if(i==to) return;
        }
    }
}
int findmax(int from,int to){
    vis=0;
    int ret =  -1;
    dfs(from,to,ret);
    return ret;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                data[i][j]=0;
        for(int i=0;i<n-1;++i){
            cin>>u>>v>>w;
            data[u][v]=w;
        }
        cout<<finsmax(1,3);
        cout<<(sum+(n*(n-1)/2 - (n-1) )*(m+1)  )<<endl;;
    }
    return 0;
}
