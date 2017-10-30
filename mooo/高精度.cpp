#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
#define size 100
struct Bint{
    bitset<size> data;
    Bint operator+(Bint a){
        if(data&a.data==0){
            return data xor a.data;
        }
    }
};
int main(){
    return 0;
}
