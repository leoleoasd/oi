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
        cout<<"正在把"<<data.to_string()<<endl;
        cout<<"    和"<<a.data.to_string()<<endl;
        cout<<"相加";
        if(!(data & a.data).any()){
             return Bint(data xor a.data);
        }
        return Bint((data & a.data)<<1)+Bint(data xor a.data);
    }
};
int main(){
    Bint a(2);
    Bint b(3);
    cout<<(a+b).data.to_string()<<endl;
    //cout<<(a+b).data.to_string()<<endl;
    return 0;
}
