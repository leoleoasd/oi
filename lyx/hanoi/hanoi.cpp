#include <iostream>
#include <stack>
using namespace std;
stack<int> s[3];
stack<int> k_source;
stack<int> k_target;
stack<int> k_spare;
int n,k;
int nowstep=0;
int tmp;
void hanoi_n(int source,int spare,int target,int n){
    if(n>0 and nowstep <k){
        hanoi_n(source,spare,target,n-1);
        if(nowstep > k) return;
        tmp = s[source].top();
        s[source].pop();
        s[target].push(tmp);
        ++nowstep;
        cout<<"Moving"<<tmp<<"From"<<source<<"To"<<target<<""endl;
        if(nowstep > k) return;
        hanoi_n(spare,target,source,n-1);
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        s[0].push(i);
    }
    hanoi_n(0,1,2,n);
    while(!s[0].empty()){
        cout<<s[0].top()<<" ";
        s[0].pop();
    }
    cout<<endl;
    while(!s[1].empty()){
        cout<<s[1].top()<<" ";
        s[1].pop();
    }
    cout<<endl;
    while(!s[2].empty()){
        cout<<s[2].top()<<" ";
        s[2].pop();
    }
    cout<<endl;
    return 0;
}
