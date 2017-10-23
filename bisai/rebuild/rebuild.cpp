#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 1500
int data[MAXN][MAXN]={0};
int n,m;
struct e{
    int from;
    int to;
};
e edge[MAXN];
vector<int> outputs;
void floyd(){
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(data[i][j]==1 and data[j][k]==1)
                    data[i][k]=1;
}
int main(){
    cin>>n>>m;
    int x,y;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        edge[i].from = x;
        edge[i].to = y;
    }
    int max = -1;
    for(int i=0;i<m;++i){
        memset(data,0,MAXN*MAXN);
        for(int j=0;j<m;++j){
            data[edge[j].from][edge[j].to]=1;
        }
        data[edge[i].to][edge[i].from]=1;
        floyd();
        int ans = 0;
        for(int k=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(data[k][j]==1 and data[j][k]==1){
                    ++ans;
                }
            }
        }
        if(ans >max){
            max = ans;
            outputs.clear();
            outputs.push_back(i);
        }
    }
    cout<<max<<endl;
    cout<<outputs.size()<<endl;
    for(int i=0;i<outputs.size();++i){
        cout<<outputs[i]<<" ";
    }
    return 0;
}