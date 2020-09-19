#include <iostream>
#include <string>
using namespace std;

int map[1010][1010] = {0};
int n,m,k;

void inline paint(int x, int y){
    // 上
    for(int a = x+1; a < n && a-x <= k; ++ a){
        if(map[a][y] == 2){
            // 加速
            break;
        }
        for(int b = min(min(y+k - (a-x), n-1), y + a-x); b >= max(max(y-k + (a-x), 0), y-a+x); -- b){
            map[a][b] = 1;
        }
    }
    // 下
    for(int a = x-1; a >= 0 && x-a <= k; -- a){
        if(map[a][y] == 2){
            // 加速
            break;
        }
        for(int b = min(min(y+k - (x-a), n-1), y + x-a); b >= max(max(y-k + (x-a), 0), y-x+a); -- b){
            map[a][b] = 1;
        }
    }
    // 左
    for(int a = y-1; a >= 0 && y-a <= k; -- a){
        if(map[x][a] == 2){
            break;
        }
        for(int b = min(min(x+k - (y-a), n-1), x+y-a); b >= max(max(x-k + (y-a), 0), x-y+a); -- b){
            map[b][a] = 1;
        }
    }
    // 右
    for(int a = y+1; a < n && a-y <= k; ++ a){
        if(map[x][a] == 2){
            break;
        }
        for(int b = min(min(x+k - (a-y), n-1), x+a-y); b >= max(max(x-k + (a-y), 0), x+y-a); -- b){
            map[b][a] = 1;
        }
    }
}

int main(){
    cin>>n>>m;

    /**
     * n * m;
     */
    char t;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            cin>>t;
            map[i][j] = t == 'g' ? 2 : 0;
        }
    }
    cin>>k;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            if(map[i][j] == 2){
                paint(i,j);
            }
        }
    }
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < m; ++ j){
            cout<< (map[i][j] ? 'g' : '.');
        }
        cout<<"\n";
    }
}