#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

#define MAXN 1000010
ifstream fin("bus.in");
ofstream fout("bus.out");
#define cin fin
#define cout fout
struct edge{
    int to;
    int value;
};
struct na{
    vector<struct edge> e;
    inline void add_edge(int to,int value){
        struct edge asd;
        asd.to = to;
        asd.value = value;
        this->e.push_back(asd);
    }
    inline int operator[](const int num){
        for(int i=0;i<this->e.size();++i){
            if(this->e[i].to == num){
                return this->e[i].value;
            }
        }
        return 0;
    }
};
na node[MAXN];
int n,maxc;
void aoutput(){
    for(int i=0;i<n;++i){
        cout<<i<<":";
        for(int j=node[i].e.size()-1;j>=0;--j){
            cout<<" "<<node[i].e[j].to;
        }
        cout<<endl;
    }
}
inline void read(){
    int a,b;
    cin>>n>>maxc;
    
    for(int i=0;i<n;++i){
        cin>>a>>b;
        for(int j=i+a,k=1;j<=n;j+=a,++k){
            node[i].add_edge(j,b*k);
        }
    }
    ++n;
    //output();
}
int dist[MAXN]={0};
bool visited[MAXN]={0};
inline void solve(){
    for(int i=0;i<n;++i){
        dist[i]=(node[0][i]!=0)?node[0][i]:0x7fffffff;
    }
    dist[0]=0;
    visited[0]=true;
    for(int v = 1;v<=n;++v){
        int min = 0x7fffffff;
        int a = 0;
        for(int i=1;i<n;++i){
            if(!visited[i] and dist[i] < min){
                min = dist[i];
                a=i;
            }
        }
        visited[a] = true;
        int tmp;
        for(int i=0;i<n;++i){
            tmp=node[a][i];
            if(tmp !=0){
                if(tmp + dist[a] < dist[i]){
                    dist[i] = tmp + dist[a];
                }
            }
        }
    }
}
void output(){
    for(int i=1;i<n;++i){
        if(dist[i]==0x7fffffff){
            cout<<-1<<" ";
        }else{
            cout<<dist[i]<<" ";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    read();
    solve();
    output();
    return 0;
}