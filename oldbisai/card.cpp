#include <iostream>
#include <fstream>
#include <stdint.h>
using namespace std;
#define MAXN 100010

ifstream fin("card.in");
ofstream fout("card.out");
#define cin fin
#define cout fout
#define int long long
int data[MAXN]={0};
int n,k;
void read(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>data[i];
    }
}
int output = 0;
int pro[MAXN] = {0};
void dfs(int pos,int num){
    if(num == k){
        int temp = pro[0];
        for(int i=1;i<k;++i){
            temp = temp xor pro[i];
        }
        output += temp;
        output %= 998244353;
        return;
    }
    int max = n - k + num + 1;
    for(int i=pos;i<=max;++i){
        pro[num]=data[i];
        dfs(i+1,num+1);
    }
}
void solve(){
    dfs(1,0);
}
int32_t main(){
    ios::sync_with_stdio(false);
    read();
    solve();
    cout<<output;
}