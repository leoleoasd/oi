#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;

string ope;
string orig;

void solve(char ope){
    if(ope=='A'){
        cout<<1;
        string ne;
        for(int i=orig.size()-1,j=0;i>=0;--i,++j){
            ne[j]=orig[i];
            cout<<2;
        }
        orig = ne;
        cout<<ne;
        return;
    }
}


int main(){
    cin>>ope>>orig;
    for(int i=ope.size()-1;i>=0;--i){
        solve(ope[i]);
        cout<<ope[i];
    }
    cout<<orig;
    return 0;
}
