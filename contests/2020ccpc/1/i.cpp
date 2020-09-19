#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 100050
#define MOD 1000000007
#define endl '\n'
long long edges_start[MAXN] = {0};
long long edges_end[MAXN] = {0};
long long edges_length[MAXN] = {0};
// 第i条边的某个方向的子树大小
long long left_size[MAXN] = {0};
int visited[MAXN] = {0};
vector<pair<int,int> > to[MAXN];
int dfs(int now) {
    if (visited[now]) return 0;
    visited[now] = 1;
    int ans = 1;
    int t = 0;
    for (auto &&tt : to[now]) {
        t = dfs(tt.first);
        ans += t;
        left_size[tt.second] = t;
    }
    return ans;
}
void solve(int n) {
    for(int i = 0; i <= n; ++ i){
    }
    memset(visited,0,(n+1) * sizeof(int));
    for(int i = 0; i < n-1; ++ i){
        cin>>edges_start[i]>>edges_end[i]>>edges_length[i];
        to[edges_start[i]].emplace_back(edges_end[i], i);
        to[edges_end[i]].emplace_back(edges_start[i], i);
    }
    dfs(1);
    long long ans = 0;
    long long pow = 1;
    for(int i = 1; i <= n-1; ++ i){
        pow = pow * i % MOD;
    }
    for(int i = 0; i < n - 1; ++ i){
        ans += ((2 * left_size[i] * (n-left_size[i]) % MOD) * edges_length[i] % MOD) * pow % MOD;
        ans %= MOD;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n) {
        solve(n);
    }
}