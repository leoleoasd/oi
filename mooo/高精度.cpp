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
    Bint(unsigned long long a){data = bitset<size>(a);}
    Bint operator+(Bint a){
        if((data & a.data).any()){
             return Bint(data xor a.data);
        }
        return Bint((data & a.data)<<1)+Bint(data xor a.data);
    }
};
int main(){
    Bint a(2);
    Bint b(3);
    //cout<<(a).data.to_string()<<endl;
    //cout<<(b).data.to_string()<<endl;
    Bint c(((a.data & b.data)<<1));
    Bint d(a.data xor b.data);
    cout<<c.data.to_string()<<endl;
    cout<<d.data.to_string()<<endl;
    cout<<d.data[1]<<endl;
    cout<<c.data[1]<<endl;
    cout<<()(d.data ^ c.data).to_string()<<endl;
    cout<<((c.data xor b.data)).to_string()<<endl;
    //cout<<(a+b).data.to_string()<<endl;
    return 0;
}
