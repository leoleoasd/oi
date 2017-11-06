#include <iostream>
#include <bitset>
#include <cstdio>
using namespace std;
#define size 10
struct Bint{
    bitset<size> data;
    Bint(bitset<size> a){
        data = a;
    }
    Bint(){}
    Bint(int a){data = bitset<size>(a);}
    Bint(unsigned long long a){data = bitset<size>(a);}
    Bint operator+(Bint a){
        if(!(data & a.data).any()){
             return Bint(data xor a.data);
        }
        return Bint((data & a.data)<<1)+Bint(data xor a.data);
    }
};
int main(){
    Bint a(1234567890);
    Bint b(300);
    cout<<((a+b).data).to_ulong()<<endl;
    //cout<<(a+b).data.to_string()<<endl;
    return 0;
}
