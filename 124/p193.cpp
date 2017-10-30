#include <iostream>
#include <algorithm>
#include <vector>
//using namespace std;
using std::cin;
using std::cout;
using std::vector;
using std::ios;
using std::endl;
#define MAXN 5050
vector<int> output;
int data[MAXN][MAXN]={0};
int n,m,q;
struct p{
    p(){}
    p(int x,int y,int z){
        a=x;
        b=y;
        c=z;
    }
    int a,b,c;
} cz[MAXN];

int father[MAXN]={0};
inline void init(){
    for(int i=1;i<MAXN;++i){
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
    }else{
        father[fb]=fa;
    }
}
void solve(int cmd,int x,int y){
    if(cmd==1){
        merge(x,y);
        return;
    }
    if(cmd==2){
        output.push_back(getfather(x)==getfather(y));
        return;
    }
    int out = 0;
    for(int i=1;i<=n;++i){
        if(getfather(i)==i)++out;
    }
    output.push_back(out);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    int x,y;
    init();
    for(int i=0;i<m;++i){
        cin>>x>>y;
        data[x][y]=data[y][x]=1;
    }
    int z;
    for(int i=q-1;i>=0;--i){
        cin>>x;
        if(x==1){
            cin>>y>>z;
            cz[i]=p(x,y,z);
            data[y][z]=data[z][y]=0;
        }
        if(x==2){
            cin>>y>>z;
            cz[i]=p(x,y,z);
        }
        if(x==3){
            cz[i]=p(3,0,0);
        }
    }
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            if(data[i][j])merge(i,j);
        }
    for(int i=1;i<=n;++i){
        cout<<getfather(i)<<" ";
    }
    cout<<endl;
    for(int i=0;i<q;++i){
        solve(cz[i].a,cz[i].b,cz[i].c);
    }
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<endl;
    }
    return 0;
}
