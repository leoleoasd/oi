#include <iostream>
using namespace std;

#define MAXN 1020
int n=0;
int data[MAXN][MAXN]={0};

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>data[i][j];
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(data[i][j] > data[i][k]+data[k][j])
                    data[i][j]=data[i][k]+data[k][j];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            cout<<data[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
