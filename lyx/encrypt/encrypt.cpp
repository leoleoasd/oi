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
        char ne[30]={'\0'};
        for(int i=orig.size()-1,j=0;i>=0;--i,++j){
            ne[j]=orig[i];
        }
        orig = ne;
        return;
    }
    if(ope=='C'){
        char ne[30]={'\0'};
        for(int i=1;i<orig.size();++i){
            ne[i-1]=orig[i];
        }
        ne[orig.size()-1]=orig[0];
        orig=ne;
        return;
    }
}


int main(){
    cin>>ope>>orig;
    for(int i=ope.size()-1;i>=0;--i){
        solve(ope[i]);
    }
    cout<<orig;
    return 0;
}
