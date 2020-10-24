#include <iostream>
using namespace std;
#define MAXN 55
#define endl '\n'
int a[MAXN][MAXN];
int k[3][3];
void solve(){
    int n;
    cin>>n;
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            cin>>a[i][j];
        }
    }
    int flag = 0;
    for(int i = 0; i < 3; ++ i){
        for (int j = 0; j < 3; ++ j){
            cin>>k[i][j];
            if (k[i][j] != 0) {
                flag++;
            }
        }
    }
    if (flag == 1) {
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                cout<<a[i][j];
                if(j != n-1){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    } else {
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < n; ++ j){
                cout<<"0";
                if(j != n-1) {
                    cout << " ";
                }
            }
            cout<<endl;
        }
    }
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