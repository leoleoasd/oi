#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
#define ULL unsigned long long
int main(){
    ULL x,y;
    ULL output;
    cin>>x>>y;
    if(x<=y){
        output = 0;
        for(ULL i = 1;i<=x;++i){
            output += x % i;
        }
        output += (y-x)*x;
        cout<<output<<endl;;
        return 0;

    output = 0;
    for(ULL i=1;i<=y;++i){
        output += x % i;
    }
    cout<<output;
    return 0;
}
