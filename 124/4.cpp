#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

//ifstream fin("H.in");
//ofstream fout("H.out");

#define fin cin
#define fout cout
//#define debug 1

#ifdef debug
#define LOG(A) cout<<A<<" ";
#else
#define LOG(A)
#endif

int n,k;
int data[100000]={0};
int main(){
    int a;
    cin>>a;
    double b=0;
    for(int i=1;i<=a;++i) b+=((double)1/i);
    cout<<setprecision(2)<<fixed<<b;
    return 0;
}