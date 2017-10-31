#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;++i){
        if(n%i==0){
            bool flag = false;
            for(int j=2;j<i;++j){
                if(i%j==0) flag = true;
            }
            if(i==2) flag = false;
            flag ? (0) : (cout<<i<<" ");
        }
    }
    return 0;
}
