#include <iostream>
using namespace std;
int main(){
    #define MAXN 1020
    int t,m;
    int f[MAXN]={0};
    int w[MAXN]={0};
    int v[MAXN]={0};
    cin>>t>>m;
    for(int i=1;i<=m;++i){
        cin>>v[i];
        cin>>w[i];
    }
    f[0]=0;
    for(int i=1;i<=m;++i){
        for(int j=t;j>=0;--j){
            if(j>v[i]){
                f[j] = max(f[j],f[j-w[i]]+v[i]);
            }
        }
    }
    cout<<f[t];
    return 0;
}
