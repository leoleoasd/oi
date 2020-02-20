#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
ifstream fin("b.in");
ofstream fout("b.out");
#define cin fin
#define cout fout
int main(){
    cout<<rand()%10;
    return 0;
}