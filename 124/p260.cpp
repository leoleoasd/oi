#include <iostream>
#include <cstdlib>
using namespace std;
#define MAXN 600
int data[MAXN][MAXN]={0};
int x[MAXN]={0};
int y[MAXN]={0};
void kill(int a,int b){
    data[a][b]=0;
    --x[a];
    --y[b];
}
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;++i){
        cin>>a>>b;
        data[a][b]=1;
        x[a]++;
        y[b]++;
    }
    bool flag = false;
    int max;
    int xx;
    int step = 0;
    do{
        flag = false; 
        max = -1;
        for(int i=0;i<=n;++i){
            if(x[i]>max){
                max = x[i];
                xx=i;
            }
            if(x[i]!=0){
                flag = true;
            }
        }
        for(int i=0;i<=n;++i){
            if(y[i]>max){
                max = y[i];
                xx = -i;
            }
        }
        if(xx>0){
            for(int i=1;i<=n;++i){
                if(data[xx][i]!=0){
                    kill(xx,i);
                }
            }
        }else{
            xx = -xx;
            for(int i=1;i<=n;++i){
                if(data[i][xx]!=0){
                    kill(i,xx);
                }
            }
        }
        ++step;
    }while(flag);
    cout<<step;
    return 0;
}