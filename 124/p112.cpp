#include <iostream>
using namespace std;

#define MAXN 1020
int n=0;
int data[MAXN][MAXN]={0};
#define INF 0x7fffffff
int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j){
            cin>>data[i][j];
            if(data[i][j]==0) data[i][j]=INF;
        }
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(data[i][j] > data[i][k]+data[k][j])
                    data[i][j]=data[i][k]+data[k][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(data[i][j]==INF)data[i][j]=0;
            if(i==j)data[i][j]=0;
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
