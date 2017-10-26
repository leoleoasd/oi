#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 16
int data[MAXN][MAXN]={0};
bool vis[MAXN][MAXN]={false};
int r,c;,now,sum;
struct node{
    int x;
    int y;
    int value;
    node(){
        x=y=value=0;
    }
    node(int a,int b,int c){
        x=a;
        y=b;
        value=c;
    }
    bool operator<(node a){
        return value < a.value;
    }
    bool operator>(node a){
        return value > a.value;
    }
};
node P[MAXN];

int main(){
    cin>>r>>c;
    while(r!=0 and c!=0){
        cout<<123<<endl;
        cin>>r>>c;
    }
    return 0;
}