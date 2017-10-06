#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("Z.in");
ofstream fout("Z.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
#define LOG(A) cout<<A<<" ";
#else
#define LOG(A)
#endif
int ans=0;
int a,b;
int r;
void dfs(int x,int y,int step){
    if(step > r){
        return;
    }
    if(x==a and y==b and r==step){
        ++ans;
        ans %= 998244353; 
        return;
    }
    dfs(x,y+1,step+1);
    dfs(x,y-1,step+1);
    dfs(x+1,y,step+1);
    dfs(x-1,y,step+1);
    return;
}
int main(){
    int n;
    fin>>n;
    while(n--){
        ans=0;
        fin>>a>>b>>r;
        dfs(0,0,0);
        fout<<ans;
    }
    return 0;
}