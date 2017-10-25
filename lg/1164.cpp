#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    #define MAXN 100
    int m,n;
    int a[MAXN]={0};
    int ways[MAXN]={0};
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        cin>>a[i];
        //++ways[a[i]];
    }
    for(int i=0;i<m;i++)//初始化为f[1-n]=-inf，f[0]=0,相当于在0容量背包里装0合法，其余容量装0不合法 
      ways[i]=0;
      ways[0]=1;
    sort(a,a+n);
    for(int i=0;i<=m;++i){
        for(int j=0;j<n and i > a[j];++j){
            ways[i] += ways[i-a[j]];
        }
    }
    cout<<ways[m-1];
    return 0;
}