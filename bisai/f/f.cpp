#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define MAXN 16
int data[MAXN][MAXN]={0};
bool vis[MAXN][MAXN]={false};
int r,c,now,sum;
int output;
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
int pos;
int main(){
    cin>>r>>c;
    char tmp;
    while(!r==0 and !c==0){
        for(int i=1;i<=r;++i){
            for(int j=1;j<=c;++j){
                cin>>tmp;
                if(tmp=='#'){
                    data[i][j]=-1;
                }else{
                    data[i][j]=tmp-'0';
                    P[pos]=node(i,j,data[i][j]);
                    ++sum;
                }
            }
        }
        sort(P,P+pos);
        for(int i=0;i<pos;++i){
            cout<<P[i].x<<P[i].y<<P[i].value;
        }
        cin>>r>>c;
    }
    return 0;
}