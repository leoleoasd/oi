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
int num=0;
struct node{
    int id;
    int first;
    node(){
        this->id=0;
        this->first=0;
    }
    void add_road(int to,int value){
        int fr = this->first;
        bian[num].to=to;
        bian[num].value=value;
        bian[num].next=fr;
        ++num;
        this->first=num-1;
    }
} w[2000];
struct bian{
    int to;
    int next;
    int value;
    bian(){
        this->to=0;
        this->next=0;
        this->value=0;
    }
} list[20000];
int n,m;
int dd=0;
int dfs(int now){
    if(dd!=0){
        
    }
}
void bfs(){
    
}
void init(){
    for(int i=1;i<=1999;i++){
        node[i].id=i;
    }
}

int main(){
    init();
    int a,b;
    cin>>n>>m;
    while(--m){
        cin>>a>>b;
        add_road(a,b,1);
    }
    bfs();
    dfs();
    return 0;
}