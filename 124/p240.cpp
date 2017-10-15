#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <queue>

using namespace std;
int solve();
int n,m;
int main(){
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
#define MAXN 105
int A[MAXN]={0};
int B[MAXN]={0};

int solve(){
    int a,b;
    
    cin>>n>>m;
    while(m--){
        cin>>a>>b;
        data[a][b]=1;
    }
    int res=0;
    int poi=(n/2)+1;
    for(int i=1;i<=n;i++){
        if(A[i] >= poi or B[i] >= poi){
            res++;
        }
    }
    cout<<res;
    return 0;
}