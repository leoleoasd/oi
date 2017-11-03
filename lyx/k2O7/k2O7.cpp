#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    int x,y;
    int output;
    cin>>x>>y;
    i//f(x<=y){
        output = 0;
        for(int i = 1;i<=x;++i){
            output += x % i;
        }
        output += (y-x)*x;
        cout<<output<<endl;;
    //    return 0;
    //}
    output = 0;
    for(int i=1;i<=y;++i){
        output += x % i;
    }
    cout<<output;
    return 0;
}
