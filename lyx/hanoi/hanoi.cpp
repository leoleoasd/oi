#include <iostream>
#include <stack>
using namespace std;
stack<int> source;
stack<int> target;
stack<int> spare;
stack<int> k_source;
stack<int> k_target;
stack<int> k_spare;
int n,k;
int nowstep=0;
int tmp;
void hanoi_n(stack<int>& source,stack<int>& target,stack<int>& spare,int n){
    if(n>0 and nowstep <k){
        hanoi_n(source,spare,target,n-1);
        if(nowstep >= k) return;
        tmp = source.top();
        source.pop();
        target.push(tmp);
        ++nowstep;
        cout<<"Moving"<<tmp<<endl;
        if(nowstep >= k) return;
        hanoi_n(spare,target,source,n-1);
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        source.push(i);
    }
    hanoi_n(source,target,spare,n);
    while(!source.empty()){
        cout<<source.top()<<" ";
        source.pop();
    }
    cout<<endl;
    while(!spare.empty()){
        cout<<spare.top()<<" ";
        spare.pop();
    }
    cout<<endl;
    while(!target.empty()){
        cout<<target.top()<<" ";
        target.pop();
    }
    cout<<endl;
    return 0;
}
