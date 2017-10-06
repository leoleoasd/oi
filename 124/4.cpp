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
    int a,b,c;
    cin>>a;
    if(a>=0){
        if(a%2==0){
            cout<<a*a;
        }else{
            cout<<a-10;
        }
    }else{
        if(a%2==0){
            cout<<1-a*a*a;
        }else{
            cout<<10-a;
        }
    }
    return 0;
}