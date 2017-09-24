#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct road{
    int from;
    int to;
    int data;
};

struct road data[2020];

int cmp(struct road a,struct road b){
    return a.data<b.data;
}

void read(int &x){
    char p = getchar();
    while(('0'>= p or p >='9') and p != '-'){
        p = getchar();
    }
    int f=1;
    x=0;
    if(p=='-'){
        f=-1;
        p=getchar();
    }
    while('0'<= p and p <= '9'){
        x = x*10+p-'0';
        p=getchar();
    }
    x*=f;
}

int main(){
    int test;
    int a=1132;
    cout<<(a<<3)+(a<<1);
    return 0;
}