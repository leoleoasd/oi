#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v[0]=123;
    v[1]=234;
    cout<<v.operator[](0);
    return 0;
}