#include <iostream>
#include <math.h>
using namespace std;
int main(){
    for(int i = 100; i <= 999; ++ i){
        if( i == (i/100)*(i/100)*(i/100) + (i/10 % 10)* (i/10 % 10)* (i/10 % 10) + (i%10)*(i%10)*(i%10) ){
            cout<<i<<endl;
        }
    }
    return 0;
}
