#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>b;
    int output =0;
    for(int i=1;i<=b;++i){
        output += i*i;
    }
    cout<<output;
    return 0;
}
