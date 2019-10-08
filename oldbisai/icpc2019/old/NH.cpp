#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unordered_map>
#define ll long long
#define MOD 998244353
using namespace std;

struct mat
{
    ll a[2][2];
};
unordered_map<long long,mat> mm;
mat c;
inline mat mat_mul(const mat & x,const mat & y)
{
    mat res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j]);
    res.a[0][0] %= 998244353;
    res.a[0][1] %= 998244353;
    res.a[1][0] %= 998244353;
    res.a[1][1] %= 998244353;
    return res;
}
inline mat mat_pow(ll n)
{
	if(n==1)return c;
	if(mm.count(n)==1)return mm[n];
    mat res = mat_pow(n>>1);
	res=mat_mul(res,res);
	if(n&1) res=mat_mul(res,c);
    return mm[n]=res;
}
inline ll getn(ll n){
	if(n == 0) return 0;
	return mat_pow(n).a[1][0];
}

void Read(ll & p)

{

p=0;

int flag=1;

char c=getchar();

while(c<'0' or c>'9')

{

if(c=='-') flag=-1;

c=getchar();

}

while(c>='0' and c<='9')

p=p*10+(c-'0'),c=getchar();

p*=flag;

}

 

int main(){
	c.a[0][0]=0;
	c.a[0][1]=2;
	c.a[1][0]=1;
    c.a[1][1]=3;
	mm[1]=c;
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	ll n,q;
	//cin>>q>>n;
    Read(q);
    Read(n);
	ll r = 0;
	while(q--){
		ll t = getn(n);
		r ^= t;
		n = n ^ (t * t);
	}
    printf("%lld",r);
	//cout<<r<<endl;
	return 0;
}