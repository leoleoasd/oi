#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

ifstream fin("rect.in");
ofstream fout("rect.out");

#define cin fin
#define cout fout


int main(){
    srand((unsigned)time(NULL));
    cout<<rand()%100+1;
    return 0;
}