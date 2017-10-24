#include <iostream>
#include <map>
using namespace std;
#define MAXN 1000000

long long n,m;
long long rank[MAXN]={0};
long long father[MAXN]={0};
struct na{
    map<long long,long long> e;
    inline void add_edge(long long to,long long value){
        e[to]=value;
    }
    inline long long operator[](const long long num){
        map<long long,long long>::iterator iter = this->e.find(num);
        if(iter!=this->e.end())
        {
            return iter->second;
        }
        return 0;
    }
};
na node[MAXN];
void init(){
    for(long long i=1;i<=n;++i){
        father[i]=i;
    }
}
inline long long getfather(long long pos){
    if(father[pos]==pos){
        return pos;
    }else{
        father[pos]=getfather(father[pos]);
        return father[pos];
    }
}

inline void merge(long long a,long long b){
    long long fa,fb;
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
    long long tmp;
    for(long long i=1;i<=n;++i){
        cin>>rank[i];
        cin>>tmp;
        node[i].add_edge(tmp,1);
        node[tmp].add_edge(i,1);
    }
    for(long long i=1;i<=n;++i){
        for(long long j=1;j<=n;++j){
            if(node[i][j]==0){
                merge(i,j);
            }
        }
    }
    long long max = -1;
    for(long long i=1;i<=n;++i){
        if(rank[i]>max){
            max = rank[i];
        }
    }
    cout<<max;
    return 0;
    
}