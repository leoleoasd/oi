#include <iostream>
#include <algorithm>
using namespace std;
#define endl '\n'
#define MAXN 1000020
struct floor{
    long long f = 0;
    long long in_correct_count = 0;
    bool operator>(const floor & that) const {
        return this->in_correct_count > that.in_correct_count;
    }
};

floor floors[MAXN];

void solve(){
    long long m,n,k;
    cin>>m>>n>>k;
    for(long long i = 0; i < m; ++ i){
        floors[i].f = i;
        cin>>floors[i].in_correct_count;
        floors[i].in_correct_count = n - floors[i].in_correct_count;
    }
    sort(floors, floors+m, greater<floor>());
    long long result = 0;
    for(long long i = 0; i < m; ++ i){
        if(i < k){
            result += floors[i].in_correct_count;
        }else{
            result += n - floors[i].in_correct_count;
        }
    }
    cout<<result<<endl;
}
int  main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long long t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}