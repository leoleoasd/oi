#include <iostream>

using namespace std;

#define MAXN 210
int data[MAXN][MAXN]={0};
int n;
void read(){
    cin>>n;
    int a;
    for(int i=1;i<=n;++i){
        a=1;
        while(cin>>a,a){
            data[i][a]=1; 
        }
    }
}

void floyd(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(data[i][j]==1 and data[j][k]==1)
                    data[i][k]=1;
}

int father[MAXN]={0};

void solve(){
    for(int i=1;i<=n;++i){
        father[i]=i;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(data[i][j])
                father[j]=father[i];
        }
    }
    int sum=0;
    for(int i=1;i<=n;++i){
        if(father[i]==i)++sum;
    }
    cout<<sum;
}

int main(){
    read();
    floyd();
    solve();
    return 0;
}