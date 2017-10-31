#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int data[50]={0};
    data[1]=1;
    data[2]=1
    data[3]=1;
    data[4]=1;
    data[5]=2;
    data[6]=2;
    data[7]=2;
    data[8]=2;
    data[9]=2;
    data[10]=4;
    for(int i=11;i<=n;++i){
        data[i]=data[i-1]+data[i-5]+data[i-10];

    }
    cout<<data[n];
    return 0;
}
