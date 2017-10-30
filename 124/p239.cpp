#include <iostream>
#include <cstdio>
using namespace std;

char tmp;
#define MAXN 10000
int data[MAXN]={0};

int main(){
    int i = 0;
    while(cin>>tmp){
        if(tmp!='#')
            data[i]=1;
        ++i;
    }
    for(int j=0;j<i;++j){
        if(data[j]!=0){
            if(data[j*2+1]==data[j*2+2]){

            }else{
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
