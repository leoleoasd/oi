#include <iostream>
#include <stack>
using namespace std;
stack<int> source;
stack<int> target;
stack<int> spare;
stack<int> k_source;
stack<int> k_target;
stack<int> k_spare;
int main(){
    source.push(1);
    source.push(2);
    cout<<(source==target);
    target.push(1);
    source.pop();
    cout<<(source==target);
    return 0;
}
