#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
bool flag(int x1,int y1,int x2,int y2,int x3,int y3){
    if(x1 == x2 and x2==x3){
        return true;
    }
    return ((double)(x2-x1)/(y2-y1))==((double)(x3-x2)/(y3-y2));
}
double dist(int x1,int y1,int x2,int y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
struct p{
    int x;
    int y;
}goodman[305],badman[110];
int x,y,n,m;
#define MAXN 305
#define INF 0x3f3f3f3f
double data[305][305]={0};
double dist[MAXN]={0};
int vis[MAXN]={0};
int main(){
    ios::sync_with_stdio(false);
    cin>>x>>y>>n>>m;
    int a,b;
    for(int i=1;i<=n;++i){
        cin>>a>>b;
        goodman[i].x=a;
        goodman[i].y=b;
        for(int j=1;j<i;++j){
            data[j][i]=data[i][j]=dist(a,b,goodman[j].x,goodman[j].y);
        }
        data[0][i]=data[i][0]=dist(a,b,x,y)*2;
    }
    for(int i=1;i<=m;++i){
        cin>>a>>b;
        for(int i=0;i<=n;++i){
            for(int j=i;j<=n;++j){
                if(data[i][j]){
                    if(flag(goodman[i].x,goodman[i].y,goodman[j].x,goodman[j].y,a,b)){
                        data[i][j]=data[j][i]=0;
                    }
                }
            }
        }
    }
    // DJSTL
    for(int i=0;i<=n;++i){
        dist[i]=data[1][i];
    }
    dist[1]=INF;
    vis[1]=1;
    int minn;
    int pos;
    for(int asdasdasd=0;asdasdasd<n;++asdasdasd){
        minn = INF;
        for(int i=0;i<=n;++i){
            if(minn > dist[i] and vis[i]==0){
                minn = dist[i];
                pos = i;
            }
        }
        vis[pos]=1;
        for(int i=0;i<=n;++i){
            dist[i]=min(dist[i],dist[pos]+data[pos][i]);
        }
    }
    cout<<dist[0];
    return 0;
}
