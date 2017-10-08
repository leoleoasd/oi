#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

#define fin cin
#define fout cout
#define debug 1

#ifdef debug
    #define LOG(A) cout<<A<<" ";
#else
    #define LOG(A)
#endif
int n,m;
int result;
int head,tail;
void baoli(int pos,int last){
    if(pos > n){
        ++result;
        if(head==last){
            --result;
        }
        return;
    }else{
        
        for(int i=1;i<=m;i++){
            if(i==last) continue;
            if(last==0) head=i;
            baoli(pos+1,i);
        }
    }
}
void solve(){
    
    fin>>n>>m;
    if(n<=5){
        result = 0;
        baoli(1,0);
        cout<<result;
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    
    fin>>n;
    while(n--){
        solve();
    }
    return 0;
}