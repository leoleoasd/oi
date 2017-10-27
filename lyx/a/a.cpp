#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdint.h>
using namespace std;
#define MAXN 10000000
uint8_t data[MAXN]={0};
int rd[MAXN]={0};
int main(){
    return 0;
}
/*
int ap[MAXN]={0};
vector<int> data[MAXN](vector<int>(0));
int n,q;
ifstream fin("a.in");
ofstream fout("a.out");
#define cin fin
#define cout fout
inline int calc(int a,int l,int r){
    int ret = 0;
    for(register int i=0;i<data[a].size();++i){
        if(l<=data[a][i] and data[a][i]<=r){
            ++ret;
        }
    }
    return ret;
}
inline void solve(int x,int y){
    int ret = 0;
    for(register int i=0;i<n;++i){
        for(register int j=0;j<n-i;++j){
            if(calc(x,i,i+j)==calc(y,i,i+j)){
                ++ret;
            }
        }
    }
    cout<<ret<<endl;
}
int main(){
    cin>>n>>q;
    for(register int i=0;i<n;++i){
        cin>>ap[i];
        data[ap[i]].push_back(i);
    }
    int x,y;
    for(register int i=0;i<q;++i){
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}*/
