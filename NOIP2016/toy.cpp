#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

//ifstream fin("a.in");
//ofstream fout("a.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
struct toy{
    struct toy* prev;
    struct toy* next;
    int cx;
    string name;
    void read(){
        fin>>this->cx>>this->name;
        if(this->cx==0){
            this->cx=-1;
        }
    }
};
struct toy * data;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    fin>>n>>m;
    data = new struct toy[n+3];
    
    return 0;
}