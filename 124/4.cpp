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

#define MM 300
int n,k;
int data[100000]={0};
int main(){
    int a,b;
    cin>>a>>b;
    cout<<(a>b)?a:b;
    return 0;
}