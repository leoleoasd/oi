#include <iostream>
#include <string>
using namespace std;
char map[1024][1024] = {0};
void dfs(int x, int y, int size, int type){
    if(size == 0){
        map[x][y] = type ? 'C' : 'P';
        map[x+1][y] = !type ? 'C' : 'P';
        map[x][y+1] = type ? 'C' : 'P';
        map[x+1][y+1] = type ? 'C' : 'P';
    }else {
        dfs(x,y,size-1,type);
        dfs(x + (2<<(size-1)),y,size-1,!type);
        dfs(x,y + (2<<(size-1)),size-1,type);
        dfs(x + (2<<(size-1)),y + (2<<(size-1)),size-1,type);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        dfs(0,0,n-1,1);
        for(int i = 0; i < 2<<n-1; ++ i){
            for(int j = 0; j < 2<<n-1; ++ j){
                cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}