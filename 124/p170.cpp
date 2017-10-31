#include <iostream>
using namespace std;
int main(){
    int n,p;
    cin>>n;
    for(int i=2;i<n;++i){
        if(n%i==0){
            cout<<"no";
            return 0;
        }
    }
    cout<<"yes";
    return 0;
}
