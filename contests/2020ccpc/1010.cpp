#include <iostream>
using namespace std;
void solve(){
    int n;
    int flag = 0;
    int data[2] = {0};
    cin>>n;
    for(int i = 0; i < n; ++ i){
        cin>>data[i%2];
        if (i > 0) {
            if (data[1] == data[0]) {
                flag = 1;
            }
        }
    }
    cout<<(flag ? "NO\n" : "YES\n");
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}