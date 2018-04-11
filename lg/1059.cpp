#include <iostream>
using namespace std;
int main(){
    int data[1050] = {0};
    int n,temp,sum=0;
    cin>>n;
    for (size_t i = 0; i < n; i++) {
        cin>>temp;
        sum += !(data[temp]);
        data[temp]=1;
    }
    cout<<sum<<endl;
    for(int i=0;i<1050;++i){
        if(data[i]==1){
            cout<<i<<" ";
        }
    }
    return 0;
}
