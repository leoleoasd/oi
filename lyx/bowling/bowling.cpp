#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAXN 10020
int x[MAXN]={0};
int sum[MAXN]={0};
int f[20000][505]={0};
int n,w,k;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>w>>k;
    for(int i=0;i<n;++i){
        cin>>data[i];
    }

    for (long j=0;j<n+w+1;j++){
        for (long i=0;i<k+1;i++){
            f[i][j] = -926359016;
        }
    }
    for (long i=1;i<n+1;i++){
        cin>>x[i];
        sum[i] = sum[i-1]+(lld)x[i];
    }
    for (long i=n+1;i<n+w+1;i++){
        sum[i] = sum[i-1];
    }
    long long ans = -9147483;
    for (long i=1;i<n+w+1;i++){
        f[1][i] = sum[i]-sum[i-w>?0];
        ans >?= f[1][i];
    }
    for (long i=2;i<k+1;i++){
        for (long j=1;j<n+w+1;j++){
            for (long l=0;l<=j-w-1>?0;l++){
                f[i][j] >?= f[i-1][l]+sum[j]-sum[j-w>?0];
            }
            for (long l=j-1;l>=((j-w)>?0);l--){
                f[i][j] >?= f[i-1][l]+sum[j]-sum[l];
            }
            ans >?= f[i][j];
        }
    }
    cout << ans;
    return 0;
}
