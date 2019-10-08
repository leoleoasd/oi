#include <iostream>
using namespace std;

void print(int n,bool flag = 0){
    if(flag) cout<<"+";
    if(n == 0){
        //cout<<0;
        return;
    }
    if(n == 1){
        cout<<"2(0)";
        return;
    }
    if(n == 2){
        cout<<"2";
        return;
    }
    //cout<<"DEBUG"<<n<<"!";
    for(int i = 16; n; --i){
        if(n >= (1<<i)){
            n -= 1<<i;
            if(i <= 1){
                print(1<<i);
            }else{
                cout<<"2(";
                print(i);
                cout<<")";
            }
            if(n != 0)
                cout<<"+";
        }
    }
}

int main(){
    int n;
    cin>>n;
    print(n);
    return 0;
}