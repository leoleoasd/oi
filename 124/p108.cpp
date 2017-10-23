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
#define MAXN 2020
int data[MAXN][MAXN]={0};
int b = 0;
int d = 0;
int n;
bool visited[MAXN]={0};
int m;
void bfs(int pos){
    queue<int> que;
    visited[pos]=1;
    for(int i=1;i<=n;++i){
        if(data[pos][i]==1 and !visited[i]){
            que.push(i);
        }
    }
    if(b==0){
        b=1;
    }else{
        cout<<"-";
    }
    cout<<pos;
    while(!que.empty()){
        
        int now = que.front();
        visited[now]=1;
        que.pop();
        if(visited[now]) continue;
        cout<<"-"<<now;
        for(int i=1;i<=n;++i){
            if(data[now][i]==1 and !visited[i]){
                que.push(i);
            }
        }
    }
}
void dfs(int pos){
    if(visited[pos]){
        return;
    }
    visited[pos]=1;
    if(d==0){
        d=1;
    }else{
        cout<<"-";
    }
    cout<<pos;
    for(int i=1;i<=n;++i){
        if(data[pos][i]==1 and visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    int a,b;
    cin>>n>>m;
    ++m;
    while(--m){
        cin>>a>>b;
        data[a][b]=data[b][a]=1;
    }
    for(int i=1;i<=n;++i){
        if(!visited[i])
            dfs(i);
    }
    cout<<endl;
    for(int i=0;i<MAXN;++i)visited[i]=false;
    for(int i=1;i<=n;++i){
        if(!visited[i])
            bfs(i);
    }
    return 0;
}