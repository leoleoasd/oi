#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

//#define fin cin
//#define fout cout
//#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
#define MOD 998244353

long long n,m;
long long result;
long long head,tail;
void baoli(long long pos,long long last){
    if(pos > n){
        ++result;
        if(head==last){
            --result;
        }
        return;
    }else{

        for(long long i=1;i<=m;i++){
            if(i==last) continue;
            if(last==0) head=i;
            baoli(pos+1,i);
        }
    }
}
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b%2==1){
            ans =(ans * a)%MOD;
            ans %= MOD;
        }
        b/=2;
        b%=MOD;
        a=a*a%MOD;
    }
    return ans;
}
void solve(){
    
    fin>>n>>m;
    if(n<=4){
        result = 0;
        baoli(1,0);
        fout<<result;
    }else{
        long long r=0;
        result = 0;
        result = m*(m-2)%MOD;
        result %= MOD;
        /*
        for(long long i=0;i<n-2;i++){
            result *= m-1;
            result %= MOD;
        }
        */
        result *= qpow(m-1,n-2);
        if(n>=4) r=(m-1)*(m-1)%MOD;
        r *= qpow(m-2,n-4)%MOD;
        /*
        for(long long i=0;i<n-4;++i){
            r*=(m-2);
            r%=MOD;
        }*/
        result += m*r/(m-1)%MOD;
        result %= MOD;
        fout<<result;
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
        solve();
    return 0;
}