#include <iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i){
        k = (k+1)*2;
    }
    cout<<k;
    return 0;
}
