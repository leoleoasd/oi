#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("rect.in");
ofstream fout("rect.out");
const long long jc[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000,2432902008176640000};
long long C(int b,int a){
    if(b==0){
        return 0;
    }
    return (jc[b])/((jc[a])*jc[b-a]);
}
#define MAXN 2000
#define LL long long
LL bian[MAXN][4]={0};
LL type[MAXN]={0};   // 1为竖直  0 水平
#define cout fout
int n;
int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>bian[i][0]>>bian[i][1]>>bian[i][2]>>bian[i][3];
        if(bian[i][0]==bian[i][2]){
            type[i]=1;
            if(bian[i][3]<bian[i][1]){
                swap(bian[i][1],bian[i][3]);
            }
        }else{
            if(bian[i][2] < bian[i][0]){
                swap(bian[i][0],bian[i][2]);
            }
        }
    }
    int output = 0;
    int mi,ma;
    int mim,mam;
    cout<<"---------------------------------"<<endl;
    for(int i=0;i<n;++i){
        cout<<bian[i][0]<<" "<<bian[i][1]<<" "<<bian[i][2]<<" "<<bian[i][3]<<" "<<type[i]<<endl; 
    }
    cout<<"---------------------------------"<<endl;
    for(int i=1;i<=n;++i){
        if(type[i]==1){
            for(int j=i+1;j<n;++j){
                if(type[j]==1){
                    int cnt = 0;
                    mi = min(bian[i][1],bian[j][1]);
                    ma = max(bian[i][3],bian[j][3]);
                    mim = min(bian[i][0],bian[j][0]);
                    mam = max(bian[i][0],bian[j][0]);
                    cout<<"竖着的边 "<<i<<" "<<j<<endl;
                    cout<<"横着的边 ";
                    for(int k=1;k<=n;++k){
                        if(type[k]==0 and (mi <= bian[k][1] and ma >= bian[k][1]) and (bian[k][0]<=mim and bian[k][2] >= mam)){
                            ++cnt;
                            cout<<k<<" ";
                        }
                    }
                    cout<<endl;
                    output += C(cnt,2);
                    cout<<"---------------------------------"<<endl;
                }
            }
        }
    }
    cout<<output;
    return 0;
}