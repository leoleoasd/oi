#include <iostream>
using namespace std;
#define MAXN 1000000

int n,m;
int rank[MAXN]={0};
int father[MAXN]={0};
struct na{
    map<int,int> e;
    inline void add_edge(int to,int value){
        e[to]=value;
    }
    inline int operator[](const int num){
        map<int,int>::iterator iter = this->e.find(num);
        if(iter!=this->e.end())
        {
            return iter->second;
        }
        return 0;
    }
};
na node[MAXN];
void init(){
    for(int i=1;i<=n;++i){
        father[i]=i;
    }
}
inline int getfather(int pos){
    if(father[pos]==pos){
        return pos;
    }else{
        father[pos]=getfather(father[pos]);
        return father[pos];
    }
}

inline void merge(int a,int b){
    int fa,fb;
    fa = getfather(a);
    fb=  getfather(b);
    if(fa==fb){
        return;
    }
    if(fa>fb){
        father[fa]=fb;
        rank[fb]+=rank[fa];
        rank[fa]=0;
    }else{
        father[fb]=fa;
        rank[fa]+=rank[fb];
        rank[fb]=0;
    }
}

int main(){
    cin>>n;
    init();
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>rank[i];
        cin>>tmp;
        node[i].add_edge(tmp,1);
        node[tmp].add_edge(i,1);
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(node[i][j]==0){
                merge(i,j);
            }
        }
    }
    int max = -1;
    for(int i=1;i<=n;++i){
        if(rank[i]>max){
            max = rank[i];
        }
    }
    cout<<max;
    return 0;
    
}