#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    int n =0;
    cin>>n;
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
　　　　cout<<rand()<<" ";
}