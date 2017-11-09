#include <iostream>
using namespace std;
bool flag(int x1,int y1,int x2,int y2,int x3,int y3){
    if(x1 == x2 and x2==x3){
        return true;
    }
    return ((double)(x2-x1)/(y2-y1))==((double)(x3-x2)/(y3-y2))
}
int main(){
    ios::sync_with_stdio(false);
    cout<<flag(0,0,1,1,2,2);
    cout<<flag(0,0,1,2,2,2);
    return 0;
}
