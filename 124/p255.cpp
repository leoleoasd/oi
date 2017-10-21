#include<iostream>
#include <algorithm>
using namespace std;
#define MAXN 330
struct e{
    int from;
    int to;
    int value;
};
e edge[10020];
int father[MAXN]={0};
int rank[MAXN]={0};
int s = 0;
int num;
int n,m;
bool cmp(struct e a,struct e b){
    if(a.value != b.value){
        return a.value < b.value;
    }
    if(a.from != b.from){
        return a.from < b.from;
    }
    return a.to < b.to;
}
void read(){
    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>edge[i].from>>edge[i].to>>edge[i].value;
    }
}
inline void init(){
    for(int i=1;i<MAXN;++i){
        father[i]=i;
        rank[i]=1;
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
int maxa = -1;
void solve(){
    init();
    sort(edge,edge+m,cmp);
    for(int i=0;s<n-1;++i){
        if(getfather(edge[i].from) != getfather(edge[i].to)){
            merge(edge[i].from,edge[i].to);
            ++s;
            maxa = maxa > edge[i].value ? maxa : (edge[i].value);
        }
    }
    cout<<s<<" "<<maxa;
}
int main(){
    read();
    solve();
    //sort(edge,edge+m,cmp);
    //cout<<endl<<endl;
    //for(int i=0;i<m;++i){
    //    cout<<edge[i].from <<" "<< edge[i] . to <<" "<< edge[i]. value<<endl;;
    //}
    return 0;
}