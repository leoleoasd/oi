#include <cstdio>
#include <iostream>
#define ULL unsigned long long
#define LL long long
using namespace std;
ULL k1, k2;
ULL gen1(){
    ULL k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17 ) ^ (k4 >> 26);
    return k2+k4;
}
int n,m;
/*
u[100001],v[100001];
ULL w[100001];
*/
struct Edge{
    int u,v;
    ULL w;
}edge[maxm];
void gen(){
    scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
    for(int i = 1; i <= m; ++ i){
        u[i] = gen1() % n + 1;
        v[i] = gen1() % n + 1;
        w[i] = gen1();
    }
}
const int maxn=100100;
const int maxm=100100;
int f[maxn+10],tol;
void add(int u,int v,ull w)
{

    edge[tol].u=u;
    edge[tol].v=v;

}
int main(){
    gen();
}