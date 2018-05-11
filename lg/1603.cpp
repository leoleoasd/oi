#include <bits/stdc++.h>
using namespace std;

vector<int> data;

void add(string &x){
    if(x == "one")data.push_back(1);
    else if(x == "two")data.push_back(4);
    else if(x == "three")data.push_back(9);
    else if(x == "four")data.push_back(16);
    else if(x == "five")data.push_back(25);
    else if(x == "six")data.push_back(36);
    else if(x == "seven")data.push_back(49);
    else if(x == "eight")data.push_back(64);
    else if(x == "nine")data.push_back(81);
    else if(x == "ten")data.push_back(0);
    else if(x == "eleven")data.push_back(21);
    else if(x == "twelve")data.push_back(44);
    else if(x == "thirteen")data.push_back(69);
    else if(x == "fourteen")data.push_back(96);
    else if(x == "fifteen")data.push_back(25);
    else if(x == "sixteen")data.push_back(56);
    else if(x == "seventeen")data.push_back(89);
    else if(x == "eighteen")data.push_back(24);
    else if(x == "nineteen")data.push_back(61);
    else if(x == "twenty")data.push_back(0);
    else if(x == "a")data.push_back(1);
    else if(x == "both")data.push_back(4);
    else if(x == "another")data.push_back(9);
    else if(x == "first")data.push_back(1);
    else if(x == "second")data.push_back(4);
    else if(x == "third")data.push_back(9);
}
int main(){
    string tmp;
    for(int i=0;i<6;++i){
        cin>>tmp;
        add(tmp);
    }
    sort(data.begin(),data.end());
    cout<<data[0];
    for(auto t=data.begin();t==data.end();++t){
        if(*t<10){
            cout<<"0";
        }
        cout<<t;
    }
    return 0;
}