#include <iostream>
#include <cstdlib>

using namespace std;
#define MAXN 27
int data[MAXN][MAXN]={0};
int n;
int ru[MAXN]={0};
int sss[MAXN][4];

int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>sss[i][0]>>sss[i][1]>>sss[i][2]>>sss[i][3];
    }
    int x,y;
    for(int i=1;i<=n;++i){
        cin>>x>>y;
        for(int j=1;j<=n;++j){
            if(sss[j][0] < x and x < sss[j][1] and sss[j][2] < y and y < sss[j][3]){
                data[j][i]=1;
                ru[i]++;
            }
        }
    }
    int ans[MAXN]={0};
    int sum = 1;
    int min,minx;
    /*
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){ 
            cout<<data[i][j]<<" ";
        } 
        cout<<endl;
    }
    for(int i=1;i<=n;++i){
        cout<<ru[i]<<" ";
    }
    */
    while(sum <= n){
        min = 0x7ffffff;
        minx = -1;
        for(int i=1;i<=n;++i){
            if(ru[i]<min and ans[i]==0){
                min = ru[i];
                minx = i;
            }
        }
        if(min!=1){
            cout<<"None"<<endl;
            return 0;
        }
        int d = 0;
        for(int i=1;i<=n;++i){
            if(data[i][minx]!=0){
                d=i;
            }
        }
        ans[minx]=d;
        ++sum;
        for(int i=1;i<=n;++i){
            if(data[d][i]!=0){
                data[d][i]=0;
                ru[i]--;
            }
        }
    }
    
        for(int i=1;i<=n;++i){
        int j=1;
        for(;j<=n;++j){
            if(ans[j]==i){
                break;
            }
        }
        cout<<(char)(i+'A'-1)<<" "<<j<<endl;
    }
    return 0;
}