#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <functional>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

#define DEBUG 1
#ifdef DEBUG
    #define LOG(A) do{cout<<A<<endl;}while(0)
#else
    #define LOG(A)l
#endif

#define MAXN 2000
#define min(A,B) (((A)>(B))?(A):(B))

int data[MAXN][MAXN]={0};
int m,n;
int from,to;
double bbb[MAXN][MAXN]={0};
int read(){
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        data[a][b]=c;
        data[b][a]=c;
    }
    cin>>from>>to;
}
struct paira{
    int from;
    int now;
};
int bfs(int ads){
    queue<struct paira> que;
    for(int i=1;i<=n;++i){
        if(data[i][ads]>=0){
            bbb[i][ads] = 100 * (1 + ( data[i][ads]/100.0 ));
            struct paira asd;
            asd.from = ads;
            asd.now = i;
            que.push(asd);
        }
    }
    while(!que.empty()){
        struct paira asd;
        asd = que.front();
        que.pop();
        for(int i=1;i<=n;++i){
            if(i==asd.from) continue;
            if(data[i][asd.now]>=0){
                bbb[i][asd.now] = min(bbb[i][asd.now],bbb[i][asd.from]*(1+(data[i][asd.now]/100.0)));
            }
        }
    }
}
int solve(){
    bfs(to);
    printf("%.8f",bbb[from][to]);
    //cout<<bbb[from][to]<<endl;
    
}
int main(){
    for(int i=0;i<MAXN;i++){
        for(int j=0;j<MAXN;++j){
            data[i][j]=-1000;
        }
    }
    read();
    solve();
    
    return 0;
}