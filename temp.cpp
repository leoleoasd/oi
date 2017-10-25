#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a,int b){
        return a<b;
    }
}
int main(){
    priority_queue<int,vector<int>,greater<int> > asd;
    asd.push(1);
    asd.push(2);
    asd.push(3);
    cout<<asd.top();
    return 0;
}
