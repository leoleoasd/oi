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
    int n;
    cin>>n;
    int sum=0;
    sum+=n/5;
    sum+=n/25;
    sum+=n/125;
    sum+=n/625;
    sum+=n/3125;
    sum+=n/15625;
    cout<<sum;
    return 0;
}