#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    #define MAXN 100
    int m,n;
    int a[MAXN]={0};
    int ways[MAXN]={0};
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>a[i];
        //++ways[a[i]];
    }
    ways[0]=1;
    sort(a,a+n);
    for(int i=0;i<n;i++)
    for(int j=m;j>=a[i];j--)
    ways[j]+=ways[j-a[i]];
    cout<<ways[m];
    return 0;
}