#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::bitset;
int data[MAXN][MAXN]={0};
int t,u,v,w,sum,m;
int n;

void dfs(int from,int to,int & ret){
    if(from==to)return;
    for(int i=1;i<=n;++i){

    }
}
int findmax(int from,int to){
    int ret =  -1;
    dfs(from,to,ret);
    return ret;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<==n;++i)
            for(int j=1;j<=n;++j)
                data[i][j]=0;

        m = -1;
        sum = 0;
        for(int i=0;i<n-1;++i){
            cin>>u>>v>>w;
            m = max(w,m);
            sum += w;
        }
        cout<<(sum+(n*(n-1)/2 - (n-1) )*(m+1)  )<<endl;;
    }
    return 0;
}
