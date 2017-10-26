#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 16
int data[MAXN][MAXN]={0};
bool vis[MAXN][MAXN]={false};
int r,c;
struct node{
    int x;
    int y;
    int value;
    node(int a,int b,int c){
        x=a;
        y=b;
        value=c;
    }
    bool operator<(node a){
        return value < a.value;
    }
};

int main(){
    cout<<(node(1,2,3)<node(1,2,2));
    //cin>>r>>c;
    
    return 0;
}