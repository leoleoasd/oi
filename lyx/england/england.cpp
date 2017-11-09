#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n;
    int data[100020]={0};
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }
    int output = -1;
    int f;
    int lo;
    int l = 0;
    for(int i=51;i>=0;--i){
        lo = 0;
        f = 1;
        l = 0;
        for(int j=0;j<n;++j){
            if(data[j]>i){
                if(f==1){
                    ++lo;
                }else{
                    f=1;
                    lo=1;
                }
            }else{
                f=0;
                l = max(lo,l);
            }
        }
        output = max(output,l * i);
    }
    cout<<output;
    return 0;
}
