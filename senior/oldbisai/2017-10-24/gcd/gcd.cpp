#include <cstdio>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

ifstream fin("gcd.in");
ofstream fout("gcd.out");
int main(){
    int n =0;
    fin>>n;
    srand((unsigned)time(NULL));
    for(int i=0;i<n;i++)
        fout<<rand()<<" ";
}