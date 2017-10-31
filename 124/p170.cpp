#include <iostream>
using namespace std;
int main(){
    double n,p;
    cin>>n>>p;
    int i=1;
    for(;n<p;++i){
        n*=1.005;
    }
    cout<<i;
    return 0;
}
