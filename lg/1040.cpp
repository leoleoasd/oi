#include <bits/stdc++.h>
using namespace std;

#define MAXN 35
#define LL long long

LL f[MAXN][MAXN] = {0};

int root[MAXN][MAXN] = {0};

int n = 0;

int scores[MAXN] = {0};

LL dfs(int left,int right){
    LL tmp;
    if(left > right){
        return 1;
    }
    if(f[left][right] == -1){
        for(int i = left; i <= right; ++i){
            tmp = dfs(left,i-1) * dfs(i+1,right) + f[i][i];
            if(tmp > f[left][right]){
                f[left][right] = tmp;
                root[left][right] = i;
            }
        }
    }
    return f[left][right];
}

bool flag = false;

void print(int left,int right){
    if (left > right){
        return;
    }
    cout<<root[left][right]<<" ";
    print(left,root[left][right]-1);
    print(root[left][right]+1,right);
}

int main(){
    for(int i=0;i<MAXN;++i){
        for(int j=0;j<MAXN;++j)
            f[i][j] = -1;
        root[i][i] = i;
    }
    cin>>n;
    for(int i = 1; i <= n; ++ i){
        cin>>f[i][i];
    }
    dfs(1,n);
    cout<<f[1][n]<<endl;
    print(1,n);
    return 0;
}