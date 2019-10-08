#include <iostream>
#define LL long long
using namespace std;

int dat[11][1000020] = {0};

int pos[11] = {0,0,0,0,0,0,0,0,0,0,0};

inline int get(int i, int b){
    int ans = 0;
    while(i){
        ans += i % b;
        i /= b;
    }
    return ans;
}

inline int solve(int n,int b){
    if(pos[b] > n) return dat[b][n];
    int ans = dat[b][pos[b]];
    for(int i = pos[b]+1; i <= n; ++ i){
        ans += get(i,b);
        dat[b][i] = ans;
    }
    pos[b] = n;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int n,b;
    cin>>t;
    for(int i = 1; i <= t; ++ i){
        cin>>n>>b;
        cout<<"Case #"<<i<<": "<<solve(n,b)<<"\n";
    }
    return 0;
}