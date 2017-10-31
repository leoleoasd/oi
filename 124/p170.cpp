#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    vector<int> data;
    for(int i=1;i<=10;++i){
        cin>>n;
        if(n%2==1) cout<<n<<" ";
        else data.push_back(n);
    }
    cout<<endl;
    for(int i=0;i<data.size();++i){
        cout<<data[i]<<" ";
    }
    return 0;
}
