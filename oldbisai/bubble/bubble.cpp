#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 2000000
ifstream fin("bubble.in");
ofstream fout("bubble.out");
#define cin fin
#define cout fout
int n;
int data[MAXN];
int f[MAXN],lefta[MAXN]={0},righta[MAXN]={0},v[MAXN]={0};
void read(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>data[i];
    }
}
int find(int l,int r,int x)
{
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (x>f[mid]) l=mid+1;
            else r=mid-1;
    }
    return l;
}

void solve(){
    int output=0;
    for (int i=1;i<=n;++i)
    {
        int j=find(1,output,data[i]);
        f[j]=data[i];
        if (j>output) output=j;
        lefta[i]=j;
    }
    int an=0;
    for (int i=n;i>=1;i--)
    {
        int j=find(1,an,-data[i]);
        f[j]=-data[i];
        if (j>an) an=j;
        righta[i]=j;
    }
    cout<<output<<endl;
    for (int i=1;i<=n;++i)
        if (lefta[i]+righta[i]==output+1) v[lefta[i]]++;
    for (int i=1;i<=n;++i)
        if (v[lefta[i]]==1 and lefta[i]+righta[i]==output+1) cout<<i<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    read();
    solve();
    return 0;
}