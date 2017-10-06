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
    if(p%4!=0){
        cout<<"normal year";
    }else if(p%100!=0){
        if(p%400!=0)
            cout<<"normal year";
        else
            cout<<"leap year";
    }else{
        cout<<"leap year";
    }
    return 0;
}