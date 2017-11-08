#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAXN 100000

int t,n=0,m,y;
int x[MAXN]={0};
int k[MAXN]={0};
int sum;
int dsum;
void solve(){
    double fff;
    fff = (double)m / y;
    for(int i=0;i<n;++i){
        k[i] = x[i] * fff;
        dsum += k[i];
    }
    for(int i=0;dsum != sum;++i){
        ++dsum;
        ++k[i];
    }
    for(int i=0;i<n;++i){
        cout<<k[i]<<" ";
    }
    cout<<endl;
}

void init(){
    for(int i=0;i<n;++i){
        x[i]=0;
        k[i]=0;
    }
    sum=0;
    dsum=0;
}

int main(){
    cin>>t;
    while(t--){
        init();
        cin>>n>>m>>y;
        for(int i=0;i<n;++i){
            cin>>x[i];
        }
        solve();
    }
    return 0;
}
