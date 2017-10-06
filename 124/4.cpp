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
    int p;
    double k;
    char a;
    cin>>p>>k;
    int bmi=((double) p)/k/k;
    if(bmi<18){
        cout<<"very thin";
    }else if(bmi < 25){
        cout<<"very good";
    }else if(bmi < 30){
        cout<<"overweight";
    }else if(bmi<35){
        cout<<"fat";
    }else if(bmi < 40){
        cout<<"normal fat";
    }else{
        cout<<"very fat";
    }
    return 0;
}