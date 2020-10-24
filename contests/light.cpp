#include <iostream>
#include <bitset>
#include <unordered_map>
using namespace std;
#define endl '\n'
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,t;
    cin>>n>>t;
    bitset<1000000> ss;
    unordered_map<bitset<1000000>, int> mm;
    int a;
    for(int i = 0; i < n; ++ i){
        cin>>a;
        ss[a] = 1;
    }
    bitset<1000000> ss1 = ss;
    mm[ss1] = 1;
    //cout<<ss1.to_string()<<endl;
    int count = 0;
    for(int i = 0; i < t - 1; ++ i){
        ss1 <<= 1;
        ss1[0] = ss1[t];
        ss1[t] = 0;
        //cout<<ss1.to_string()<<endl;
        if(mm.find(ss1) == mm.end()){
            mm[ss1] = 1;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
/*
A B B B B B B C C
ADBBBECCC
ADEEEECCC
ADEEEEFCF
ADGHHFFFF
ADGHHHFFF
ADGHHHIII
ADGGGHIII
ADDGGGIII
 */