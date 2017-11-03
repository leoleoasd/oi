#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    int x,y;
    int output;
    cin>>x>>y;
    if(x==0){
        cout<<0;
        return 0;
    }
    if(x<=y){
        output = 0;
        for(int i = 1;i<=x;++i){
            output += x % i;
        }
        output += (y-x)*x;
        cout<<output;
        return 0;
    }
    return 0;
}
