#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");
#define cin fin
#define cout fout

#define MAXN 16
long long  data[MAXN][MAXN]={0};
bool vis[MAXN][MAXN]={false};
long long  r,c,now;
long long output;
long long  maxa;
#define max(A,B) (((A)>(B))?(A):(B))
struct node{
    long long  x;
    long long  y;
    long long  value;
    node(){
        x=y=value=0;
    }
    node(long long  a,long long  b,long long  c){
        x=a;
        y=b;
        value=c;
    }
    bool operator<(node a){
        return value < a.value;
    }
    bool operator>(node a){
        return value > a.value;
    }
};
bool cmp(node a,node b){
    return a.value > b.value;
}
node P[MAXN*MAXN];
long long  pos;
long long  dfs(long long  x,long long  y,long long  & ret){
    if(x<1 or y<1 or x>r or y>c or data[x][y]==-1 or vis[x][y]){
        return 0;
    }
    vis[x][y]=true;
    node P[4];
    long long  p=0;
    if(x>1){
        P[p].x=x-1;
        P[p].y=y;
        P[p].value=data[x-1][y];
        ++p;
    }
    if(y>1){
        P[p].x=x;
        P[p].y=y-1;
        P[p].value=data[x][y-1];
        ++p;
    }
    if(x<r){
        P[p].x=x+1;
        P[p].y=y;
        P[p].value=data[x+1][y];
        ++p;
    }
    if(y<c){
        P[p].x=x;
        P[p].y=y+1;
        P[p].value=data[x][y+1];
        ++p;
    }
    sort(P,P+p,cmp);
    ret = ret * 10 + data[x][y];
    long long  maxa = -1;
    long long  tmp = ret;
    for(int i=0;i<p;++i){
        tmp = ret;
        dfs(P[i].x,P[i].y,tmp);
        maxa = max(tmp,maxa);
        if((long long )log10(maxa) == pos-1){
            break;
        }
    }
    ret = maxa;
    vis[x][y]=false;
}
int main(){
    cin>>r>>c;
    char tmp;
    while(!r==0 and !c==0){
        pos=0;
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                cin>>tmp;
                if(tmp=='#'){
                    data[i][j]=-1;
                }else{
                    data[i][j]=tmp-'0';
                    P[pos]=node(i,j,data[i][j]);
                    ++pos;
                }
            }
        }
        sort(P,P+pos,cmp);
        maxa = -1;
        output = 0;
        long long  ret;
        for(int i=0;i<pos;++i){
            ret=0;
            dfs(P[i].x,P[i].y,ret);
            maxa = max(maxa,ret);
            if((long long )log10(maxa) == pos-1){
                break;
            }
        }
        if(maxa==-1){
            maxa=0;
        }
        cout<<maxa<<endl;
        cin>>r>>c;
    }
    return 0;
}