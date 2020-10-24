#include <iostream>
using namespace std;
int p = 5;
inline int qpow(long long a, int b) {
    int ans = 1;
    a = (a % p + p) % p;
    for (; b; b >>= 1) {
        if (b & 1) ans = (a * ans) % p;
        a = (a * a) % p;
    }
    return ans;
}
int main(){
    cout<<qpow(4,3) <<" "<<qpow(2,3)<<" "<<qpow(6,3);
}