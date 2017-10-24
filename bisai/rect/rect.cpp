#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("rect.in");
ofstream fout("rect.out");

//#define cin fin
//#define cout fout
long long ASD(int n){
    long long a = 1;
    for(int i=1;i<=n;++i){
        a *= i;
    }
    return a;
}
int main(){
    for(int i=0;i<=10;++i){
        cout<<ASD(i)<<",";
    }
    return 0;
}