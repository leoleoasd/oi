#include <iostream>
using namespace std;
#define MAXN 8
int n,m;
int visited[MAXN][MAXN] = {0};
int sx,sy,fx,fy;
int output = 0;
int t;
int za[MAXN][MAXN] = {0};

void dfs(int x,int y){
    if(x == fx and y == fy){
        output += 1;
        return;
    }
    if(visited[x][y]){
        return;
    }
    if(x < 1 or x > n){
        return;
    }
    if(y < 1 or y > m){
        return;
    }
    visited[x][y] = 1;
    //cout<<"Visiting "<<x<<" "<<y<<endl;
    if(za[x+1][y] == 0){
        dfs(x+1,y);
    }
    if(za[x-1][y] == 0){
        dfs(x-1,y);
    }
    if(za[x][y+1] == 0){
        dfs(x,y+1);
    }
    if(za[x][y-1] == 0){
        dfs(x,y-1);
    }

    visited[x][y] = 0;
}

int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    int x,y;
    for(int i = 0; i < t; ++ i){
        cin>>x>>y;
        za[x][y] = 1;
    }
    dfs(sx,sy);
    cout<<output<<endl;
    return 0;
}