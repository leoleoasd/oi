#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct no{
    int l;
    int r;
    int value;
    
};

#define tree_size 23
void buildtree(int l,int r,int root,struct tree asd);
struct tree{
    no node[tree_size];
    tree(int l,int r){
        buildtree(l,r,0,*this);
    }
};
void buildtree(int l,int r,int root,struct tree & tr){
    tr.node
}
int main(){
    return 0;
}