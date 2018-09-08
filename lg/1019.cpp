#include <bits/stdc++.h>
using namespace std;
string data[25];
string old,now;
char begin_at;
int status[25] = {0};
int n = 0;
int maxn = 0;
int olds,news;
void dfs(int pos,int iv){
    if(status[pos] >= 2){
        return;
    }
    status[pos] += 1;
    old = now;
    olds = now.size();
    //now += data[pos];
    now = now.substr(0,iv) + data[pos];
    news = now.size();
    maxn = (maxn > news) ? maxn : news;
    cout<<now<<endl;
    for(int i = olds; i < news; ++i){
        for(int j = 0; j < n; ++ j){
            if(data[j][0] == now[i]){
                dfs(j,i);
            }
        }
    }
    status[pos] -= 1;
    now = old;
}
int main(){
    cin>>n;
    for(int i = 0; i < n; ++ i){
        cin>>data[i];
    }
    cin>>begin_at;
    for(int i = 0; i < n; ++ i){
        if(data[i][0] == begin_at){
            dfs(i,0);
        }
    }
    cout<<maxn;
    return 0;
}