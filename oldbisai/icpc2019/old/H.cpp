#include <iostream>
#define LL long long
using namespace std;
#define MOD 998244353L
#define M(a) (((a)>MOD)?(a) = (a) % MOD : (a) )
struct mat{
    LL data[4];
    inline LL& operator[](const int n){
        return data[n];
    }
};

LL getn(LL n){
    if(n == 0) return 0;
    struct mat m;
    m[0] = 0;
    m[1] = 2;
    m[2] = 1;
    m[3] = 3;
    struct mat r;
    struct mat t;
    r[0] = 1;
    r[1] = 0;
    r[2] = 0;
    r[3] = 1;
    while(n != 0){
        if((n&1)!= 0){
            t[0] = r[0] * m[0] + r[1] * m[2];
            //t[0] %= 998244353L;
            M(t[0]);
            t[1] = r[0] * m[1] + r[1] * m[3];
            M(t[1]);
            t[2] = r[2] * m[0] + r[3] * m[2];
            M(t[2]);
            t[3] = r[2] * m[1] + r[3] * m[3];
            M(t[3]);
            r = t;
        }
        t[0] = m[0] * m[0] + m[1] * m[2];
        M(t[0]);
        t[1] = m[0] * m[1] + m[1] * m[3];
        M(t[1]);
        t[2] = m[2] * m[0] + m[3] * m[2];
        M(t[2]);
        t[3] = m[2] * m[1] + m[3] * m[3];
        M(t[3]);
        m = t;
        n >>= 1;
    }
    return r[2];
}
/*

LL getn(LL n){
    if(n == 0) return 0;
    struct mat a = ksm(n);
    LL r = a[2] % 998244353L;
    return r;
}

/*
0 1
2 3
*/
LL n,q;
int main(){
    //cout<<getn(0)<<" "<<getn(1)<<" "<<getn(2)<<" "<<getn(3)<<" "<<getn(4)<<endl;
    cin>>q>>n;
    LL r = 0;
    while(q--){
        LL t = getn(n);
        r ^= t;
        n = n ^ (t * t);
        //cout<<t<<" "<<n<<endl;
    }
    cout<<r<<endl;
    return 0;
}