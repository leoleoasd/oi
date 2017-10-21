#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct edge{
    int to;
    int value;
};
struct node{
    int id;
    vector<struct edge> e;
    void add_edge(int to,int value){
        struct edge asd;
        asd.to = to;
        asd.value = value;
        this->e.push_back(asd);
    }
};

int main(){
    node a;
    a.add_edge(1,2);
    a.add_edge(2,3);
    for(int i=0;i<a.e.size();++i){
        cout<<a.e[i].to<<" "<<a.e[i].value<<endl;;
    }
    return 0;
}