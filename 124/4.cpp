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
    cin>>a>>b>>c;
    int p;
    p=(b*b-2*a*c);
    if(a==0){
        cout<<"one answer";
    }else if(p>0){
        cout<<"two answers";
    }else if(p==0){
        cout<<"two equal answers";
    }else{
        cout<<"no answer";
    }
    return 0;
}