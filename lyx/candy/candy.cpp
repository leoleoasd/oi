#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::sort;
#define MAXN 100000

int t,n=0,m,y;
int x[MAXN]={0};
int sum;
int dsum;
struct p{
    int id;
    int data;
};
bool cmp1(p a,p b){
    return a.data < b.data;
}
bool cmp2(p a,p b){
    return a.id < b.id;
}
struct p k[MAXN];
void solve(){
    double fff;
    fff = (double)m / y;
    for(int i=0;i<n;++i){
        k[i].data = x[i] * fff;
        dsum += k[i].data;
    }
    sort(k,k+n,cmp1);
    for(int i=0;dsum != m and i < n;++i){
        ++dsum;
        ++k[i].data;
    }
    sort(k,k+n,cmp2);
    for(int i=0;i<n;++i){
        cout<<k[i].data<<" ";
    }
    cout<<endl;
}

void init(){
    for(int i=0;i<n;++i){
        x[i]=0;
        k[i].id=i;
        k[i].data=0;
    }
    sum=0;
    dsum=0;
}

int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>y;
        init();
        for(int i=0;i<n;++i){
            cin>>x[i];
        }
        solve();
    }
    return 0;
}
