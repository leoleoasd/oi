#include <bits/stdc++.h>
using namespace std;
map<char,char> m0,m1;
int main(){
    string miwen,yuanwen;
    cin>>miwen>>yuanwen;
    int size = miwen.size();
    for(int i = 0; i < size; ++i){
        if(m0.count(miwen[i]) != 0 and m0[miwen[i]] != yuanwen[i]){
            cout<<"Failed"<<endl;
            return 0;
        }
        if(m1.count(yuanwen[i]) != 0 and m1[yuanwen[i]] != miwen[i]){
            cout<<"Failed"<<endl;
            return 0;
        }
        m0[miwen[i]] = yuanwen[i];
        m1[yuanwen[i]] = miwen[i];
    }
    yuanwen = "";
    miwen = "";
    cin>>miwen;
    size = miwen.size();
    string output = "";
    if(m0.size() < 26){
        cout<<"Failed"<<endl;
        return 0;
    }
    for(int i = 0; i < size; ++i){
        if(m0.count(miwen[i]) == 0){
            cout<<"Failed"<<endl;
            return 0;
        }
        output += m0[miwen[i]];
    }
    cout<<output<<endl;
    return 0;
}