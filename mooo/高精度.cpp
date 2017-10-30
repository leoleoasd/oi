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
    Bint(){}
    Bint(int a){data = bitset<size>(a);}
    Bint(unsigned long long a)(data = bitset<size>(a);)
    Bint operator+(Bint a){
        if((data & a.data).any()){

             return Bint(data xor a.data);
        }
        return Bint();
    }
};
int main(){
    return 0;
}
