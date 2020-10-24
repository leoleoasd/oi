#include <iostream>
using namespace std;
#define endl '\n'
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,cb, cp;
    cin>>n>>cb>>cp;
    int bcount = 0;
    int pcount = 0;
    int a,b;
    for(int i = 0; i < n; ++ i){
        cin>>a>>b;
        bcount += a;
        pcount += b;
    }
    cout<<cb * ((bcount / 10) + (bcount%10 != 0)) + cp * ((pcount / 10) + (pcount%10 != 0))<<endl;
    return 0;
}