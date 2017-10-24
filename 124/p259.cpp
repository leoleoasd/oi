#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
using std::cin;
using std::cout;
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
        int sum = 1;
        int max = -1;
        int pos = 0;
        while(sum != n){
            max = -1;
            pos = 0;
            for(int i=1;i<=n;++i){
                if(max < dist[i]){
                    max = dist[i];
                    pos = i;
                }
            }
            if(pos == 0 ){
                cout<<"fatal ERROR!!";
                return;
            }
            for(int i=1;i<=n;++i){
                if(dist[i] > dist[pos] + data[i][pos]){
                    dist[i]=dist[pos]+dist[i][pos];
                }
            }
        }
    }
    int max = -1;
}
using namespace Leo;
int main(){
    cout<<max;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        data[a][b]=c;
    }
    cin>>from>>to>>k;
    rev_djstl();
    for(int i=1;i<=n;++i){
        cout<<dist[i]<<" ";
    }
    return 0;
}