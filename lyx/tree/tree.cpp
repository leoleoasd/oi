#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::bitset;

std::ifstream fin("tree.in");
std::ofstream fout("tree.out");
#define cin fin
#define cout fout


#define MAXN 15020
int data[MAXN][MAXN]={0};
int t,u,v,w,sum,m;
int n;
bitset<MAXN> vis;
void dfs(int from,int to,int & ret){
    vis[from]=1;
    if(from==to)return;
    for(int i=1;i<=n;++i){
        if(!vis[i] and data[from][i]!=0){
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
            data[v][u]=w;
        }
        int output = 0;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                if(data[i][j]==0){
                    data[i][j]=findmax(i,j)+1;
                }
                output += data[i][j];
            }
        }
        cout<<output<<endl;
    }
    return 0;
}
