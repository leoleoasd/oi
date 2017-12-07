#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;
int gcd(int a,b){
    if(a<b){
        swal(a,b);
    }
    if(a % b == 0){
        return b;
    }
    return gcd(b,a%b);
}
int main(){
    cout<<gcd(20,15);
    return 0;
}
