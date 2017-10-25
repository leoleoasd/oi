#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
using std::priority_queue;
#define MAXN 1020
#define INF 0xfffffff
namespace Leo{
    int data[MAXN][MAXN]={0};
    bool visited[MAXN]={false};
    int dist[MAXN]={0};
    int n,m;
    int from,to,k;
    void rev_djstl(){
        for(int i=1;i<=n;++i){
            dist[i]=data[i][to];
            if(dist[i]==0){
                dist[i]=INF;
            }
        }
        visited[to]=1;
        int sum = 1;
        int max = -1;
        int pos = 0;
        while(sum != n){
            max = -1;
            pos = 0;
            for(int i=1;i<=n;++i){
                if(max < dist[i] and !visited[i]){
                    max = dist[i];
                    pos = i;
                }
            }
            visited[pos]=1;
            if(pos == 0 ){
                cout<<"fatal ERROR!!";
                return;
            }
            for(int i=1;i<=n;++i){
                if(dist[i] > dist[pos] + data[i][pos] and data[i][pos] != 0){
                    dist[i]=dist[pos]+data[i][pos];
                }
            }
            ++sum;
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
        que.push(Node(0,dist[from],from));
        int len,num;
        num = len = 0;
        while(!que.empty()){
            Node now = que.top();
            que.pop();
            if(now.id==to){
                ++num;
            }
            if(num >= k){
                return now.h;
            }
            for(int i=1;i<=n;++i){
                if(data[now.id][i]!=0){
                    que.push(Node(now.h+data[now.id][i],dist[i],i));
                }
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
        data[a][b]=c;
    }
    cin>>from>>to>>k;
    rev_djstl();
    cout<<Astar();
    return 0;
}