#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
#define MAXN 100
using namespace std;

//ifstream fin("a.in");
//ofstream fout("a.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
int sss[MAXN]={0};
int data[MAXN][MAXN]={0};
int n=0;
int read();
int solve();
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            data[i][j]=10000000;
            
    read();
    solve();
    return 0;
}
int read(){
    int a,b,c;
    int d=n;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
        sss[i]=a;
        data[i][b]=1;
        data[b][i]=1;
        data[i][c]=1;
        data[c][i]=1;
    }
}
int solve(){
    
}