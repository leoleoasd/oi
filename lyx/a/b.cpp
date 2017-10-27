#include <iostream>
#include <fstream>
#include <map>
using namespace std;
ifstream fin("a.in");
ofstream fout("a.out");
#define cin fin
#define cout fout
#define MAXN 8080
map<int,int> SY;
int qzh[MAXN][MAXN]={0};
int pos = 0;
int data[MAXN]={0};
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
}
int get(int x,int pos){
    int sy = find(x);
    if(x==-1){
        return 0;
    }
    return qzh[x][pos]; 
}
int calc(int x,int l,int r){
    if(l==0){
        return get(x,r);
    }else{
        return get(x,r)-get(x,l-1);
    }
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