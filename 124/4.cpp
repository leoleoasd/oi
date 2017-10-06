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
    int p,k,t;
    cin>>p;
    if(p>=90){
        cout<<"A";
    }else if(p>=80){
        cout<<"B";
    }else if(p>=60){
        cout<<"C";
    }else{
        cout<<"D";
    }
    return 0;
}