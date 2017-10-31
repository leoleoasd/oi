#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int tmp;
    int data[2]={0};
    for(int i=1;i<=n;++i){
        cin>>tmp;
        data[tmp]++;
    }
    if(data[0]==data[1]) cout<<"invalid";
    if(data[0]<data[1]) cout<<"X win";
    if(data[0]>data[1]) cout<<"T win";
    return 0;
}
