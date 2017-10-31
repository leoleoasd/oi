#include <iostream>
using namespace std;
int main(){
    int maxa = -1;
    int tmp;
    for(int i=0;i<10;++i){
        cin>>tmp;
        if(maxa < tmp)maxa = tmp;
    }
    cout<<maxa;
    return 0;
}
