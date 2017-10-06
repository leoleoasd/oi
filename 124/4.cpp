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
    int p,k,t;
    cin>>p;
    int output=8;
    p-=3;
    if(p<=0) p=0;
    output += 2*p;
    cout<<output;
    return 0;
}