#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int k = 0;
    for(int i = 100; i <= 999; ++ i){
        if(i % 2 == 0){
            cout<<i<<" ";
            ++k;
        }
        if(k == 10){
            cout<<endl;
            k = 0;
        }
    }
    return 0;
}
