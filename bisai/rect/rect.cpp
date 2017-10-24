#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("rect.in");
ofstream fout("rect.out");
const long long jc[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
long long C(int b,int a){
    return (jc[b])/((jc[a])*jc[b-a]);
}

int main(){
    cout<<C(8,2);
    return 0;
}