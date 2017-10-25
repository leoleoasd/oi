#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
#define MAXN 420
struct edge{
    int to;
    int val;
    edge(int a,int b){
        to=a;
        val=b;
    }
};
struct Node{
    int id;
    int L;
    vector<struct edge> r;
    edge operator[](const int pos){
        return r[pos];
    }
    int size(){
        return r.size();
    }
    void add(int to,int value){
        r.push_back(edge(to,value));
    }
};
Node data[MAXN];
int n,m;
int dist[MAXN]={0};
#define INF 0xfffffff
void djstl(){
    bitset<MAXN> vis;
    for(int i=0;i<=n;++i){
        dist[i]=INF;
    }
    dist[0]=0;
    vis[0]=1;
    int l_min = INF;
    int l_pos = 0;
    for(int sum = 0;sum < n; ++sum){
        for(int i=0;i<=n;++i){
            if(dist[i]>l_min){
                dist[i]=l_min;
                l_pos=i;
            }
        }
        if(data[l_min].L > data[0].L+m or data[l_min].L < data[0].L+m){
            ++sum;
            v[l_min]=1;
            continue;
        }
        for(int i=0;i<data[l_min].size();++i){
            if(dist[data[l_min][i].to] > dist[l_min] + data[l_min][i].val){
                dist[data[l_min][i].to]=dist[l_min] + data[l_min][i].val;
            }
        }
    }
}
int main(){
    cin>>m>>n;
    int a,b,c;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
        data[0].add(i,a);
        data[i].add(0,a);
        data[i].L=b;
        for(int j=0;j<c;++j){
            cin>>a>>b;
            data[a].add(i,b);
            data[i].add(a,b);
        }
    }
    djstl();
    cout<<dist[1]<<endl;
    for(int i=0;i<=n;++i){
        cout<<i<<": ";
        for(int j=0;j<data[i].size();++j){
            cout<<"("<<data[i][j].to<<","<<data[i][j].value<<") ";
        }
        cout<<endl;
    }
    return 0;
}