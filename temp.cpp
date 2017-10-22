
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1020

int father[MAXN]={0};
int rank[MAXN]={0};
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
int n,m;
int main(){
    cin>>n>>m;
    init();
    int a,b;
    while(--m){
        cin>>a>>b;
        merge(a,b);
    }
    int output=0;
    for(int i=1;i<=n;++i){
        if(rank[i]!=0)++output;
    }
    cout<<output-1;
}