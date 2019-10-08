#include <iostream>
#include <algorythm>
using namespace std;

int main(){
    int n,m,data[10020] = {0};
    cin>>n>>m;
    for(int i = 0; i < n; ++ i){
        cin>>data[i];
    }
    for(int i = 0; i < m; ++ i){
        next_permutation(data,data+n);
    }
    for(int i = 0; i < n; ++ i){
        cout<<data[i]<<" ";
    }
    cout<<"\n";
    return 0;
}