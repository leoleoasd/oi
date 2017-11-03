#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    int x,y;
    int output;
    cin>>x>>y;
    if(x==0){
        cout<<0;
        return 0;
    }
    if(x<=y){
        cout<<y-x;
        return 0;
    }
    return 0;
}
