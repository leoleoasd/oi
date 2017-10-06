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
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,3);
    if(a[0]+a[1]<a[2]){
        cout<<"impossible";
    }else if(a[2]-a[1]>a[0]){
        cout<<"impossible";
    }else if(a[0]==a[1] and a[1]==a[2]){
        cout<<"equilateral triangle";
    }else if(a[0]==a[1] or a[1]==a[2]){
        cout<<"isosceles triangle";
    }else{
        cout<<"normal triangle";
    }
    return 0;
}