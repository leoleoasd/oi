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
        if(nowstep >= k) return;
        hanoi_n(spare,target,source,n-1);
    }
}
bool f = false;
void hanoi_k(stack<int>& k_source,stack<int>& k_target,stack<int>& k_spare,int n){
    if(f) return;
    if(n>0){
        hanoi_k(k_source,k_target,k_spare,n-1);
        if(f) return;
        tmp = k_source.top();
        k_source.pop();
        k_spare.push(tmp);
        ++nowstep;
        if(k_source == source and k_target == target and k_spare == spare){
            cout<<nowstep;
            f = true;
            return;
        }
        hanoi_k(k_target,k_source,k_spare,n-1);
        if(f) return;
        tmp = k_spare.top();
        k_spare.pop();
        k_target.push(tmp);
        ++nowstep;
        if(k_source == source and k_target == target and k_spare == spare){
            cout<<nowstep;
            f = true;
            return;
        }
        hanoi_k(k_source,k_target,k_spare,n-1);
    }
}
int main(){
    cin>>n>>k;
    for(int i=n;i>=1;--i){
        source.push(i);
        k_source.push(i);
    }
    hanoi_n(source,target,spare,n);
    nowstep = 0;
    hanoi_k(k_source,k_target,k_spare,n);
    return 0;
}
