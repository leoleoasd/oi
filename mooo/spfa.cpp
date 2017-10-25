#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <bitset>
using std::cin;
using std::cout;
using std::queue;
using std::vector;
using std::bitset;
using namespace std;
#define MAXN 420
#define INF 0xfffffff
struct node{
    int to;
    int value;
    node(int a,int b){
        to=a;
        value=b;
    }
};
vector < node > data[MAXN];
int n,m;
int dist[MAXN]={0};
void SPFA(int from){
    bitset<MAXN> inqueue;
    for(int i=1;i<=n;++i){
        dist[i]=INF;
    }
    dist[from]=0;
    queue<int> que;
    que.push(from);
    inqueue[from]=true;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        inqueue[now]=false;
        int len = data[now].size();
        for(int i=0;i<len;++i){
            if(dist[data[now][i].to] > dist[now] + data[now][i].value){
                dist[data[now][i].to] = dist[now] + data[now][i].value;
                if(!inqueue[data[now][i].to]){
                    inqueue[data[now][i].to]=true;
                    que.push(data[now][i].to);
                }
            }
        }
    }
}
int main(){
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        data[a].push_back(node(b,c));
    }
    SPFA(1);
    for(int i=2;i<=n;++i){
        if(dist[i]==INF){
            cout<<-32767<<" ";
        }else
        cout<<dist[i]<<" ";
    }
    return 0;
}