#include <iostream>
#include <stdint.h>
using namespace std;
#define MAXN 1000000
#define int long long

int n,m;
int data[MAXN][MAXN];
int rank[MAXN]={0};
int father[MAXN]={0};
void init(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            data[i][j]=1;
        }
    }
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

int32_t main(){
    cin>>n;
    init();
    int tmp;
    for(int i=1;i<=n;++i){
        cin>>rank[i];
        cin>>tmp;
        data[i][tmp]=0;
        data[tmp][i]=0;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(data[i][j]){
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