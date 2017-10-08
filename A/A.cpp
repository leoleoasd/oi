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
int n,m;
int result;
int head,tail;
void baoli(int pos,int last){
    if(pos > n){
        ++result;
        if(head==last){
            --result;
        }
        return;
    }else{
        
        for(int i=1;i<=m;i++){
            if(i==last) continue;
            if(last==0) head=i;
            baoli(pos+1,i);
        }
    }
}
int qpow(int a,int b){
    int ans=a;
    while(b){
        if(b%2==1){
            ans *= a;
            ans %= MOD;
        }
        b*=b;
        b%=MOD;
        a*=a;
        a%=MOD;
    }
    return ans;
}
void solve(){
    
    fin>>n>>m;
    if(n<=5){
        result = 0;
        baoli(1,0);
        fout<<result;
    }else{
        int r=0;
        result = 0;
        result = m*(m-2);
        result %= MOD;
        for(int i=0;i<n-2;i++){
            result *= m-1;
            result %= MOD;
        }
        if(n>=4) r=(m-1)*(m-1);
        for(int i=0;i<=n-1;++i){
            r*=(m-2);
            r%=MOD;
        }
        result += m*r/(m-1);
        result %= MOD;
        fout<<result;
        
    }
    
}

int main(){
    cout<<qpow(3,4);
    ios::sync_with_stdio(false);
        solve();
    return 0;
}