#include <iostream>
#include <fstream>
#include <map>
using namespace std;
#define MAXN 8080
map<int,int> SY;
int qzh[MAXN];
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
void precaoculate(){
    for(int i=0;i<n;++i){
        
    }
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