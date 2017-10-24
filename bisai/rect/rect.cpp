#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main(){
    srand((unsigned)time(NULL));
    cout<<rand()%100+1;
    return 0;
}