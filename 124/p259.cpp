#include <iostream>
#include <fstream>
#include <cstdlib>
#include <queue>

//using namespace std;
#define cin std::cin
#define cout std::cout
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
        while(sum != n){
            for(int i=1;i<n;++i){

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
    return 0;
}