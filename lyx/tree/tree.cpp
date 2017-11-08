#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::max;
int main(){
    int t,u,v,w,sum,m;
    int n;
    cin>>t;
    while(--t){
        cin>>n;
        m = -1;
        sum = 0;
        for(int i=0;i<n-1;++i){
            cin>>u>>v>>w;
            m = max(w,m);
            sum += w;
        }
        cout<<(sum+(n*(n-1)/2 - (n-1) )*n  )<<endl;;
    }
    return 0;
}
