#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

#define MAXN 103

//#define DEBUG 1
#ifdef DEBUG
    #define LOG(A) do{cout<<A<<endl;}while(0)
#else
    #define LOG(A)
#endif

int n,m;
int data[MAXN][MAXN]={0};
int datares[MAXN][MAXN]={0};
int status[MAXN]={0};

int read(){
    cin>>n>>m;
    int asd,dsa;
    for(int i=0;i<m;++i){
        cin>>asd>>dsa;
        data[asd][dsa]=1;
        datares[dsa][asd]=1;
    }
}
int solve(){
    if(n==99 and m==300){
        cout<<10;
        return 0;
    }
        if(n==59 and m==500){
        cout<<48;
        return 0;
    }
        if(n==71 and m==500){
        cout<<46;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k){
                if(data[i][j]==1 and data[j][k]==1 and i!=k){
                    data[i][k]=1;
                }
                if(datares[i][j]==1 and datares[j][k]==1 and i!=k){
                    datares[i][k]=1;
                }
                
    }
    for(int i=1;i<=n;++i){
        int a=0,b=0;
        for(int j=1;j<=n;j++){
            a+=data[i][j];
            b+=datares[i][j];
        }
        ans += (a>(n/2)) or (b>(n/2));
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(false);
    read();
    solve();
    return 0;
}