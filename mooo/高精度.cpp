#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
#define size 100
struct Bint{
    bitset<size> data;
    Bint(bitset<size> a){
        data = a;
    }
    Bint operator+(Bint a){
        if(data and a.data){

             return Bint(data xor a.data);
        }
    }
};
int main(){
    return 0;
}
