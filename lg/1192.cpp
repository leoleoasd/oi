#include <iostream>
using namespace std;
int n,k;
int ways(int n){
    if(n < 0) return 0;
    if(n == 1) return 1;
    int ans = 0;
    for(int i = 1; i <= k; ++ i){
        ans += ways(n-i);
        ans %= 100003;
    }
    return ans;
}
int main(){
    cin>>n>>k;
    cout<<ways(n);
    return 0;
}