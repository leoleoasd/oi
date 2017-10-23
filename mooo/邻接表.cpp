#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct na{
    map<int,int> e;//vector<struct edge> e;
    inline void add_edge(int to,int value){
        e[to]=value;
    }
    inline int operator[](const int num){
        /*
        for(int i=0;i<this->e.size();++i){
            if(this->e[i].to == num){
                return this->e[i].value;
            }
        }
        return 0;
        */
        map<int,int>::iterator iter = this->e.find(num);
        if(iter!=this->e.end())
        {
            return iter->second;
        }
        return 0;
    }
};
int main(){
    node data[200];
    int n,m;
    cin>>n>>m;
    int a,b,c;
    for(int i=0;i<m;++i){
        cin>>a>>b>>c;
        if(a==1){
            data[b].add_edge(c,1);
            data[c].add_edge(b,1);
        }else{
            data[b].add_edge(c,1);
        }
    }
    for(int i=0;i<n;++i){
        cout<<i<<":";
        for(int j=data[i].e.size()-1;j>=0;--j){
            cout<<" "<<data[i].e[j].to;
        }
        cout<<endl;
    }
    return 0;
}