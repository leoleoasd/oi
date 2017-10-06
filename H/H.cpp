#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("H.in");
ofstream fout("H.out");

//#define fin cin
//#define fout cout
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
    fin>>n>>k;
    for(register int i=0;i<n;++i){
        fin>>data[i];
    }
    sort(data,data+n);
    int sum=0; 
    for(register int i=n-1;i>=k-1;i-=2){
        sum+=data[i]+data[i-1];
    }
    fout<<sum;
    return 0;
}