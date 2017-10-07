#include<iostream>
using namespace std;
int gcd(int m,int n)//求最大公约数 
{
    int r,t;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
int main(){
    
}