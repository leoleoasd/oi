#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define MAXN 200000

struct event{
    int type;
    int value;
};
int n;
event e[MAXN];
ifstream fin("dragons.in");
ofstream fout("dragons.out");
#define cin fin
#define cout fout
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    char tmp;
    int tmpp;
    for(int i=0;i<n;++i){
        cin>>tmp>>tmpp;
        if(tmp=='c'){
            e[i].type = 1;
            e[i].value = tmpp;
        }else{
            e[i].type=2;
            e[i].value=tmpp;
        }
    }
    if(n>=20){
        cout<<-1<<endl;
        return 0;
    }
    int num = e[n-1].value;
    int sum = 0;
    int output = 0;
    for(int i=n-1;i>=0;--i){
        if(e[i].type==1){
            ++sum;
            output += e[i].value;
            
        }
        if(sum == num){
            break;
        }
    }
    cout<<output;
    return 0;
}