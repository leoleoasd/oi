#include <iostream>
#include <cmath>
using namespace std;
bool tree[1100000]={false};
int d,l;
int fall(){
    int now = 1;
    while(now>>(d-1)<=1){
        //cout<<now<<endl;
        now = now*2 + tree[now];
        tree[now/2]=!tree[now/2];
    }
    now /= 2;
    return now;
}
int main(){
    cin>>d>>l;
    for(int i=1;i<l;++i){
        fall();
    }
    cout<<fall();
    return 0;
}