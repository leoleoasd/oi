#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
#include <fstream>
using std::ifstream;
using std::ofstream;
ifstream fin("sqrt.in");
ofstream fout("sqrt.out");
#define cin fin
#define cout fout
using std::endl;
int main(){
    int n,p,x,y;
    cin>>n;
    for(int i=sqrt(n);i>=0;--i){
        if(n%(i*i)==0){
            x=(n/(i*i))*(i+1)*(i+1);
            break;
        }
    }
    cout<<x<<endl;
    return 0;
}
