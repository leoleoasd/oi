#include <iostream>
using namespace std;

#define MAXN 45
int data[MAXN][MAXN] = {0};
int n,m;

int rst = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= m; ++ j){
            cin>>data[i][j];
        }
    }
    for(int i = 1; i <= n; ++ i ){
        for(int j = 1; j <= m; ++ j){

        }
    }
    cout<<rst<<endl;
    return 0;
}