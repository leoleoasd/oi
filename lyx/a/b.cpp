#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define MAXN 8080
map<int,int> SY;
int qzh[MAXN][MAXN];
int pos = 0;
int data[MAXN];
int n,q;
int find(int i){
    if(SY.find(i)==SY.end()){
        return -1;
    }else{
        return SY.find(i)->second;
    }
}
void pre_calculate(){
    for(int i=0;i<n;++i){
        int sy = find(data[i]);
        if(sy==-1){
            SY[data[i]]=pos;
            sy = pos;
            ++pos;
        }
        int sum = 0;
        for(int j=0;j<n;++j){
            if(data[j]==data[i]){
                ++sum;
            }
            qzh[sy][j]=sum;
        }
    }
    for(int i=0;i<n;++i){
        cout<<qzh[find(1)][i]<<" ";
    }
}
void solve(int x,int y){
    
}
int main(){
    cin>>n>>q;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }
    int x,y;
    pre_calculate();
    for(int i=0;i<q;++i){
        cin>>x>>y;
        solve(x,y);
    }
    return 0;
}