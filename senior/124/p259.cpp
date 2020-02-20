#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
using std::vector;
using std::greater;
#define MAXN 1020
#define INF 0xfffffff
namespace Leo{
    //int data[MAXN][MAXN]={0};
    struct node{
        int to;
        int val;
        node(int a,int b){
            to=a;
            val=b;
        }
    };
    vector<node> data[MAXN],_data[MAXN];
    bool visited[MAXN]={false};
    int dist[MAXN]={0};
    int n,m;
    int from,to,k;
    void rev_djstl(){
        priority_queue<int , vector<int> , greater<int> > q;  
        for(int i=1;i<=n;++i){
            dist[i]=INF;
        }
        visited[to]=1;
        dist[to]=0;
        q.push(to);
        int u;
        while(!q.empty()){
            u = q.top();
            q.pop();
            for(int i=0;i<_data[u].size();++i){
                node v = _data[u][i];
                if(dist[v.to] > dist[u]+v.val){
                    dist[v.to]=dist[u]+v.val;
                    if(!visited[v.to]){
                        q.push(v.to);
                        visited[v.to]=true;
                    }
                }
            }
            visited[u]=false;
        }
    }
    struct Node{
        int h;  //当前已经走了多远
        int g;  //到达目标点所需的代价
        int id;
        Node(int a,int b,int c){
            h=a; g=b; id=c; 
        }    
        bool operator < (Node a) const
        {
            return h+g > a.h+a.g;
        }
    };
    int Astar(){
        priority_queue<Node> que;
        while(!que.empty()) que.pop();  
        que.push(Node(0,dist[from],from));
        int num;
        num = 0;
        while(!que.empty()){
            Node now = que.top();
            que.pop();
            if(now.id==to){
                ++num;
            }
            if(num >= k){
                return now.h;
            }
            for(int i=0;i<data[now.id].size();++i){
                que.push(Node(now.h+data[now.id][i].val,dist[data[now.id][i].to],data[now.id][i].to));
            }
        }
    }
}
using namespace Leo;
int main(){
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        data[a].push_back(node(b,c));
        _data[b].push_back(node(a,c));
    }
    cin>>from>>to>>k;
    rev_djstl();
    cout<<Astar();
    return 0;
}