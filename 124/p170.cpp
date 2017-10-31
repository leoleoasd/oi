#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int data[50]={0};
    data[0]=0;
    data[1]=1;
    data[2]=1;
    for(int i=3;i<=n;++i){
        data[i]=data[i-1]+data[i-2];
    }
    cout<<data[n];
    return 0;
}
