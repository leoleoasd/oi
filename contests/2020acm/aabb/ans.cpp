#include <iostream>
#include <algorithm>
using namespace std;

#define MAXD 110
#define MM 1000000007
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
int d = 0;
int n = 0;
int ice_dim1[MAXD] = {0};
int ice_dim2[MAXD] = {0};
int dim1[MAXD] = {0};
int dim2[MAXD] = {0};
int main(){
    ios::sync_with_stdio(false);
    cin>>d;
    for (int i = 0; i < d; ++ i) {
        cin>>ice_dim1[i]>>ice_dim2[i];
    }
    cin>>n;
    long long ans = 0;
    for (int _ = 0; _ < n; ++ _) {
        ans = 1;
        for (int i = 0; i < d; ++ i) {
            cin>>dim1[i]>>dim2[i];
        }
        for (int i = 0; i < d; ++ i) {
            ans *= max(
                min(dim2[i], ice_dim2[i]) - max(dim1[i], ice_dim1[i])
                , 0);
            ans %= MM;
        }
        cout<<ans<<'\n';
    }
    return 0;
}