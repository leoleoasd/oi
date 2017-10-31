#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int output = 1;
    for(int i=0;i<b;++i){
        output*=a;
    }
    cout<<output;
    return 0;
}
