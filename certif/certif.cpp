#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
#define MAXN 100
using namespace std;

ifstream fin("certif.in");
ofstream fout("certif.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
#define LL long long
int n,m;
bool data[1004][1004]={0};
int status[1004]={0};
map<int,map<int,int> > num;
int dfs(int from,int to,int z){
    if(from == to){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(status[i]==0 and data[from][i]){
            dfs(i,to,z);
            num[i][z]|++;
        }
    }
}
int read(){
    fin>>n>>m;
    int asd,sdf,dfg;
    for(int i=0;i<n-1;i++){
        cin>>asd>>sdf;
        data[asd][sdf]=1;
        data[sdf][asd]=1;
    }
}
int solve(){
    int asd,sdf,dfg;
    for(int asdddd=0;asdddd<m;asdddd++){
        cin>>asd>>sdf>>dfg;
        dfs(asd,sdf,dfg);
    }
}
int main(){
    ios::sync_with_stdio(false);
    read();
    solve();
}