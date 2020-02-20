#include <iostream>
using namespace std;

#define MAXN 1020
int sum = 0;
int n;
int k=0;
struct e{
    int from;
    int to;
};
e edge[MAXN];
int father[MAXN]={0};
int rank[MAXN]={0};
inline void read(){
    int tmp,temp;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>tmp;
        for(int j=0;j<tmp;++j){
            cin>>temp;
            if(temp > i){
                edge[sum].from=i;
                edge[sum].to=temp;
                ++sum;
            }
        }
    }
}

inline void init(){
    for(int i=1;i<=1010;++i){
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
void solve(){
    int max = n;
    while(max > n/2){
        max=-1;
        ++k;
        init();
        for(int i=0;i<sum;++i){
            if(edge[i].from > k and edge[i].to > k){
                merge(edge[i].from,edge[i].to);
            }
        }
        for(int i=1;i<=n;++i){
            max = (rank[i] > max)?rank[i] : max;
        }
    }
    cout<<k;
}

int main(){
    
    read();
    solve();
    return 0;
}