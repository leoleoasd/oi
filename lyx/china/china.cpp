#include <iostream>
#include <algorithm>
#include <stdint.h>
using namespace std;
#define int int64_t
int32_t main(){
    int s,n;
    cin>>s>>n;
    int now = 0;
    int a,b,c;
    int output = 0;
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        output += (b-a+1)*c;
        now += (b-a+1);
    }
    output += s-now;
    cout<<output;
    return 0;
}
