#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("B.in");
ofstream fout("B.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
#define MOD 998244353
void solve(){
    
    int n,m,k;
    fin>>n>>m>>k;
    for(int i=0;i<n*k;i++) fin>>m;
    int a=0;
    while(k!=1) {
        k/=2; 
        a++;
    }
    while(--a){
        k*=2;
    }
    k*=2;
    fout<<k;
    
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    fin>>n;
    while(n--){
        solve();
    }
    return 0;
}