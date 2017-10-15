#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
#define MAXN 100
using namespace std;

ifstream fin("calendar.in");
ofstream fout("calendar.out");

//#define fin cin
//#define fout cout
//#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
long long a,b,c,d,t;
int solve();
int main(){
    ios::sync_with_stdio(false);
    fin>>a>>b>>c>>t;
    solve();
}
int get(long long y, long long m, long long d){
    if (m == 1 || m == 2) {  
        m += 12;  
        y--;  
    }  
    return (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
}
int pf(){
    long long sum = t / 365.2422;
    long long out = 0;
    long long asd = get(a,b,c);
    while(--sum){
        if(get(++a,b,c)==asd)++out;
    }
    fout<<out;
}
int solve(){
    if(t <= 10000000){
        pf();
        return 0;
    }
    long long year = a;
    double sum;
    sum = t / 365;
    fout<<(int)(((sum+a)*4/28)-(sum+a)/400+a/400-a/7);
}