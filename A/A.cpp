#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
#define int long long
#define MAXN 1000010
int f[MAXN]={0};
inline int get(int n){
    if(f[n]!=0) return f[n];
    f[n] = get(n-1)+get(n-2);
    return f[n];
}
int32_t main(){
    ios::sync_with_stdio(false);
    ifstream fin("A.in");
    ofstream fout("A.out");
    f[1]=1;
    f[2]=1;
    cout<<get(3);
    return 0;
}