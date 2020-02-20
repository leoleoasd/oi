#include <iostream>
#include <stack>
#define LL long long 
#define MAXN 100020

using namespace std;

LL n,m;
stack<LL> s;
bool outputed[MAXN] = {false};

int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;

    int t;
    for(register int i = n;i > 0; -- i){
        s.push(i);
        cin>>t;
    }
    for(register int i = 0; i < m; ++ i){
        cin>>t;
        s.push(t);
    }
    while(!s.empty()){
        if(!outputed[s.top()]){
            cout<<s.top();
            //if(s.size()!=1)
                cout<<" ";
            outputed[s.top()] = 1;
        }
        s.pop();
    }
    //cout<<endl;
    return 0;
}