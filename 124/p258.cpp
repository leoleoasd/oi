#include <iostream>
#include <queue>
#include <bitset>
using namespace std;
#define MAXN 420
struct edge{
    int to;
    int value;
    edge(int a,int b){
        to=a;
        value=b;
    }
};
struct Node{
    int id;
    int L;
    vector<struct edge> r;
    int operator[](const int pos){
        return r[pos];
    }
    int size(){
        return r.size();
    }
    void add(int to,int value){
        r.push_back(edge(to,value));
    }
};
Node data[MAXN];
int n,m;
int main(){
    cin>>m>>n;
    int a,b,c;
    for(int i=1;i<=n;++i){
        cin>>a>>b>>c;
        data[0].add(i,a);
        data[i].L=b;
        for(int j=0;j<c;++j){
            cin>>a>>b;
            data[a].add(i,b);
            data[i].add(a,b);
        }
    }
    for(int i=0;i<=n;++i){
        cout<<i<<": ";
        for(int j=0;j<data[i].size();++j){
            cout<<"("<<data[i][j].to<<","<<data[i][j].value<<") ";
        }
    }
    return 0;
}