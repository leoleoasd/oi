#include <iostream>
#include <algorithm>
using namespace std;
int i,j,T,n,p[10001],w[10001],f[10020],m;
int main(){
    while(cin>>n>>m){
        for(i=1;i<=n;i++)
            cin>>p[i]>>w[i];
        for(int i = 0; i < 10020; ++ i){
            f[i] = 0;
        }
        for(i=1;i<=n;i++)
            for(j=p[i];j<=10020;j++)
                f[j]=max(f[j],f[j-p[i]]+w[i]);
        for(int i = 1; i < 10020; ++ i){
            if(f[i] >= m){
                cout<<i<<" "<<f[i]<<endl;
                continue;
            }
        }
    }
    return 0;
}