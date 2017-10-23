#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

string password;
string encoded;
ifstream fin("substring.in");
ofstream fout("substring.out");

#define cin fin
#define cout fout
void read(){
    cin>>encoded>>password;
}
void solve(){
    int i=0,j=0;
    int head,tail;
    for(;i<password.size();++j){
        if(encoded[j]==password[i]){
            if(i==0){
                head = j;
            }
            ++i;
        }
    }
    tail = j-1;
    ++head;
    tail = encoded.size()-tail;
    cout<<head*tail;
}
int main(){
    ios::sync_with_stdio(false);
    read();
    solve();
    return 0;
}