#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
#define MAXN 100000000
int ap[MAXN]={0};
vector<int> data[MAXN](vector<int>(0));
int n,q;
ifstream fin("a.in");
ofstream fout("a.out");
#define cin fin
#define cout fout
int calc(int a,int l,int r){
    int ret = 0;
    for(int i=0;i<data[a].size();++i){
        if(l<=data[a][i] and data[a][i]<=r){
            ++ret;
        }
    }
    return ret;
}
void solve(int x,int y){
    int ret = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i;++j){
            if(calc(x,i,i+j)==calc(y,i,i+j)){
                ++ret;
            }
        }
    }
    cout<<ret<<endl;
}
int main(){
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>ap[i];
        data[ap[i]].push_back(i);
    }
    int x,y;
    for(int i=0;i<q;++i){
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}