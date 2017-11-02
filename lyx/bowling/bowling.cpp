#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define max(A,B) ((A) > (B) ? (A) : (B))
#define MAXN 10020
int x[MAXN]={0};
int sum[MAXN]={0};
int f[20000][505]={0};
int n,w,k;
int main(){
    std::ios::sync_with_stdio(false);
    cin>>n>>w>>k;
    for (long j=0;j<n+w+1;j++){
        for (long i=0;i<k+1;i++){
            f[i][j] = -926359016;
        }
    }
    for (long i=1;i<n+1;i++){
        cin>>x[i];
        sum[i] = sum[i-1]+x[i];
    }
    for (long i=n+1;i<n+w+1;i++){
        sum[i] = sum[i-1];a
    }
    long long ans = -926359016;
    for (long i=1;i<n+w+1;i++){
        if(i-w>0)
            f[1][i] = sum[i]-sum[i-w];
        else
            f[1][i] = sum[i]-sum[0];
        ans =max(ans,f[1][i]);
    }
    for (long i=2;i<k+1;i++){
        for (long j=1;j<n+w+1;j++){
            for (long l=0;l<=j-w-1>?0;l++){
                f[i][j]=max(f[i][j],f[i-1][l]+sum[j]-sum[(j-w)>0?j-w:0]);
            }
            for (long l=j-1;l>=((j-w)>?0);l--){
                f[i][j]=max(f[i][j],f[i-1][l]+sum[j]-sum[l]);
            }
            ans = max(ans,f[i][j]);
        }
    }
    cout << ans;
    return 0;
}
