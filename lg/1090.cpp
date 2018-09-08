#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > data;
int n,tmp;
int main(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>tmp;
        data.push(tmp);
    }
    int a,b;
    int output = 0;
    while(!(data.size()==1)){
        a = data.top();
        data.pop();
        b = data.top();
        data.pop();
        output = output + a + b;
        data.push(a+b);
    }
    cout<<output;
    return 0;
}