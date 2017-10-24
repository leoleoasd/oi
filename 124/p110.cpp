#include <iostream>
#define MAXN 50
using namespace std;

int n,m;
int a,b,c;
int output=0;
int data[MAXN][MAXN]={0};
int dist[MAXN]={0};
int main(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        data[a][b]=c;
        data[b][a]=c;
    }
    int from,to;
    cin>>from>>to;
    for(int i=0;i<=n;++i){
        dist[i]=data[from][i];
        if(dist[i]==0)
            dist[i]=0x7ffffff;
    }
    int V[MAXN]={0};
    int sum = 1;
    V[from]=1;
    for(;sum < n;++sum){
        int min = 0x7ffffff;
        int u = from;
        for(int i=1;i<=n;++i){
            if((!V[i]) and dist[i]<min){
                min = dist[i];
                u = i;
            }
        }
        //cout<<u<<endl;
        V[u]=1;
        for(int i=1;i<=n;++i){
            if(data[u][i] + dist[u] < dist[i] and data[u][i]!=0){
                dist[i]=data[u][i]+dist[u];
            }
        }
    }
    cout<<dist[to]<<endl;
    return 0;
}