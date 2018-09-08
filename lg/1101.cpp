#include <iostream>
using namespace std;

#define MAXN 105

int n = 0;

string datas[MAXN];
string target = "yizhong";

int visiable[MAXN][MAXN] = {0};

int directions[8][2] = {
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1},
    {-1,0},
    {-1,1},
};

void dfs(int i,int j,int pos,int di){
    //cout<<"dfs"<<i<<" "<<j<<" "<<target[pos]<<" "<<di<<" "<<endl;
    if(pos == 6){
        for(int _t = 0; _t < 7;i -= directions[di][0],j -= directions[di][1], ++_t){
            visiable[i][j] = 1;
        }
        return;
    }
    if( i + directions[di][0] < n and
        i + directions[di][0] >=0 and
        j + directions[di][1] < n and
        j + directions[di][1] >=0 and
        datas[i + directions[di][0]][j + directions[di][1]] == target[pos+1])
        dfs(i + directions[di][0],j + directions[di][1],pos+1,di);
}

int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>datas[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(datas[i][j] == 'y'){
                for(int di = 0; di < 8; ++di){
                    if( i + directions[di][0] < n and
                        i + directions[di][0] >=0 and
                        j + directions[di][1] < n and
                        j + directions[di][1] >=0 and
                        datas[i + directions[di][0]][j + directions[di][1]] == 'i')
                        dfs(i,j,0,di);
                        //cout<<"Finished"<<endl;
                }
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            if(visiable[i][j])
                cout<<datas[i][j];
            else
                cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}
/**
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
**/
