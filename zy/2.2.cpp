#include <iostream>
#include <math.h>
using namespace std;
int gcd(int a,int b){
    if(b > a){
        return gcd(b,a);
    }
    int c = a % b;

    while(c){
        b = a;
        a = c;
        c = a % b;
    }
    return b;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
    return 0;
}
