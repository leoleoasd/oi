#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct no{    //[l,r] 闭区间
    int l;
    int r;
    int value;
    
};

#define tree_size 23

struct tree{
    no node[tree_size];
    tree(int l,int r){
        buildtree(l,r,0,*this);
    }
};

int main(){
    return 0;
}