#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>
using std::cin;
using std::cout;
using std::endl;
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
            cout<<pos<<endl;
            for(int i=1;i<=n;++i){
                if(dist[i] > dist[pos] + data[i][pos] and data[i][pos] != 0){
                    dist[i]=dist[pos]+data[i][pos];
                }
            }
            ++sum;
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
    for(int i=1;i<=n;++i){
        if(dist[i]==INF){
            cout<<"-1 ";
            continue;
        }
        cout<<dist[i]<<" ";
    }
    return 0;
}