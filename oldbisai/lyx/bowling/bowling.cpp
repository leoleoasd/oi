#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
ifstream fin("bowling.in");
ofstream fout("bowling.out");
#define cin fin
#define cout fout
#define max(A,B) ((A) > (B) ? (A) : (B))
#define MAXN 10020
int x[MAXN]={0};
int sum[MAXN]={0};
int f[20000][505]={0};
int n,w,k;
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>w>>k;
    for(int  j=0;j<n+w+1;j++){
        for(int  i=0;i<k+1;i++){
            f[i][j] = -926359016;
        }
    }
    for(int  i=1;i<n+1;i++){
        cin>>x[i];
        sum[i] = sum[i-1]+x[i];
    }
    for(int  i=n+1;i<n+w+1;i++){
        sum[i] = sum[i-1];
    }
    long long ans = -926359016;
    for(int  i=1;i<n+w+1;i++){
        if(i-w>0)
            f[1][i] = sum[i]-sum[i-w];
        else
            f[1][i] = sum[i]-sum[0];
        ans =max(ans,f[1][i]);
    }
    for(int  i=2;i<k+1;i++){
        for(int  j=1;j<n+w+1;j++){
            for(int  l=0;l<=max(j-w-1,0);l++){
                f[i][j]=max(f[i][j],f[i-1][l]+sum[j]-sum[(j-w)>0?j-w:0]);
            }
            for(int  l=j-1;l>=max((j-w),0);l--){
                f[i][j]=max(f[i][j],f[i-1][l]+sum[j]-sum[l]);
            }
            ans = max(ans,f[i][j]);
        }
    }
    cout << ans;
    return 0;
}
